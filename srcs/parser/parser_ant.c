/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_ant.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:26:55 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/07 18:33:20 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "read_42.h"
#include "lem_in.h"

bool    parser_ant(t_anthill *anthill, char **line, int *ants)
{
	if (get_next_line(0, line) != 1)
	{
		ft_putstr("Problem with anthill: file doesn't exist or path is wrong.\n");
		return (false);
	}
	while (*line[0] == '#')
	{
		add_line(anthill, line);
		if (get_next_line(0, line) != 1)
		{
			ft_putstr("No number of ants.\n");
			return (false);
		}
	}
	if (ft_isatoi(*line, ants) == false)
	{
		ft_putstr("Wrong number of ants: value must be an int.\n");
		ft_strdel(line);
	}
	add_line(anthill, line);   
	return (true);
}
