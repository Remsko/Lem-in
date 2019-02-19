/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_consumer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:07:11 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/19 11:27:03 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "types.h"
#include "queue_42.h"
#include "memory_42.h"
#include "write_42.h"

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

void graph_consumer(t_graph *graph, t_adjacency *adj, t_karp *karp)
{
    unsigned int v;
    unsigned int u;

    ft_memset(karp->parent, 0, sizeof(int) * (size_t)graph->size);
    if (bfs_(graph, adj, karp) == false)
        return (ft_putstr("No path found."));
    v = karp->sink;
    while (v != karp->source)
    {
        u = karp->parent[v];
        graph->flow[u][v] = 0;
        graph->flow[v][u] = 0;
        v = karp->parent[v];
    }
}