/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 11:12:30 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/18 21:10:37 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <limits.h>
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

bool ret(bool *visited, int t)
{
    bool r;

    r = visited[t];
    free(visited);
    return (r);
}

bool bfs(t_graph *graph, t_adjacency *adj, int *parent, int s, int t)
{
    t_queue queue;
    bool *visited;
    int u;
    int v;
    int link;

    if ((visited = (bool *)ft_memalloc(sizeof(bool) * (size_t)graph->row)) == NULL)
        return (false);
    ft_bzero((void *)&queue, sizeof(t_queue));
    en_queue(&queue, s);
    visited[s] = true;
    while (is_queue(&queue))
    {
        u = de_queue(&queue);
        link = 0;
        while (link < adj[u].length)
        {
            v = adj[u].list[link];
            if (visited[v] == false && graph->flow[u][v] > 0)
            {
                en_queue(&queue, v);
                visited[v] = true;
                parent[v] = u;
            }
            ++link;
        }
    }
    return (ret(visited, t));
}

int edmonds_karp(t_graph *graph, t_adjacency *adj, int source, int sink)
{
    int *parent;
    int v;
    int u;
    int path_flow;
    int max_flow;

    if ((parent = (int *)malloc(sizeof(int) * (size_t)graph->row)) == NULL)
        return (0);
    ft_memset(parent, -1, sizeof(int) * (size_t)graph->row);
    max_flow = 0;
    while (bfs(graph, adj, parent, source, sink))
    {
        path_flow = INT_MAX;
        v = sink;
        while (v != source)
        {
            u = parent[v];
            path_flow = min(path_flow, graph->flow[u][v]);
            v = parent[v];
        }
        v = sink;
        while (v != source)
        {
            u = parent[v];
            graph->flow[u][v] -= path_flow;
            graph->flow[v][u] += path_flow;
            v = parent[v];
        }
        max_flow += path_flow;
    }
    free(parent);
    return (max_flow);
}