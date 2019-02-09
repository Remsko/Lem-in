/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 12:27:49 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/09 18:06:13 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_42.h"
#include "read_42.h"
#include "string_42.h"
#include "free_42.h"
#include "memory_42.h"

#include "types.h"
#include "anthill.h"
#include "room.h"

#include "write_42.h"

/*
#include <stdio.h>
void pipe_print(t_map *map)
{
    if (map == NULL)
        return ;
    t_room **rooms = map->rooms;
    if (rooms == NULL)
        return ;
    size_t index = 0;
    while (index < map->length)
    {
        printf("name = %s ; index = %zu ; pipes =", rooms[index]->name, rooms[index]->self_index);
        for (size_t i = 0; i < rooms[index]->pipes.length; i++)
        {
            printf(" %zu", rooms[index]->pipes.tab[i]);
        }
        printf("\n");
        ++index;
    }
}

void index_add(t_index *pipes, size_t index)
{
    pipes->tab = ft_realloc(pipes->tab,
        sizeof(size_t) * (pipes->length + 1),
        sizeof(size_t) * pipes->length);
    if (pipes->tab == NULL)
        return (ft_putstr("Warning: index_add fails.\n"));
    pipes->tab[pipes->length] = index;
    pipes->length += 1;
}

void    pipe_add(t_room *room1, t_room *room2)
{
    if (room1 == NULL || room2 == NULL)
        return (ft_putstr("Warning: pipe_add fails.\n"));
    index_add(&room1->pipes, room2->self_index);
    index_add(&room2->pipes, room1->self_index);
}
*/

//
// graph->flow[room1_index][room2_index] = 1
// graph->flow[room2_index][room1_index] = 1
//

bool    pipe_check(char **split, size_t length)
{
    if (length != 2)
        return (false);
    else if (ft_strequ(split[0], split[1]))
        return (false);
    return (true);
}

bool    pipe_parse(t_map *map, char **line)
{
    char        **split;
    size_t      length;
    bool        pass;

    split = ft_strsplit(*line, '-');
    length = ft_splitlen(split);
    if ((pass = pipe_check(split, length)))
        pipe_add(room_byname(map, split[0]), room_byname(map, split[1]));
    free_2d_char(split, length);
    return (pass);
}

t_error *parser_pipe(t_map *map, t_anthill *anthill, char **line)
{
    int ret;

    if (pipe_parse(map, line) == false)
        return (error_create("No pipes: no solution.", NULL, 3));
    while ((ret = get_next_line(0, line)) == 1)
    {
        anthill_add(anthill, line);
        if (*line[0] == '#')
            continue ;
        else if (pipe_parse(map , line) == false)
            break ;
    }
    if (ret == 0)
        ft_strdel(line);
    return (NULL);
}