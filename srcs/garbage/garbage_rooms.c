/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 18:00:20 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/23 21:43:57 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
            if (rooms[i] != NULL)
            {
                if (rooms[i]->name != NULL)
                    free(rooms[i]->name);
                free(rooms[i]);
            }
            ++i;
        }
        free(rooms);
    }
}
