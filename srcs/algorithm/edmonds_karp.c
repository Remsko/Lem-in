/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 11:12:30 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/09 15:41:53 by rpinoit          ###   ########.fr       */
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
    t_qnode *u;
    bool *visited;
    int value;
    int index;

    visited = (bool *)malloc(sizeof(bool) * graph->row);
    ft_bzero((void *)visited, sizeof(bool) * graph->row);
    queue = new_queue();
    en_queue(queue, s); // s as index plz
    visited[s] = true;
    while (queue != NULL)
    {
        u = de_queue(queue);
        index = 0;
        while (index < graph->row)
        {
            value = graph[u->key][index];
            if (value > 0 && visited[index] == false)
            {
                en_queue(queue, index);
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