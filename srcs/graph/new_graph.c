/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_graph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 15:37:38 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/20 21:45:50 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "graph.h"
#include "types.h"
#include "memory_42.h"

#include <stdio.h>
t_graph *new_graph(size_t size)
{
    t_graph *graph;
    size_t index;

    if ((graph = (t_graph *)malloc(sizeof(t_graph))) == NULL)
        return (NULL);
    graph->size = size * 2;
    printf("%zu\n", graph->size);
    if ((graph->edge = (t_edge **)ft_memalloc(sizeof(t_edge *) * graph->size)) == NULL)
    {
        free_graph(graph);
        return (NULL);
    }
    index = 0;
    while (index < graph->size)
    {
        if ((graph->edge[index] = (t_edge *)ft_memalloc(sizeof(t_edge) * graph->size)) == NULL)
        {
            free_graph(graph);
            return (NULL);
        }
        ++index;
    }
    print_graph(graph);
    return (graph);
}