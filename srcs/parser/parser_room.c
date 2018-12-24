/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 20:17:08 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/24 12:24:49 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_42.h"
#include "read_42.h"
#include "string_42.h"
#include "conv_42.h"
#include "free_42.h"

#include "types.h"
#include "anthill.h"
#include "room.h"

void    type_change(char **line, t_room_type *type)
{
    if (ft_strequ(*line, "##start"))
        *type = START;
    else if (ft_strequ(*line, "##end"))
        *type = END;
}

t_error *room_parse(t_map *map, char **line, t_room_type type)
{
    t_room  *room;
    t_error *err;
    char    **split;
    size_t  length;

    split = ft_strsplit(*line, ' ');
    length = ft_splitlen(split);
    err = room_check(split, length);
    if (err == NULL && room_index(map, split[0]) == (size_t)-1)
    {
        room = room_create(split[0], type);
        if (room != NULL)
            room_add(map, &room);
    }
    free_2d_char(split, length);
    return (err);
}

t_error *parser_room(t_map *map, t_anthill *anthill, char **line)
{
    t_error *err;
    t_room_type type;

    type = BASIC;
    while (1)
    {
        if (get_next_line(0, line) != 1)
        {
            ft_strdel(line);
            return (error_create("No pipes, no paths.", NULL, 3));
        }
        anthill_add(anthill, line);
        if (*line[0] == '#')
            type_change(line, &type);
        else if ((err = room_parse(map, line, type)) == NULL)
            type = BASIC;
        else
            break ;
    }
    return (NULL);
}