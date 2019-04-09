/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_arrived.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 22:23:12 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/04 22:23:25 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "types.h"

bool ant_arrived(t_map *map, t_ant *ant)
{
	size_t index;

	index = ant->path->list[ant->index];
	if (map->rooms[index]->type == END)
		return (true);
	return (false);
}