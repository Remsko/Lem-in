/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_graph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:09:37 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/19 10:43:30 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "write_42.h"
#include "types.h"

void    print_graph(t_graph *graph)
{
    size_t x;
    size_t y;

    y = 0;
    if (graph == NULL)
        return (ft_putstr("GRAPH IS EMPTY\n"));
    if (graph->flow == NULL)
        return (ft_putstr("FLOW IS EMPTY\n"));
    while (y < graph->size)
    {
        x = 0;
        while (x < graph->size)
        {
            ft_putnbr(graph->flow[y][x]);
            ++x;
        }
        ft_putchar('\n');
        ++y;
    }
}