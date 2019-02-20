/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 11:12:30 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/20 21:54:14 by rpinoit          ###   ########.fr       */
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

static int min(int a, int b)
{
    return (a > b ? b : a);
}

bool bfs(t_graph *graph, t_adjacency *adj, t_karp *karp)
{
    t_queue queue;
    //size_t link;
    unsigned int u;
    unsigned int v;

    (void)adj;
    ft_bzero((void *)karp->visited, sizeof(bool) * (size_t)graph->size);
    ft_bzero((void *)&queue, sizeof(t_queue));
    en_queue(&queue, (int)karp->source);
    karp->visited[karp->source] = true;
    while (is_queue(&queue))
    {
        u = (unsigned int)de_queue(&queue);
        v = 0;//link = 0;
        while (v/*link*/ < graph->size/*adj[u].length*/)
        {
            //v = graph->edge[u][link];/*adj[u].list[link]*/;
            if (karp->visited[v] == false && graph->edge[u][v].capacity > graph->edge[u][v].flow)
            {
                en_queue(&queue, (int)v);
                karp->visited[v] = true;
                karp->parent[v] = u;
            }
            v++/*++link*/;
        }
    }
    return (karp->visited[karp->sink]);
}

int edmonds_karp(t_graph *graph, t_adjacency *adj, t_karp *karp)
{
    unsigned int v;
    unsigned int u;
    int path_flow;
    int max_flow;

    (void)adj;
    max_flow = 0;
    while (bfs(graph, adj, karp))
    {
        path_flow = INT_MAX;
        v = karp->sink;
        while (v != karp->source)
        {
            u = karp->parent[v];
            path_flow = min(path_flow, graph->edge[u][v].capacity - graph->edge[u][v].flow);
            v = karp->parent[v];
        }
        v = karp->sink;
        while (v != karp->source)
        {
            u = karp->parent[v];
            graph->edge[v][u].flow -= path_flow;
            graph->edge[u][v].flow += path_flow;
            v = karp->parent[v];
        }
        max_flow += path_flow;
    }
    return (max_flow);
}