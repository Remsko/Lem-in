/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 11:12:30 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/19 12:48:33 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "types.h"
#include "queue_42.h"
#include "memory_42.h"

int min(int a, int b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

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
            if (karp->visited[v] == false && graph->flow[u][v] > 0)
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
    int path_flow;
    int max_flow;

    ft_memset(karp->parent, -1, sizeof(int) * (size_t)graph->size);
    max_flow = 0;
    while (bfs(graph, adj, karp))
    {
        path_flow = 0x7FFFFFFF;
        v = karp->sink;
        while (v != karp->source)
        {
            u = karp->parent[v];
            path_flow = min(path_flow, graph->flow[u][v]);
            v = karp->parent[v];
        }
        v = karp->sink;
        while (v != karp->source)
        {
            u = karp->parent[v];
            graph->flow[u][v] -= path_flow;
            graph->flow[v][u] += path_flow;
            v = karp->parent[v];
        }
        max_flow += path_flow;
    }
    return (max_flow);
}