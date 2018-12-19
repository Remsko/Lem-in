/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:06:33 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/19 16:47:35 by rpinoit          ###   ########.fr       */
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

int		main(void)
{
	t_env	env;
	t_error	*err;

	ft_bzero(&env, sizeof(t_env));
	if ((env.anthill = (t_anthill *)array_create(sizeof(char *))) == NULL)
		error_malloc("in main for env.anthill .");
	err = parser_all(&env);
	if (err != NULL)
	{
		anthill_print(env.anthill);
		//algo
		//printer
		//free
	}
	else
	{
		ft_putstr("ERROR\n");
		error_throw(err, NULL, false);
		//free
	}
	garbage_all(&env);
	return (0);
}
