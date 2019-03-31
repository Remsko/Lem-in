/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:06:33 by rpinoit           #+#    #+#             */
/*   Updated: 2019/03/31 23:56:07 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "memory_42.h"
#include "array_42.h"
#include "write_42.h"
#include "error_42.h"

#include "parser.h"
#include "anthill.h"
#include "garbage.h"
#include "algorithm.h"
#include "graph.h"

t_env	*env_new(void)
{
	t_env *env;

	malloc_or_die((void **)&env, sizeof(t_env), "main");
	ft_bzero((void *)env, sizeof(t_env));
	env->anthill = (t_anthill *)array_create(sizeof(char *));
	if (env->anthill == NULL)
		error_malloc("main");
	env->map = (t_map *)array_create(sizeof(t_room *));
	if (env->map == NULL)
		error_malloc("main");
	env->start = (unsigned int)-1;
	env->end = (unsigned int)-1;
	return (env);
}

static void	print_usage(char *bin)
{
	ft_putstr("usage: ");
	ft_putstr(bin);
	ft_putstr(" < map\n");
}
#include <stdio.h>
int		main(int ac, char **av)
{
	t_env	*env;
	t_error	*err;

	if (ac == 1)
	{
		env = env_new();
		err = parser_all(env);
		if (err != NULL)
		{
			ft_putstr_fd("ERROR\n", 2);
			error_throw(err, NULL, false);
			garbage_all(env);
			return (1);
		}
		//room_print(env->map);
		//graph_print(env->graph);
		algorithm_launch(env);
		if (env->run != NULL)
		{
			anthill_print(env->anthill);
			printf("\n");
			ants_algorithm(env);
		}
		//graph_print(env->graph);
		garbage_all(env);
	}
	else
		print_usage(av[0]);
	return (0);
}