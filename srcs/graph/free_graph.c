/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 15:52:51 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/19 10:42:50 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "types.h"

void free_graph(t_graph *graph)
{
    size_t index;

    if (graph == NULL)
        return ;
    if (graph->flow != NULL)
    {
        index = 0;
        while (index < graph->size)
        {
            if (graph->flow[index] != NULL)
                free(graph->flow[index]);
            ++index;
        }
        free(graph->flow);
    }
    free(graph);
}