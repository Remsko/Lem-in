/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 15:52:51 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/20 20:05:51 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "types.h"

void graph_free(t_graph *graph)
{
    size_t index;

    if (graph == NULL)
        return ;
    if (graph->edge != NULL)
    {
        index = 0;
        while (index < graph->size)
        {
            if (graph->edge[index] != NULL)
                free(graph->edge[index]);
            ++index;
        }
        free(graph->edge);
    }
    free(graph);
}