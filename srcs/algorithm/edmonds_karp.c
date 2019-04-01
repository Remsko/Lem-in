/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 11:12:30 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/01 19:08:42 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <float.h>
#include "path.h"
#include "algorithm.h"
#include "graph.h"
#include "types.h"
#include "array_42.h"
#include "memory_42.h"

void graph_augment_flow(t_graph *graph, t_karp *karp)
{
    size_t v;
    size_t u;

    v = karp->sink;
    while (v != karp->source)
    {
        u = karp->parent[v];
        graph->edge[v][u].flow -= 1;
        graph->edge[u][v].flow += 1;
        v = karp->parent[v];
    }
}

double rentability_calcul(t_run *run, size_t ants)
{
    size_t index;
    size_t total;

    index = 0;
    total = 0;
    while (index < run->length)
    {
        total += run->paths[index]->length;
        ++index;
    }
    return ((double)(total + ants) / (double)run->length);
}

bool condidition_capacity(t_edge *edge)
{
    return (edge->capacity > edge->flow);
}

void run_saver(t_env *e, t_karp *karp, double *rentability)
{
    t_run *run;
    t_graph *copy;
    t_karp *karp_tmp;
    double tmp;

    karp_tmp = new_karp(karp->source, karp->sink, e->graph->size);
    copy = graph_copy(e->graph);
    run = path_build(copy, e->adj, karp_tmp);
    tmp = rentability_calcul(run, (size_t)e->ants);
    if (tmp < *rentability)
    {
        if (e->run != NULL)
            array_dispose((t_array *)e->run, &path_free);
        *rentability = tmp;
        e->run = run;
    }
    else
        array_dispose((t_array *)run, &path_free);
    free_karp(karp_tmp);
    graph_free(copy);
}

void    edmonds_karp(t_env *e, t_karp *karp, void (*saver)(t_env *, t_karp *, double *))
{
    double rentability;

    rentability = FLT_MAX;
    ft_bzero((void *)karp->visited, sizeof(bool) * (size_t)e->graph->size);
    while (bfs(e->graph, e->adj, karp, &condidition_capacity))
    {
        graph_augment_flow(e->graph, karp);
        saver(e, karp, &rentability);
        ft_bzero((void *)karp->visited, sizeof(bool) * (size_t)e->graph->size);
    }
}