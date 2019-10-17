/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:09:37 by rpinoit           #+#    #+#             */
/*   Updated: 2019/10/17 21:05:56 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "write_42.h"

static void print_capacity(t_graph *graph)
{
	size_t x;
	size_t y;

	y = 0;
	while (y < graph->size)
	{
		x = 0;
		while (x < graph->size)
		{
			if (graph->edge[y][x].capacity >= 2)
				ft_putnbr(graph->edge[y][x].capacity);
			++x;
		}
		//ft_putchar('\n');
		++y;
	}
}

static void print_flow(t_graph *graph)
{
	size_t x;
	size_t y;

	y = 0;
	while (y < graph->size)
	{
		x = 0;
		while (x < graph->size)
		{
			if (graph->edge[y][x].flow >= 2)
				ft_putnbr(graph->edge[y][x].flow);
			++x;
		}
		//ft_putchar('\n');
		++y;
	}
}

void graph_print(t_graph *graph)
{
	if (graph == NULL)
		return (ft_putstr("Graph is empty.\n"));
	if (graph->edge == NULL)
		return (ft_putstr("Edge is empty.\n"));
	ft_putstr("Flow:\n");
	print_flow(graph);
	ft_putstr("\n");
	ft_putstr("Capacity:\n");
	print_capacity(graph);
}
