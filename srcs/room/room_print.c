/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 21:33:08 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/23 21:41:28 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "write_42.h"

#include "types.h"

void    room_print(t_map *map)
{
    t_room **rooms;
    size_t  index;

    rooms = map->rooms;
    index = 0;
    while (index < map->length)
    {
        if (rooms[index] != NULL && rooms[index]->name != NULL)
            ft_putendl(rooms[index]->name);
        ++index;
    }
}