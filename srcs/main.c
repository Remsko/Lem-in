/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:06:33 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/13 17:47:14 by rpinoit          ###   ########.fr       */
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
	t_env env;

	ft_bzero(&env, sizeof(t_env));
	if ((env.anthill = (t_anthill *)array_create(sizeof(char *))) == NULL)
		error_malloc();
	if (parser_all(&env) == true)
	{
		anthill_print(env.anthill);
		//algo
		//printer
		//free
	}
	else
	{
		ft_putstr("ERROR\n");
		//free
	}
	garbage_all(&env);
	return (0);
}
