/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 11:12:30 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/01 18:45:36 by rpinoit          ###   ########.fr       */
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

bool edge_condidition_capacity(t_edge *edge)
{
    return (edge->capacity > edge->flow);
}

void    edmonds_karp(t_env *e, t_karp *karp)
{
    t_run *run;
    t_graph *copy;
    t_karp *karp_tmp;
    double rentability;
    double rentability_tmp;

    rentability_tmp = FLT_MAX;
    ft_bzero((void *)karp->visited, sizeof(bool) * (size_t)e->graph->size);
    while (bfs(e->graph, e->adj, karp, &edge_condidition_capacity))
    {
        graph_augment_flow(e->graph, karp);
        karp_tmp = new_karp(karp->source, karp->sink, e->graph->size);
        copy = graph_copy(e->graph);
        run = path_build(copy, e->adj, karp_tmp);
        rentability = rentability_calcul(run, (size_t)e->ants);
        if (rentability < rentability_tmp)
        {
            if (e->run != NULL)
                array_dispose((t_array *)e->run, &path_free);
            rentability_tmp = rentability;
            e->run = run;
        }
        else
            array_dispose((t_array *)run, &path_free);
        free_karp(karp_tmp);
        graph_free(copy);
        ft_bzero((void *)karp->visited, sizeof(bool) * (size_t)e->graph->size);
    }
}