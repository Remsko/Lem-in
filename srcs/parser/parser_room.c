/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 20:17:08 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/13 17:07:41 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "error_42.h"
#include "read_42.h"
#include "string_42.h"

#include "types.h"
#include "anthill.h"
#include "room.h"

static void    type_change(char *line, t_room_type *type)
{
    if (line != NULL && type != NULL)
    {
        if (ft_strequ(line, "##start"))
            *type = START;
        else if (ft_strequ(line, "##end"))
            *type = END;
    }
}

t_error *parser_room(t_rb_tree **root, t_map *map, t_anthill *anthill, char **line)
{
    t_error *err;
    int     ret;
    t_room_type type;

    err = NULL;
    type = BASIC;
    while ((ret = get_next_line(0, line)) == 1)
    {
        anthill_add(anthill, line);
        if (*line[0] == '#')
            type_change(*line, &type);
        else if (room_parse(root, map, *line, type))
            type = BASIC;
        else
            break ;
    }
    if (ret != 1)
    {
        if (ret == 0)
            ft_strdel(line);
        err = error_create("No rooms, no pipes: no paths.", NULL, 3);
    }
    return (err);
}