/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 18:00:20 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/18 21:36:44 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "room.h"
#include "types.h"

void    garbage_rooms(void *ptr, size_t size)
{
    t_room **rooms;
    size_t  i;

    i = 0;
    rooms = (t_room **)ptr;
    if (rooms != NULL)
    {
        while (i < size)
        {
            room_free(rooms[i]);
            ++i;
        }
        free(rooms);
    }
}
