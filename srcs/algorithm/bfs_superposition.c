/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_superposition.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:52:26 by rpinoit           #+#    #+#             */
/*   Updated: 2019/10/18 14:57:01 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "adjacency.h"
#include "queue_42.h"
#include "memory_42.h"

bool	bfs_superposition(t_graph *graph, t_adjacency *adj, t_karp *karp,
			bool *used)
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
			if (!karp->visited[v] && !used[v] && graph->edge[u][v].flow > 0)
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