/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_build.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 13:14:31 by rpinoit           #+#    #+#             */
/*   Updated: 2019/10/18 14:52:07 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "path.h"
#include "algorithm.h"
#include "array_42.h"
#include "memory_42.h"

static size_t	consume_path(t_karp *karp, bool *used)
{
	size_t path_length;
	size_t v;
	size_t u;

	path_length = 1;
	v = karp->sink;
	while (v != karp->source)
	{
		u = karp->parent[v];
		used[u] = true;
		v = karp->parent[v];
		++path_length;
	}
	return (path_length);
}

t_run			*path_build(t_graph *graph, t_adjacency *adj, t_karp *karp)
{
	t_run	*run;
	t_path	*new;
	size_t	path_length;
	bool	*used;

	if ((used = (bool *)ft_memalloc(sizeof(bool) * graph->size)) == NULL)
		return (NULL);
	if ((run = (t_run *)array_create(sizeof(t_path *))) == NULL)
	{
		free(used);
		return (NULL);
	}
	while (bfs_superposition(graph, adj, karp, used))
	{
		ft_bzero((void *)karp->visited, sizeof(bool) * graph->size);
		path_length = consume_path(karp, used);
		if ((new = path_new(karp, path_length)) == NULL)
		{
			array_dispose((t_array *)run, &path_free);
			return (NULL);
		}
		path_add(run, new);
	}
	free(used);
	return (run);
}
