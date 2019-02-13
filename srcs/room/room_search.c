/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:11:06 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/13 17:51:42 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"
#include "rb_tree_42.h"
#include "types.h"

#include <stdlib.h>
#include <stdio.h>
int     cmp_room(void *data1, void *data2)
{
    t_room *room1;
    t_room *room2;
    
    room1 = (t_room *)data1;
    room2 = (t_room *)data2;
    return (ft_strcmp(room1->name, room2->name));
}

t_room *room_search(t_rb_tree *root, char *name)
{
    t_rb_tree *node;
    t_room *tmp;

    tmp = (t_room *)malloc(sizeof(t_room));
    tmp->name = ft_strdup(name);
    if ((node = rb_tree_search(root, (void *)tmp, &cmp_room)) == NULL) 
        return (NULL);
    if (cmp_room((void *)tmp, node->data) == 0)
        return ((t_room *)node->data);
    return (NULL);
}