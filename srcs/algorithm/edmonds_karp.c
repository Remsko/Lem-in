/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 11:12:30 by rpinoit           #+#    #+#             */
/*   Updated: 2019/03/02 10:57:50 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "types.h"
#include "queue_42.h"
#include "memory_42.h"
#include "limits.h"
/*
#include <write_42.h>
#include <stdio.h>*/
#include "graph.h"
/*
static int min(int a, int b)
{
    return (a > b ? b : a);
}*/

bool bfs(t_graph *graph, t_adjacency *adj, t_karp *karp)
{
    t_queue queue;
    size_t link;
    unsigned int u;
    unsigned int v;

    ft_bzero((void *)karp->visited, sizeof(bool) * (size_t)graph->size);
    ft_bzero((void *)&queue, sizeof(t_queue));
    en_queue(&queue, (int)karp->source);
    karp->visited[karp->source] = true;
    while (is_queue(&queue))
    {
        u = (unsigned int)de_queue(&queue);
        link = 0;
        while (link < adj[u].length)
        {
            v = adj[u].list[link];
            if (karp->visited[v] == false && graph->edge[u][v].capacity > graph->edge[u][v].flow)
            {
                en_queue(&queue, (int)v);
                karp->visited[v] = true;
                karp->parent[v] = u;
            }
            ++link;
        }
    }
    return (karp->visited[karp->sink]);
}

int edmonds_karp(t_graph *graph, t_adjacency *adj, t_karp *karp)
{
    unsigned int v;
    unsigned int u;
    int max_flow;

    max_flow = 0;
    while (bfs(graph, adj, karp))
    {
        v = karp->sink;
        while (v != karp->source)
        {
            u = karp->parent[v];
            graph->edge[v][u].flow -= 1;
            graph->edge[u][v].flow += 1;
            v = karp->parent[v];
        }
        max_flow += 1;
    }
    return (max_flow);
}