/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 12:27:49 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/09 23:50:40 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_42.h"
#include "read_42.h"
#include "string_42.h"
#include "free_42.h"
#include "memory_42.h"
#include "write_42.h"

#include "types.h"
#include "anthill.h"
#include "room.h"

void pipe_add(t_graph *graph, size_t room1_index, size_t room2_index)
{
    if (room1_index == (size_t)-1 || room2_index == (size_t)-1)
        return (ft_putstr("Warning: pipe_add fails.\n"));
    graph->flow[room1_index][room2_index] = 1;
    graph->flow[room2_index][room1_index] = 1;
}

bool    pipe_check(char **split, size_t length)
{
    if (length != 2)
        return (false);
    else if (ft_strequ(split[0], split[1]))
        return (false);
    return (true);
}

bool    pipe_parse(t_graph *graph, t_map *map, char **line)
{
    char        **split;
    size_t      length;
    bool        pass;

    split = ft_strsplit(*line, '-');
    length = ft_splitlen(split);
    if ((pass = pipe_check(split, length)))
        pipe_add(graph, room_index(map, split[0]), room_index(map, split[1]));
    free_2d_char(split, length);
    return (pass);
}

t_error *parser_pipe(t_graph *graph, t_map *map, t_anthill *anthill, char **line)
{
    int ret;

    if (pipe_parse(graph, map, line) == false)
        return (error_create("No pipes: no solution.", NULL, 3));
    while ((ret = get_next_line(0, line)) == 1)
    {
        anthill_add(anthill, line);
        if (*line[0] == '#')
            continue ;
        else if (pipe_parse(graph, map , line) == false)
            break ;
    }
    if (ret == 0)
        ft_strdel(line);
    return (NULL);
}