/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_ants.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 13:50:08 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/01 14:27:20 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "types.h"
#include "cycle.h"
#include "write_42.h"
#include "array_42.h"

bool path_worth(t_path *path)
{
    (void)path;
    return (true);
}

typedef struct s_list
{
    struct s_list *next;
    t_ant *ant;
}   t_list;

void list_add(t_list **head, t_list *new)
{
	if (head != NULL && new != NULL)
	{
		new->next = *head;
		*head = new;
	}
}

t_list *list_new(t_ant *ant)
{
	t_list *new;

	if ((new = (t_list *)malloc(sizeof(t_list))) != NULL)
	{
		new->next = NULL;
		new->ant = ant;
	}
	return (new);
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

void list_delete_one(t_list **head, t_list *node)
{
    t_list *tmp;
    t_list *prev;

    if (head == NULL || *head == NULL || node == NULL)
        return ;
    if (*head == node)
    {
        *head = (*head)->next;
        free(node->ant);
        free(node);
    }
    tmp = *head;
    prev = *head;
    while (tmp != NULL && tmp != node)
    {
        prev = tmp;
        tmp = prev->next;
    }
    if (tmp == NULL)
        return ;
    prev->next = tmp->next;
    free(tmp->ant);
    free(tmp);
}

void    ants_forward(t_map *map, t_list **head, t_cycle *cycle)
{
    t_list *node;
    t_ant *ant;

    node = *head;
    while (node != NULL)
    {
        ant = node->ant;
        ant_forward(map, ant, cycle);
        node = node->next;
    }
    array_append((t_array *)cycle, (void *)"\n");
}

bool    ants_delete(t_map *map, t_list **head)
{
    t_list *node;
    t_ant *ant;

    node = *head;
    while (node != NULL)
    {
        ant = node->ant;
        if (ant_arrived(map, ant))
        {
            list_delete_one(head, node);
            return (true);
        }
        node = node->next;
    }
    return (false);
}

void new_turn(t_run *run, t_list **head, int *ant_id, int ant_number)
{
    t_list *node;
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
            node = list_new(ant);
            list_add(head, node);
        }
        ++index;
    }
}

void algorithm_ants(t_env *e)
{
    t_cycle *cycle;
    t_list *head;
    int ant_id;
    int lines;

    lines = 0;
    ant_id = 0;
    head = NULL;
    cycle = (t_cycle *)array_create(sizeof(char));
    new_turn(e->run, &head, &ant_id, e->ants);
    while (head != NULL)
    {
        ++lines;
        ants_forward(e->map, &head, cycle);
        while (ants_delete(e->map, &head))
            ;
        if (ant_id < e->ants)
            new_turn(e->run, &head, &ant_id, e->ants);
    }
    cycle_print(cycle);
    free(cycle->line);
    free(cycle);
}