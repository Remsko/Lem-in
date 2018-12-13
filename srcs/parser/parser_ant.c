/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_ant.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:26:55 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/13 17:47:10 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "string_42.h"
#include "read_42.h"
#include "write_42.h"
#include "conv_42.h"

#include "parser.h"
#include "anthill.h"

bool    parser_ant(t_anthill *anthill, char **line, int *ants)
{
	if (get_next_line(0, line) != 1)
	{
		ft_putstr("Problem with anthill: file is empty.\n");
		return (false);
	}
	while (*line[0] == '#')
	{
		anthill_add(anthill, line);
		if (get_next_line(0, line) != 1)
		{
			ft_putstr("No number of ants.\n");
			return (false);
		}
	}
	if (ft_isatoi(*line, ants) == false)
	{
		ft_putstr("Wrong number of ants: value must be at least an int.\n");
		ft_strdel(line);
		return (false);
	}
	anthill_add(anthill, line);
	return (true);
}
