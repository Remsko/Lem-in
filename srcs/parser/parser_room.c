/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 20:17:08 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/01 14:31:24 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "error_42.h"
#include "read_42.h"
#include "string_42.h"

#include "types.h"
#include "anthill.h"
#include "room.h"

static void type_change(char *line, t_room_type *type)
{
    if (ft_strequ(line, "##start"))
        *type = START;
    else if (ft_strequ(line, "##end"))
        *type = END;
}

t_error *parser_room(t_env *e, char **line)
{
    t_error *err;
    int     ret;
    t_room_type type;

    err = NULL;
    type = BASIC;
    while ((ret = get_next_line(0, line)) == 1 && err == NULL)
    {
        anthill_add(e->anthill, line);
        if (*line[0] == '#')
        {
            type_change(*line, &type);
            if (type == START && e->start != (size_t)-1)
                err = error_create("Start is in double.", NULL, 12);
            if (type == END && e->end != (size_t)-1)
                err = error_create("End is in double.", NULL, 13);
        }
        else if (*line[0] == 'L')
            err = error_create("Room can't start with a L.", NULL, 3);
        else if (room_parse(e, *line, type))
            type = BASIC;
        else
            break ;
    }
    if (ret != 1)
    {
        if (ret == 0)
            ft_strdel(line);
        err = error_create("No rooms, no pipes: no solution.", NULL, 3);
    }
    return (err);
}