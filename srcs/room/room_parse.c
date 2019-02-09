/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 13:35:47 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/26 14:34:06 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "string_42.h"
#include "write_42.h"
#include "free_42.h"

#include "room.h"
#include "types.h"

bool    room_parse(t_map *map, char *line, t_room_type type)
{
    t_room  *room;
    char    **split;
    size_t  length;
    bool    pass;

    split = ft_strsplit(line, ' ');
    length = ft_splitlen(split);
    if ((pass = room_check(split, length)))
    {
        if (room_index(map, split[0]) != (size_t)-1)
            ft_putstr("Warning: room already exist.\n");
        else if ((room = room_create(split[0], type)) != NULL)
            room_add(map, room);
        else
            ft_putstr("Warning: room_create fails.\n");
    }
    free_2d_char(split, length);
    return (pass);
}