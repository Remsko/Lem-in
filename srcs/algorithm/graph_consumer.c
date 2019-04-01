/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_consumer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 10:06:20 by rpinoit           #+#    #+#             */
/*   Updated: 2019/03/02 16:31:03 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "array_42.h"
#include "queue_42.h"
#include "memory_42.h"
#include "path.h"
#include "algorithm.h"
#include "types.h"

void graph_consumer(t_env *e, t_karp *karp)
{
    t_path *new;
    size_t path_length;
    unsigned int v;
    unsigned int u;

	e->run = (t_run *)array_create(sizeof(t_path *));
    ft_memset(karp->parent, 0, sizeof(int) * (size_t)e->graph->size);
    while (bfs_flow(e->graph, e->adj, karp))
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
        new = path_new(karp, path_length);
        path_add(e->run, new);
    }
}