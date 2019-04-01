/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 12:27:49 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/01 10:38:37 by rpinoit          ###   ########.fr       */
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


#include <stdio.h>
bool pipe_add(t_graph *graph, t_room *room1, t_room *room2)
{
    if (room1 == NULL || room2 == NULL)
        return (false);
    graph->edge[room1->self_index][room2->self_index].capacity = 1;
    graph->edge[room2->self_index][room1->self_index].capacity = 1;
    room1->pipes += 1;
    room2->pipes += 1;
    return (true);
}

bool    pipe_check(char **split, size_t length)
{
    if (length != 2)
        return (false);
    else if (ft_strequ(split[0], split[1]))
        return (false);
    return (true);
}

bool    pipe_parse(t_rb_tree *root, t_graph *graph, t_map *map, char **line)
{
    char        **split;
    size_t      length;
    bool        pass;

    (void)root;
    (void)graph;
    (void)map;
    split = ft_strsplit(*line, '-');
    length = ft_splitlen(split);
    if ((pass = pipe_check(split, length)))
    {
        pass = pipe_add(graph, room_search(root, split[0]), room_search(root, split[1]));
    }
    free_2d_char(split, length);
    return (pass);
}

t_error *parser_pipe(t_env *e, char **line)
{
    int ret;

    if (pipe_parse(e->root, e->graph, e->map, line) == false)
        return (error_create("No pipes: no solution.", NULL, 3));
    while ((ret = get_next_line(0, line)) == 1)
    {
        anthill_add(e->anthill, line);
        if (*line[0] == '#')
            continue ;
        else if (pipe_parse(e->root, e->graph, e->map , line) == false)
            break ;
    }
    if (ret == 0)
        ft_strdel(line);
    return (NULL);
}