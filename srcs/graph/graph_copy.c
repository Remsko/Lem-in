/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 12:43:03 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/01 15:19:25 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "graph.h"
#include "memory_42.h"

t_graph	*graph_copy(t_graph *graph)
{
	t_graph	*copy;
	size_t	index;

	index = 0;
	copy = graph_new(graph->size);
	while (index < graph->size)
	{
		ft_memcpy(copy->edge[index], graph->edge[index],
			sizeof(t_edge) * graph->size);
		++index;
	}
	return (copy);
}
