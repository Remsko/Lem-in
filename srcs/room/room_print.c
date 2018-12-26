/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 21:33:08 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/25 14:54:07 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "write_42.h"

#include "types.h"

void    room_print(t_map *map)
{
    t_room **rooms;
    size_t  index;

    if (map == NULL)
        return ;
    rooms = map->rooms;
    if (rooms == NULL)
        return ;
    index = 0;
    while (index < map->length)
    {
        if (rooms[index] != NULL && rooms[index]->name != NULL)
            ft_putendl(rooms[index]->name);
        ++index;
    }
}