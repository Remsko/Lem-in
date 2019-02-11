/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_bytype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:43:49 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/11 12:51:52 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

size_t  room_bytype(t_map *map, t_room_type type)
{
    t_room **rooms;
    size_t index;

    if (map != NULL)
    {
        rooms = map->rooms;
        if (rooms != NULL)
        {
            index = map->length - 1;
            while (index != (size_t)-1)
            {
                if (rooms[index] != NULL && rooms[index]->type == type)
                    return (index);
                --index;
            }
        }
    }
    return ((size_t)-1);
}