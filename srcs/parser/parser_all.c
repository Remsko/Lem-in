/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:24:09 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/18 21:19:49 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "write_42.h"
#include "array_42.h"
#include "error_42.h"
#include "parser.h"
#include "graph.h"
#include "adjacency.h"

t_error *parser_all(t_env *e)
{
    t_error *err;
    char    *line;

    if ((err = parser_ant(e, &line)) != NULL)
        return (err);
    if ((err = parser_room(e, &line)) != NULL)
        return (err);
    if ((e->graph = graph_new(e->map->length)) == NULL)
        return (error_create("Graph malloc failed.", NULL, 9));
    if ((err = parser_pipe(e, &line)) != NULL)
        return (err);
    if ((e->adj = new_adjacency(e->map->rooms, e->graph)) == NULL)
        return (error_create("Adjacency-list malloc failed.", NULL, 10));
    return (NULL);
}