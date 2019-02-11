/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_graph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:09:37 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/11 13:16:46 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "write_42.h"
#include "types.h"

void    print_graph(t_graph *graph)
{
    int x;
    int y;

    y = 0;
    if (graph == NULL)
        return (ft_putstr("GRAPH IS EMPTY\n"));
    if (graph->flow == NULL)
        return (ft_putstr("FLOW IS EMPTY\n"));
    while (y < graph->row)
    {
        x = 0;
        while (x < graph->row)
        {
            ft_putnbr(graph->flow[y][x]);
            ++x;
        }
        ft_putchar('\n');
        ++y;
    }
}