/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 15:52:51 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/09 15:56:49 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

void free_graph(t_graph *graph)
{
    size_t index;

    if (graph == NULL)
        return ;
    if (graph->flow != NULL)
    {
        index = 0;
        while (index < graph->row)
        {
            if (graph->flow[index] != NULL)
                free(graph->flow[index]);
            ++index;
        }
        free(graph->flow);
    }
    free(graph);
}