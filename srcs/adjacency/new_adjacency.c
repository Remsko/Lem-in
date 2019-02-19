/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_adjacency.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:13:25 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/19 10:52:58 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "memory_42.h"
#include "types.h"
#include "adjacency.h"

t_adjacency *new_adjacency(t_room **rooms, t_graph *graph)
{
    t_adjacency *new;
    size_t x;
    size_t y;
    size_t link;

    if ((new = (t_adjacency *)ft_memalloc(sizeof(t_adjacency) * graph->size)) == NULL)
        return (NULL);
    y = 0;
    while (y < graph->size)
    {
        if ((new[y].list = (unsigned int *)malloc(sizeof(int) * rooms[y]->pipes)) == NULL)
        {
            free_adjacency(new, graph->size);
            return (NULL);
        }
        new[y].length = rooms[y]->pipes;
        x = 0;
        link = 0;
        while (x < graph->size)
        {
            if (graph->flow[y][x] > 0)
            {
                new[y].list[link] = (unsigned int)x;
                ++link;
            }
            ++x;
        }
        ++y;
    }
    return (new);
}