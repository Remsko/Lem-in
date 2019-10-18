/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 11:12:30 by rpinoit           #+#    #+#             */
/*   Updated: 2019/10/18 14:02:37 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include "path.h"
#include "algorithm.h"
#include "graph.h"
#include "types.h"
#include "array_42.h"
#include "memory_42.h"

static inline void	graph_augment_flow(t_graph *graph, t_karp *karp)
{
	size_t v;
	size_t u;

	v = karp->sink;
	while (v != karp->source)
	{
		u = karp->parent[v];
		graph->edge[v][u].flow -= 1;
		graph->edge[u][v].flow += 1;
		v = karp->parent[v];
	}
}

void				edmonds_karp(t_env *e, t_karp *karp,
						void (*saver)(t_env *, t_karp *))
{
	e->average = FLT_MAX;
	while (bfs(e->graph, e->adj, karp))
	{
		graph_augment_flow(e->graph, karp);
		saver(e, karp);
		ft_bzero((void *)karp->visited, sizeof(bool) * e->graph->size);
	}
}
