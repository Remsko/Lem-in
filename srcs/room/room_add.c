/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 12:29:54 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/20 21:39:19 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"
#include "error_42.h"

#include "types.h"

void    room_add(t_map *map, t_room *room)
{
    static unsigned int index = 0;

    room->self_index = index;
    room->in = index;
    room->out = index + 1;
    array_append((t_array *)map, (void *)&room);
    if (map->rooms == NULL)
        error_malloc("room_add");
    index += 2;
}