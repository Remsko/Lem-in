/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:24:09 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/09 23:55:40 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "write_42.h"
#include "array_42.h"
#include "error_42.h"
#include "parser.h"
#include "graph.h"

t_error *parser_all(t_env *e)
{
    t_graph *graph;
    t_error *err;
    char    *line;

    if ((err = parser_ant(e->anthill, &line, &e->ants)) != NULL)
    {
        ft_putstr("Parsing finish while reading ants...\n");
        return (err);
    }
    if ((parser_room(e->map, e->anthill, &line)) != NULL)
    {
        ft_putstr("Parsing finish while reading rooms...\n");
        return (err);
    }
    if ((graph = new_graph(e->map->length)) == NULL)
        return (error_create("Graph malloc failed.", NULL, 9));
    if ((err = parser_pipe(graph, e->map, e->anthill, &line)) != NULL)
    {
        ft_putstr("Parsing finish while reading pipes...\n");
        return (err);
    }
    return (NULL);
}