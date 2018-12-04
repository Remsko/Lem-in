/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:06:33 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/04 17:46:31 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "memory_42.h"
#include "write_42.h"
#include "lem_in.h"

int		main(void)
{
	t_env env;

	ft_bzero(&env, sizeof(t_env));
	if (parser_all(&env) == true)
	{
		//algo
		//printer
		//free
	}
	else
	{
		ft_putstr("ERROR\n");
		//free
		return (1);
	}
	return (0);
}
