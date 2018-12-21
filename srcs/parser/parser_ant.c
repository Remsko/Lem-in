/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_ant.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:26:55 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/21 20:21:20 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "string_42.h"
#include "read_42.h"
#include "conv_42.h"
#include "error_42.h"

#include "types.h"
#include "anthill.h"

t_error	*parser_ant(t_anthill *anthill, char **line, int *ants)
{
	if (get_next_line(0, line) != 1)
		return (error_create("Problem with anthill: file is empty.", NULL, 0));
	while (*line[0] == '#')
	{
		anthill_add(anthill, line);
		if (get_next_line(0, line) != 1)
			return (error_create("No number of ants.", NULL, 1));
	}
	if (ft_isatoi(*line, ants) == false)
	{
		ft_strdel(line);
		return (error_create("Wrong number of ants: value must be at least an int.", NULL, 2));
	}
	anthill_add(anthill, line);
	return (NULL);
}
