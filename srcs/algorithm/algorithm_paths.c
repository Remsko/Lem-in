/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:50:07 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/15 14:52:24 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "room.h"
#include "types.h"
#include "algorithm.h"
#include "path.h"
#include "graph.h"
#include "write_42.h"
#include "array_42.h"

static double	rentability_calcul(t_run *run, size_t ants)
{
	size_t index;
	size_t total;

	index = 0;
	total = 0;
	while (index < run->length)
	{
		total += run->paths[index]->length;
		++index;
	}
	return ((double)(total + ants) / (double)run->length);
}

/* protect malloc plz */
static void		run_saver(t_env *e, t_karp *karp, double *rentability)
{
	t_run	*run;
	t_graph	*copy;
	t_karp	*karp_tmp;
	double	tmp;

	karp_tmp = new_karp(karp->source, karp->sink, e->graph->size);
	copy = graph_copy(e->graph);
	run = path_build(copy, e->adj, karp_tmp);
	tmp = rentability_calcul(run, (size_t)e->ants);
	if (tmp < *rentability)
	{
		if (e->run != NULL)
			array_dispose((t_array *)e->run, &path_free);
		*rentability = tmp;
		e->run = run;
	}
	else
		array_dispose((t_array *)run, &path_free);
	free_karp(karp_tmp);
	graph_free(copy);
}

void			algorithm_paths(t_env *env)
{
	t_karp *karp;

	if (env->map->length == 2)
		return (path_start_end(env));
	karp = new_karp(env->start, env->end, env->graph->size);
	edmonds_karp(env, karp, &run_saver);
	free_karp(karp);
	if (env->run == NULL)
		return (ft_putstr("ERROR\nNo path were found."));
}
/*                  */