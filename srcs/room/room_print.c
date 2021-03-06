/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 21:33:08 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/19 10:49:56 by rpinoit          ###   ########.fr       */
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
        {
            ft_putnbr((int)rooms[index]->self_index);
            ft_putstr(" : ");
            ft_putendl(rooms[index]->name);
        }
        ++index;
    }
}