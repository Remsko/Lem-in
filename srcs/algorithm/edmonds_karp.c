/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 11:12:30 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/15 14:46:59 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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

static inline bool	condidition_capacity(t_edge *edge)
{
	return (edge->capacity > edge->flow);
}

static inline void	reset_visited(bool *visited, size_t size)
{
	ft_bzero((void *)visited, sizeof(bool) * size);
}

void				edmonds_karp(t_env *e, t_karp *karp,
						void (*saver)(t_env *, t_karp *, double *))
{
	double rentability;

	rentability = FLT_MAX;
	reset_visited(karp->visited, e->graph->size);
	while (bfs(e->graph, e->adj, karp, &condidition_capacity))
	{
		graph_augment_flow(e->graph, karp);
		saver(e, karp, &rentability);
		reset_visited(karp->visited, e->graph->size);
	}
}
