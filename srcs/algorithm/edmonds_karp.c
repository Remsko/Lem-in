/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 11:12:30 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/09 13:24:28 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <limit.h>
#include "types.h"

int min(int a, int b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

bool bfs(t_graph *graph, t_room *s, t_room *t, void *parent)
{
    t_queue *queue;
    bool *visited;
    int value;
    int index;

    visited = (bool *)malloc(sizeof(bool * graph->row));
    ft_bzero((void *)visited, sizeof(bool) * row);
    queue = new_queue();
    queue_append(queue, s);
    visited[s] = true;
    while (queue != NULL)
    {
        u = pop_left(queue);
        index = 0;
        while (index < graph->row)
        {
            value = graph[u][index];
            if (value > 0 && visited[index] == false)
            {
                queue_append(queue, index);
                visited[index] = true;
                parent[index] = u;
            }
        }
    }
    return (visited[t]);
}

int edmonds_karp(t_graph *graph, t_room *source, t_room *sink)
{
    t_room *v;
    t_room *u;
    t_room *s;
    void *parent;
    int path_flow;
    int max_flow;

    parent = NULL; // malloc du nombre de room
    max_flow = 0;
    while (bfs(start, end, parent))
    {
        path_flow = 0x7fffffff; //int max
        s = sink;
        while (s != source)
        {
            path_flow = min(path_flow, graph[s][s]);
            s = parent[s];
        }
        v = sink;
        while (v != source)
        {
            u = parent[v];
            graph[u][v] -= path_flow;
            graph[v][u] += path_flow;
            v = parent[v];
        }
        max_flow += path_flow;
    }
    return (max_flow);
}