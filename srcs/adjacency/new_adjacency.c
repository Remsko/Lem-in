/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_adjacency.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:13:25 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/19 09:44:19 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "memory_42.h"
#include "types.h"
#include "adjacency.h"

t_adjacency *new_adjacency(t_room **rooms, t_graph *graph)
{
    t_adjacency *new;
    int x;
    int y;
    int link;

    if ((new = (t_adjacency *)ft_memalloc(sizeof(t_adjacency) * (size_t)graph->row)) == NULL)
        return (NULL);
    y = 0;
    while (y < graph->row)
    {
        if ((new[y].list = (int *)malloc(sizeof(int) * (size_t)rooms[y]->pipes)) == NULL)
        {
            free_adjacency(new, graph->row);
            return (NULL);
        }
        new[y].length = rooms[y]->pipes;
        x = 0;
        link = 0;
        while (x < graph->row)
        {
            if (graph->flow[y][x] > 0)
            {
                new[y].list[link] = x;
                ++link;
            }
            ++x;
        }
        ++y;
    }
    return (new);
}