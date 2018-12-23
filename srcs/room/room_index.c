/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 12:27:25 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/23 14:56:10 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

#include "types.h"

size_t  room_index(t_map *map, char *search)
{
    t_room **rooms;
    size_t index;

    index = 0;
    if (map != NULL)
    {
        rooms = map->rooms;
        if (rooms != NULL)
        {
            while (index < map->length)
            {
                if (rooms[index] != NULL && rooms[index]->name != NULL
                    && ft_strequ(rooms[index]->name, search))
                    return (index);
                ++index;
            }
        }
    }
    return ((size_t)-1);
}