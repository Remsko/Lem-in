/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjacency_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:13:25 by rpinoit           #+#    #+#             */
/*   Updated: 2019/10/18 14:30:45 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "types.h"
#include "adjacency.h"
#include "memory_42.h"

static void	list_link(t_graph *graph, t_adjacency *new, size_t y)
{
	size_t x;
	size_t link;

	x = 0;
	link = 0;
	while (x < graph->size)
	{
		if (graph->edge[y][x].capacity > 0)
		{
			new[y].list[link] = x;
			++link;
		}
		++x;
	}
}

t_adjacency	*adjacency_new(t_room **rooms, t_graph *graph)
{
	t_adjacency	*new;
	size_t		y;

	if ((new = (t_adjacency *)ft_memalloc(sizeof(t_adjacency)
				* graph->size)) == NULL)
		return (NULL);
	y = 0;
	while (y < graph->size)
	{
		if ((new[y].list = (size_t *)ft_memalloc(sizeof(size_t)
					* rooms[y]->pipes)) == NULL)
		{
			adjacency_free(new, graph->size);
			return (NULL);
		}
		new[y].length = rooms[y]->pipes;
		list_link(graph, new, y);
		++y;
	}
	return (new);
}
