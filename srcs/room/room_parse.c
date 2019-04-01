/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 13:35:47 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/01 16:43:37 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "types.h"
#include "room.h"
#include "string_42.h"
#include "write_42.h"
#include "free_42.h"

void	set_special_room(t_env *e, t_room *room)
{
	if (room->type == START)
		e->start = room->self_index;
	else if (room->type == END)
		e->end = room->self_index;
}

bool	room_parse(t_env *e, char *line, t_room_type type)
{
	t_room	*room;
	char	**split;
	size_t	length;
	bool	pass;

	split = ft_strsplit(line, ' ');
	length = ft_splitlen(split);
	if ((pass = room_check(split, length)))
	{
		if ((room = room_create(split[0], type)) != NULL)
		{
			if ((pass = room_insert(&e->root, room)))
			{
				room_add(e->map, room);
				set_special_room(e, room);
			}
			else
				room_free(room);
		}
		else
			pass = false;
	}
	free_2d_char(split, length);
	return (pass);
}
