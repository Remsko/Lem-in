/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 18:00:20 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/01 14:57:01 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "types.h"
#include "room.h"

void	garbage_rooms(void *ptr, size_t size)
{
	t_room **rooms;
	size_t i;

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
