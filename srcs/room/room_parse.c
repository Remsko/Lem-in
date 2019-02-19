/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 13:35:47 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/18 21:34:38 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "string_42.h"
#include "write_42.h"
#include "free_42.h"
#include "rb_tree_42.h"

#include "room.h"
#include "types.h"

bool    room_parse(t_env *e, char *line, t_room_type type)
{
    t_room  *room;
    char    **split;
    size_t  length;
    bool    pass;

    split = ft_strsplit(line, ' ');
    length = ft_splitlen(split);
    if ((pass = room_check(split, length)))
    {
        if ((room = room_create(split[0], type)) != NULL)
        {
            if (room_insert(&e->root, room))
            {
                room_add(e->map, room);
                if (room->type == START)
                    e->start = room->self_index;
                else if (room->type == END)
                    e->end = room->self_index;
            }
            else
            {
                room_free(room);
                ft_putstr("Warning: room already exist.\n");
            }
        }
        else
            ft_putstr("Warning: room creation fails.\n");
    }
    free_2d_char(split, length);
    return (pass);
}