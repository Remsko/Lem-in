/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:50:07 by rpinoit           #+#    #+#             */
/*   Updated: 2019/10/18 15:02:16 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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

static void		run_saver(t_env *e, t_karp *karp)
{
	t_run	*run;
	t_karp	*karp_tmp;
	double	tmp;

	if ((karp_tmp = new_karp(karp->source, karp->sink, e->graph->size)) == NULL)
		return ;
	if ((run = path_build(e->graph, e->adj, karp_tmp)) == NULL)
		return (free(karp_tmp));
	tmp = rentability_calcul(run, (size_t)e->ants);
	if (tmp < e->average)
	{
		if (e->run != NULL)
			array_dispose((t_array *)e->run, &path_free);
		e->average = tmp;
		e->run = run;
	}
	else
		array_dispose((t_array *)run, &path_free);
	free_karp(karp_tmp);
}

void			algorithm_paths(t_env *env)
{
	t_karp	*karp;

	if (env->map->length == 2)
		return (path_start_end(env));
	if ((karp = new_karp(env->start, env->end, env->graph->size)) == NULL)
		ft_putstr_fd("ERROR\n", 2);
	edmonds_karp(env, karp, &run_saver);
	free_karp(karp);
	if (env->run == NULL)
		ft_putstr_fd("ERROR\n", 2);
}
