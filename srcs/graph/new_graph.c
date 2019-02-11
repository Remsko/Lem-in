/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_graph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 15:37:38 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/11 13:18:15 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "graph.h"
#include "types.h"
#include "memory_42.h"

t_graph *new_graph(size_t size)
{
    t_graph *graph;
    size_t index;

    if ((graph = (t_graph *)malloc(sizeof(t_graph))) == NULL)
        return (NULL);
    graph->row = (int)size;
    graph->flow = (int **)ft_memalloc(sizeof(int *) * size);
    index = 0;
    while (index < size)
    {
        graph->flow[index] = (int *)ft_memalloc(sizeof(int) * size);
        ++index;
    }
    return (graph);
}