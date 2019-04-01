/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 15:37:38 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/01 15:24:52 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "graph.h"
#include "types.h"
#include "memory_42.h"

t_graph	*graph_new(size_t size)
{
	t_graph	*graph;
	size_t	index;

	if ((graph = (t_graph *)malloc(sizeof(t_graph))) == NULL)
		return (NULL);
	graph->size = size;
	if ((graph->edge = (t_edge **)ft_memalloc(sizeof(t_edge *) * size)) == NULL)
	{
		graph_free(graph);
		return (NULL);
	}
	index = 0;
	while (index < size)
	{
		if ((graph->edge[index] = (t_edge *)ft_memalloc(sizeof(t_edge)
					* size)) == NULL)
		{
			graph_free(graph);
			return (NULL);
		}
		++index;
	}
	return (graph);
}
