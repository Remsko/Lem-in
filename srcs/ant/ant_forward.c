/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_forward.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 22:22:32 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/11 17:36:43 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "cycle.h"

void	ant_forward(t_map *map, t_ant *ant, t_cycle *cycle)
{
	char	*name;
	size_t	index;

	++ant->index;
	index = ant->path->list[ant->index];
	name = map->rooms[index]->name;
	cycle_pattern_add(cycle, name, ant->id);
}
