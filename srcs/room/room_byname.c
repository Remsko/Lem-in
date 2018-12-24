/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_byname.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 16:22:10 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/24 16:36:32 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "room.h"

t_room *room_byname(t_map *map, char *name)
{
    t_room **rooms;
    size_t index;

    if (map == NULL || name == NULL)
        return (NULL);
    rooms = map->rooms;
    if (rooms == NULL)
        return (NULL);
    if ((index = room_index(map, name)) == (size_t)-1)
        return (NULL);
    return (rooms[index]);
}