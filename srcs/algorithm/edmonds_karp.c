/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 11:12:30 by rpinoit           #+#    #+#             */
/*   Updated: 2019/03/02 18:13:22 by rpinoit          ###   ########.fr       */
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

int edmonds_karp(t_graph *graph, t_adjacency *adj, t_karp *karp)
{
    t_run *run;
    t_graph *copy;
    t_karp *karp_tmp;
    int max_flow;
    //int cycles;

    max_flow = 0;
    while (bfs_capacity(graph, adj, karp))
    {
        graph_augment_flow(graph, karp);
        karp_tmp = new_karp(karp->source, karp->sink, graph->size);
        copy = graph_copy(graph);
        run = path_build(copy, adj, karp_tmp);
        /*
        cycles = cycle_count(run, e->ants);
        if (cycle < e->cycles)
            snapshot();
        */
        array_dispose((t_array *)run, &path_free);
        free_karp(karp_tmp);
        free_graph(copy);
        max_flow += 1;
    }
    return (max_flow);
}