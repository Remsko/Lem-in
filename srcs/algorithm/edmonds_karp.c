/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 11:12:30 by rpinoit           #+#    #+#             */
/*   Updated: 2019/03/02 11:46:49 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include "types.h"

void graph_update(t_graph *graph, t_karp *karp)
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
    //t_graph *copy;
    int max_flow;
    //int cycles;

    max_flow = 0;
    while (bfs(graph, adj, karp))
    {
        graph_update(graph, karp);
        /*
        graph_copy(graph, copy);
        run = path_build(graph, adj, karp);
        cycles = cycle_count(run, e->ants);
        if (cycle < e->cycles)
            snapshot();
        */
        max_flow += 1;
    }
    return (max_flow);
}