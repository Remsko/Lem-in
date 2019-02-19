/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:19:01 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/18 21:34:55 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"
#include "rb_tree_42.h"
#include "types.h"

int     cmp_room(void *data1, void *data2)
{
    t_room *room1;
    t_room *room2;
    
    room1 = (t_room *)data1;
    room2 = (t_room *)data2;
    return (ft_strcmp(room1->name, room2->name));
}

bool    room_insert(t_rb_tree **root, t_room *room)
{
    return (rb_tree_insert(root, (void *)room, &cmp_room));
}