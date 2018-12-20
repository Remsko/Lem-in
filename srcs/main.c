/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:06:33 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/20 18:04:48 by rpinoit          ###   ########.fr       */
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

t_env	*env_new(void)
{
	t_env *env;

	malloc_or_die((void **)&env, sizeof(t_env), "main");
	ft_bzero((void *)env, sizeof(t_env));
	env->anthill = (t_anthill *)array_create(sizeof(char *));
	if (env->anthill == NULL)
		error_malloc("main");
	return (env);
}

int		main(void)
{
	t_env	*env;
	t_error	*err;

	env = env_new();
	err = parser_all(env);
	if (err == NULL)
	{
		anthill_print(env->anthill);
	}
	else
	{
		ft_putstr("ERROR\n");
		error_throw(err, NULL, false);
		return (1);
	}
	garbage_all(env);
	return (0);
}