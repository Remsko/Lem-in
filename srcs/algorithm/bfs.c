/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 11:19:43 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/01 19:08:26 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "memory_42.h"
#include "queue_42.h"
#include "types.h"

bool	bfs(t_graph *graph, t_adjacency *adj, t_karp *karp, bool (*c)(t_edge *))
{
	t_queue	queue;
	size_t	link;
	size_t	u;
	size_t	v;

    ft_bzero((void *)&queue, sizeof(t_queue));
	en_queue(&queue, karp->source);
	karp->visited[karp->source] = true;
	while (is_queue(&queue))
	{
		u = de_queue(&queue);
		link = 0;
		while (link < adj[u].length)
		{
			v = adj[u].list[link];
			if (karp->visited[v] == false && c(&graph->edge[u][v]))
			{
				en_queue(&queue, v);
				karp->visited[v] = true;
				karp->parent[v] = u;
			}
			++link;
		}
	}
	return (karp->visited[karp->sink]);
}
