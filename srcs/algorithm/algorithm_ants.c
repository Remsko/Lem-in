/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_ants.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 13:50:08 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/02 01:38:07 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "types.h"
#include "cycle.h"
#include "write_42.h"
#include "array_42.h"
#include "liblst.h"

bool path_worth(t_path *path)
{
	(void)path;
	return (true);
}

void dlist_push(t_dlist **head, void *content)  
{
	t_dlist *new;

	if ((new = malloc(sizeof(t_dlist))) == NULL)
		return ;
	new->content = content;  
	new->prev = NULL;  
	new->next = *head;  
	if (*head != NULL)  
		(*head)->prev = new;  
	*head = new;  
} 

void dlist_cut(t_dlist **head_ref, t_dlist *delete, void (free_content)(void *))
{
	if (*head_ref == NULL || delete == NULL)  
		return ;
	if (*head_ref == delete)  
		*head_ref = delete->next;  
	if (delete->next != NULL)  
		delete->next->prev = delete->prev;  
	if (delete->prev != NULL)  
		delete->prev->next = delete->next;  
	free_content(delete->content);
	free(delete);  
	return; 
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

	ant->index++;
	index = ant->path->list[ant->index];
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

void    ants_forward(t_map *map, t_dlist **head, t_cycle *cycle)
{
	t_dlist *forwarded;
	t_dlist *node;
	t_ant *ant;

	node = *head;
	while (node != NULL)
	{
		forwarded = node;
		ant = (t_ant *)forwarded->content;
		ant_forward(map, ant, cycle);
		node = node->next;
		if (ant_arrived(map, ant))
			dlist_cut(head, forwarded, &free);
	}
	array_append((t_array *)cycle, (void *)"\n");
}

void new_turn(t_run *run, t_dlist **head, int *ant_id, int ant_number)
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
			ant = ant_new(path, ant_id);
			dlist_push(head, ant);
		}
		++index;
	}
}

void algorithm_ants(t_env *e)
{
	t_cycle *cycle;
	t_dlist *head;
	int ant_id;
	int lines;

	lines = 0;
	ant_id = 0;
	head = NULL;
	cycle = (t_cycle *)array_create(sizeof(char));
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
	free(cycle->line);
	free(cycle);
}
