/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_graph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 15:37:38 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/09 16:00:00 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

t_graph *new_graph(size_t size)
{
    t_graph *graph;
    size_t index;

    if ((graph = (t_graph *)malloc(sizeof(t_graph))) == NULL)
        return (NULL);
    graph->row = size;
    if ((graph->flow = (int **)memalloc(sizeof(int *) * size)) == NULL)
    {
        free(graph);
        return (NULL);
    }
    index = 0;
    while (index < size)
    {
        if ((graph->flow[index] = (int *)memalloc(sizeof(int) * size)) == NULL)
        {
            free_graph(graph);
            return (NULL);
        }
        ++index;
    }
    return (graph);
}