/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 21:33:08 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/01 16:45:42 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "write_42.h"

void	room_print(t_map *map)
{
	t_room	**rooms;
	size_t	index;

	if (map == NULL)
		return ;
	rooms = map->rooms;
	if (rooms == NULL)
		return ;
	index = 0;
	while (index < map->length)
	{
		if (rooms[index] != NULL && rooms[index]->name != NULL)
		{
			ft_putnbr((int)rooms[index]->self_index);
			ft_putstr(" : ");
			ft_putendl(rooms[index]->name);
		}
		++index;
	}
}
