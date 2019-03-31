/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 13:50:08 by rpinoit           #+#    #+#             */
/*   Updated: 2019/03/31 23:38:18 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "types.h"
#include "write_42.h"

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

void print_list(t_list *head, bool add)
{
    printf("\nlist %s: ", add ? "add" : "delete");
    if (head == NULL)
    {
        printf("empty");
        return ;
    }
    while (head->next != NULL)
    {
        printf("%d->", head->ant->id);
        head = head->next;
    }
    printf("%d", head->ant->id);
    printf("\n");
}

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

void ant_forward(t_map *map, t_ant *ant)
{
    //print move;
    char *name;
    unsigned int index;

    ant->index++;
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

void    ants_forward(t_map *map, t_list **head)
{
    t_list *node;
    t_ant *ant;

    node = *head;
    while (node != NULL)
    {
        ant = node->ant;
        ant_forward(map, ant);
        node = node->next;
    }
    printf("\n");
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
            //print_list(*head, true);
            /* ajouter vers l'avant ou vers l'arriere peut rendre coherent l'ordre d'affichage
            du mouvement des fourmis lors dans tour */
        }
        ++index;
    }
}

void ants_algorithm(t_env *e)
{
    t_list *head;
    int ant_id;
    int cycle;

    if (e->run == NULL)
        return ;
    printf("\n");
    cycle = 0;
    ant_id = 0;
    head = NULL;
    new_turn(e->run, &head, &ant_id, e->ants);
    while (head != NULL)
    {
        ++cycle;
        //ft_putnbr(cycle);
        //ft_putstr(" : ");
        ants_forward(e->map, &head);
        while (ants_delete(e->map, &head))
            ;
        if (ant_id < e->ants)
            new_turn(e->run, &head, &ant_id, e->ants);
    }
    //printf("\ncycle: %d\n", cycle);
}