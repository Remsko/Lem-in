/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 13:50:08 by rpinoit           #+#    #+#             */
/*   Updated: 2019/03/31 16:44:24 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "types.h"

typedef struct s_list
{
	struct s_list	*next;
	t_ant *individual;
} t_list;

void list_add(t_list **head, t_list *new)
{
	if (head != NULL && new != NULL)
	{
		new->next = *head;
		*head = new;
	}
}

void list_delete_one(t_list **list)
{
    t_list *tmp;

    if (list == NULL || *list == NULL)
        return ;
    tmp = *list;
	*list = (*list)->next;
    free(tmp->individual);
    free(tmp);
}

t_list *list_new(t_ant *ant)
{
	t_list *new;

	if ((new = (t_list *)malloc(sizeof(t_list))) != NULL)
	{
		new->next = NULL;
		new->individual = ant;
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

void ant_forward(t_map *map, t_ant *ant)
{
    //print move;
    char *name;
    unsigned int index;

    if (ant->index + 1 < ant->path->length)
        ant->index++;
    else
    {
        printf("\nerror\n");
    }
    index = ant->path->list[ant->index];
    name = map->rooms[index]->name;
    printf("L%d-%s ", ant->id, name);
}

bool ant_arrived(t_map *map, t_ant *ant)
{
    unsigned int index;

    index = ant->path->list[ant->index];
    if (map->rooms[index]->type == END)
        return (true);
    return (false);
}

void    ants_forward(t_map *map, t_list **ant_list)
{
    t_list *list;
    t_ant *ant;

    list = *ant_list;
    while (list != NULL)
    {
        ant = list->individual;
        ant_forward(map, ant);
        if (ant_arrived(map, ant))
            list_delete_one(&list);
        if (list == NULL)
            break ;
        list = list->next;
    }
    printf("\n");
}

bool path_worth(t_path *path)
{
    (void)path;
    return (true);
}

void new_turn(t_run *run, t_list **ant_list_ptr, int *ant_id, int ants)
{
    t_list *list;
    t_ant *ant;
    t_path *path;
    size_t index;

    index = 0;
    while (index < run->length)
    {
        path = run->paths[index];
        if (path_worth(path) && *ant_id < ants)
        {
            ant = ant_new(path, ant_id);
            list = list_new(ant);
            list_add(ant_list_ptr, list);
        }
        ++index;
    }
}

void ants_algorithm(t_env *e)
{
    t_list **list_ptr;
    t_list *ant_list;
    int ant_id;
    int cycle;

    cycle = 0;
    ant_id = 0;
    ant_list = NULL;
    list_ptr = &ant_list;
    new_turn(e->run, list_ptr, &ant_id, e->ants);
    while (ant_list != NULL)
    {
        ants_forward(e->map, list_ptr);
        if (ant_id < e->ants)
            new_turn(e->run, list_ptr, &ant_id, e->ants);
        ++cycle;
    }
}