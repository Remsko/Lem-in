/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_ants.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 13:50:08 by rpinoit           #+#    #+#             */
/*   Updated: 2019/10/16 13:35:48 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "types.h"
#include "cycle.h"
#include "ant.h"
#include "free_42.h"
#include "write_42.h"
#include "array_42.h"
#include "dll_42.h"

bool path_worth(size_t length, int lines, double average)
{
	(void)length;
	(void)lines;
	(void)average;
	//return (average - (double)length > (double)lines - 1.0);
	return true;
}

void ants_forward(t_map *map, t_dll **head, t_cycle *cycle)
{
	t_dll *forwarded;
	t_dll *node;
	t_ant *ant;

	node = *head;
	while (node != NULL)
	{
		forwarded = node;
		ant = (t_ant *)forwarded->content;
		ant_forward(map, ant, cycle);
		node = node->next;
		if (ant_arrived(map, ant))
			dll_delete(head, forwarded, &free);
	}
	cycle_add(cycle, '\n');
}

void new_turn(t_env *e, t_dll **head, int *ant_id, int lines)
{
	t_ant *ant;
	t_path *path;
	size_t index;

	(void)lines;
	index = 0;
	while (index < e->run->length)
	{
		path = e->run->paths[index];
		if (path_worth(path->length, lines, e->average) && *ant_id < e->ants)
		{
			if ((ant = ant_new(path, ant_id)) != NULL)
				dll_push_front(head, ant);
			else
				ft_putstr("Warning: Failed to malloc ant.\n");
		}
		++index;
	}
}

void algorithm_ants(t_env *e)
{
	t_cycle *cycle;
	t_dll *head;
	int ant_id;
	int lines;

	lines = 0;
	ant_id = 0;
	head = NULL;
	if ((cycle = (t_cycle *)array_create(sizeof(char))) == NULL)
		return (ft_putstr("Error: Failed to malloc cycle.\n"));
	cycle_add(cycle, '\n');
	new_turn(e, &head, &ant_id, lines);
	while (head != NULL)
	{
		++lines;
		ants_forward(e->map, &head, cycle);
		if (ant_id < e->ants)
			new_turn(e, &head, &ant_id, lines);
	}
	cycle_print(cycle);
	array_dispose((t_array *)cycle, &free_1d_char);
}
