/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_ants.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 13:50:08 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/03 13:06:34 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "types.h"
#include "cycle.h"
#include "free_42.h"
#include "write_42.h"
#include "array_42.h"
#include "dll_42.h"

bool path_worth(t_path *path)
{
	(void)path;
	return (true);
}

t_ant *ant_new(t_path *path, int *id)
{
	t_ant *new;

	if ((new = (t_ant *)malloc(sizeof(t_ant))) != NULL)
	{
		new->id = ++(*id);
		new->index = 0;
		new->path = path;
	}
	return (new);
}

void ant_forward(t_map *map, t_ant *ant, t_cycle *cycle)
{
	char *name;
	size_t index;

	index = ant->path->list[++ant->index];
	name = map->rooms[index]->name;
	cycle_pattern_add(cycle, name, ant->id);
}

bool ant_arrived(t_map *map, t_ant *ant)
{
	size_t index;

	index = ant->path->list[ant->index];
	if (map->rooms[index]->type == END)
		return (true);
	return (false);
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

void new_turn(t_run *run, t_dll **head, int *ant_id, int ant_number)
{
	t_ant *ant;
	t_path *path;
	size_t index;

	index = 0;
	while (index < run->length)
	{
		path = run->paths[index];
		if (path_worth(path) && *ant_id < ant_number)
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
	new_turn(e->run, &head, &ant_id, e->ants);
	while (head != NULL)
	{
		++lines;
		ants_forward(e->map, &head, cycle);
		if (ant_id < e->ants)
			new_turn(e->run, &head, &ant_id, e->ants);
	}
	cycle_print(cycle);
    array_dispose((t_array *)cycle, &free_1d_char);
}