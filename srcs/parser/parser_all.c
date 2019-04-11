/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:24:09 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/11 16:08:49 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "graph.h"
#include "adjacency.h"
#include "error_42.h"

t_error	*parser_all(t_env *e)
{
	t_error	*err;
	char	*line;

	if ((err = parser_ant(e, &line)) != NULL)
		return (err);
	if ((err = parser_room(e, &line)) != NULL)
		return (err);
	if (e->start == (size_t)-1 || e->end == (size_t)-1)
		return (parser_error("Both ##start and ##end command are needed."));
	if ((e->graph = graph_new(e->map->length)) == NULL)
		return (parser_error("Graph malloc failed."));
	if ((err = parser_pipe(e, &line)) != NULL)
		return (err);
	if ((e->adj = adjacency_new(e->map->rooms, e->graph)) == NULL)
		return (parser_error("Adjacency-list malloc failed."));
	return (NULL);
}
