/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 11:12:30 by rpinoit           #+#    #+#             */
/*   Updated: 2019/03/30 16:44:46 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"
#include "path.h"
#include "algorithm.h"
#include "graph.h"
#include "types.h"

void graph_augment_flow(t_graph *graph, t_karp *karp)
{
    unsigned int v;
    unsigned int u;

    v = karp->sink;
    while (v != karp->source)
    {
        u = karp->parent[v];
        graph->edge[v][u].flow -= 1;
        graph->edge[u][v].flow += 1;
        v = karp->parent[v];
    }
}

float rentability_calcul(t_run *run, int ants)
{
    size_t index;
    int total;

    index = 0;
    while (index < run->length)
    {
        total += run->paths[index]->length;
        ++index;
    }
    return ((float)((total + ants) / run->length));
}

int edmonds_karp(t_env *e, t_karp *karp)
{
    t_run *run;
    t_graph *copy;
    t_karp *karp_tmp;
    float rentability;
    float rentability_tmp;
    int max_flow;

    max_flow = 0;
    while (bfs_capacity(e->graph, e->adj, karp))
    {
        graph_augment_flow(e->graph, karp);
        karp_tmp = new_karp(karp->source, karp->sink, e->graph->size);
        copy = graph_copy(e->graph);
        run = path_build(copy, e->adj, karp_tmp);
        rentability = rentability_calcul(run, e->ants);
        if (rentability < rentability_tmp)
        {
            rentability_tmp = rentability;
            e->run = run;
        }
        else
            array_dispose((t_array *)run, &path_free);
        free_karp(karp_tmp);
        free_graph(copy);
        max_flow += 1;
    }
    return (max_flow);
}