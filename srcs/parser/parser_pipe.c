/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 12:27:49 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/24 14:45:14 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_42.h"
#include "read_42.h"
#include "string_42.h"
#include "free_42.h"

#include "types.h"
#include "anthill.h"

t_error     *pipe_check(char **split, size_t length)
{
    if (length != 2)
        return (error_create("Wrong pipe format.", NULL, 6));
    else if (ft_strequ(split[0], split[1]))
        return (error_create("Pipe connect the same room.", NULL, 7));
    return (NULL);
}

t_error     *pipe_parse(t_map *map, char **line)
{
    t_error     *err;
    char        **split;
    size_t      length;

    (void)map;
    split = ft_strsplit(*line, '-');
    length = ft_splitlen(split);
    err = pipe_check(split, length);
    //if (err == NULL)
    //    add_pipe;
    free_2d_char(split, length);
    return (err);
}

t_error     *parser_pipe(t_map *map, t_anthill *anthill, char **line)
{
    t_error *err;

    err = pipe_parse(map, line);
    if (err != NULL)
        return (err);
    while (get_next_line(0, line) == 1)
    {
        anthill_add(anthill, line);
        if (*line[0] == '#')
            continue ;
        err = pipe_parse(map , line);
        if (err != NULL)
            return (err);
    }
    ft_strdel(line);
    return (NULL);
}