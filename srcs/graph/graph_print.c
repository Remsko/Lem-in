/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:09:37 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/20 21:17:21 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "write_42.h"
#include "types.h"

void    graph_print(t_graph *graph)
{
    size_t x;
    size_t y;

    y = 0;
    if (graph == NULL)
        return (ft_putstr("GRAPH IS EMPTY\n"));
    if (graph->edge == NULL)
        return (ft_putstr("FLOW IS EMPTY\n"));
    ft_putstr("Flow:\n");
    while (y < graph->size)
    {
        x = 0;
        while (x < graph->size)
        {
            ft_putnbr(graph->edge[y][x].flow);
            ++x;
        }
        ft_putchar('\n');
        ++y;
    }
    ft_putstr("\nCapacity:\n");
    y = 0;
    while (y < graph->size)
    {
        x = 0;
        while (x < graph->size)
        {
            ft_putnbr(graph->edge[y][x].capacity);
            ++x;
        }
        ft_putchar('\n');
        ++y;
    }
}