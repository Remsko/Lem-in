/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_build.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 13:14:31 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/01 18:45:01 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "algorithm.h"
#include "path.h"
#include "memory_42.h"
#include "array_42.h"
#include "queue_42.h"

size_t	consume_path(t_graph *graph, t_karp *karp)
{
	size_t path_length;
	size_t v;
	size_t u;

	path_length = 1;
	v = karp->sink;
	while (v != karp->source)
	{
		u = karp->parent[v];
		karp->visited[u] = true;
		graph->edge[v][u].flow = 0;
		graph->edge[u][v].flow = 0;
		v = karp->parent[v];
		++path_length;
	}
	return (path_length);
}

bool edge_condition_flow(t_edge *edge)
{
	return (edge->flow > 0);
}

t_run	*path_build(t_graph *graph, t_adjacency *adj, t_karp *karp)
{
	t_run	*run;
	t_path	*new;
	size_t	path_length;

	if ((run = (t_run *)array_create(sizeof(t_path *))) == NULL)
		return (NULL);
	ft_bzero(karp->parent, sizeof(size_t) * graph->size);
	ft_bzero((void *)karp->visited, sizeof(bool) * graph->size);
	while (bfs(graph, adj, karp, &edge_condition_flow))
	{
		ft_bzero((void *)karp->visited, sizeof(bool) * graph->size);
		path_length = consume_path(graph, karp);
		if ((new = path_new(karp, path_length)) == NULL)
		{
			array_dispose((t_array *)run, &path_free);
			return (NULL);
		}
		path_add(run, new);
	}
	return (run);
}
