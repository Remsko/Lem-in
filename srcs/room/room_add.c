/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 12:29:54 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/11 16:13:39 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "array_42.h"
#include "error_42.h"

void	room_add(t_map *map, t_room *room)
{
	array_append((t_array *)map, (void *)&room);
	if (map->rooms == NULL)
		error_malloc_exit("room_add");
	room->self_index = map->length - 1;
}
