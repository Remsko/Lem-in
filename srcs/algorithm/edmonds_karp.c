/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 11:12:30 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/11 18:03:19 by rpinoit          ###   ########.fr       */
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

bool bfs(t_graph *graph, int *parent, int s, int t)
{
    t_queue *queue;
    t_qnode *u;
    bool *visited;
    int value;
    int index;

    if ((visited = (bool *)ft_memalloc(sizeof(bool) * (size_t)graph->row)) == NULL)
        return (false);
    if ((queue = create_queue()) == NULL)
        return (false);
    en_queue(queue, s);
    visited[s] = true;
    parent[s] = -1;
    while ((u = de_queue(queue)) != NULL)
    {
        index = 0;
        while (index < graph->row)
        {
            value = graph->flow[u->key][index];
            if (value > 0 && visited[index] == false && index != u->key)
            {
                en_queue(queue, index);
                visited[index] = true;
                parent[index] = u->key;
            }
            ++index;
        }
        free(u);
    }
    free(visited);
    free(queue);
    return (visited[t]);
}

int edmonds_karp(t_graph *graph, int source, int sink)
{
    int *parent;
    int v;
    int u;
    int s;
    int path_flow;
    int max_flow;

    if ((parent = (int *)malloc(sizeof(int) * (size_t)graph->row)) == NULL)
        return (0);
    ft_memset(parent, -1, sizeof(int) * (size_t)graph->row);
    max_flow = 0;
    while (bfs(graph, parent, source, sink))
    {
        path_flow = INT_MAX;
        s = sink;
        while (s != source)
        {
            path_flow = min(path_flow, graph->flow[parent[s]][s]);
            s = parent[s];
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