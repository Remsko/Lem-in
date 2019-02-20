/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_adjacency.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:13:25 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/20 21:48:47 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "memory_42.h"
#include "types.h"
#include "adjacency.h"

#include "graph.h"
#include <stdio.h>
t_adjacency *new_adjacency(t_room **rooms, t_graph *graph)
{
    t_adjacency *new;
    size_t x;
    size_t y;
    size_t link;

    print_graph(graph);
    if ((new = (t_adjacency *)ft_memalloc(sizeof(t_adjacency) * graph->size)) == NULL)
        return (NULL);
    y = 0;
    while (y < graph->size / 2)
    {
        if ((new[y].list = (unsigned int *)malloc(sizeof(int) * rooms[y]->pipes)) == NULL)
        {
            free_adjacency(new, graph->size);
            return (NULL);
        }
        printf("poulet\n");
        new[y].length = rooms[y]->pipes;
        x = 0;
        link = 0;
        while (x < graph->size)
        {
            if (graph->edge[y][x].capacity > 0)
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