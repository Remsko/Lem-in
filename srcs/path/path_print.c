/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:40:48 by rpinoit           #+#    #+#             */
/*   Updated: 2019/10/17 21:20:22 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "write_42.h"

#include "string_42.h"
#include "array_42.h"
#include <stdio.h>

void check_doublon(t_array *allnames)
{
	for (size_t i = 0; i < allnames->length; i++)
	{
		for (size_t j = 0; j < allnames->length; j++)
		{
			if (i != j)
			{
				if (ft_strequ(((char **)allnames->content)[i], ((char **)allnames->content)[j]))
				{
					printf("room1: '%s' at %zu;\nroom2: '%s' at %zu;\n\n", ((char **)allnames->content)[i], i, ((char **)allnames->content)[j], j);
				}
			}
		}
	}
}

void path_print(t_run *run, t_map *map)
{
	t_path *path;
	size_t run_index;
	size_t path_index;
	size_t room;

	run_index = 0;
	t_array *allnames = array_create(sizeof(char **));
	while (run_index < run->length)
	{
		path = run->paths[run_index];
		path_index = 0;
		//ft_putstr("#");
		while (path_index < path->length - 1)
		{
			room = path->list[path_index];
			//ft_putstr(map->rooms[room]->name);

			array_append(allnames, (void *)&map->rooms[room]->name);

			//ft_putstr("->");
			++path_index;
		}
		room = path->list[path_index];
		//ft_putendl(map->rooms[room]->name);
		++run_index;
	}

	check_doublon(allnames);
}
