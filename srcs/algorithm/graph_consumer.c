/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_consumer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 10:06:20 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/25 16:37:15 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "array_42.h"
#include "queue_42.h"
#include "memory_42.h"
#include "write_42.h"
#include "path.h"
#include "types.h"

#include <stdio.h>
bool bfs_(t_graph *graph, t_adjacency *adj, t_karp *karp)
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
            if (karp->visited[v] == false && graph->edge[u][v].flow > 0)
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

void graph_consumer(t_env *e, t_karp *karp)
{
    t_path *new;
    size_t path_length;
    unsigned int v;
    unsigned int u;

    e->run = (t_run *)array_create(sizeof(t_path *));
    ft_memset(karp->parent, 0, sizeof(int) * (size_t)e->graph->size);
    while (bfs_(e->graph, e->adj, karp))
    {
        path_length = 1;
        v = karp->sink;
        while (v != karp->source)
        {
            u = karp->parent[v];
            e->graph->edge[u][v].flow = 0;
            e->graph->edge[v][u].flow = 0;
            v = karp->parent[v];
            ++path_length;
        }
        new = path_new(karp->parent, path_length, karp->source, karp->sink);
        path_add(e->run, new);
    }
}