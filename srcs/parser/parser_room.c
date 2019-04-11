/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 20:17:08 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/11 16:12:33 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "types.h"
#include "anthill.h"
#include "room.h"
#include "parser.h"
#include "error_42.h"
#include "read_42.h"
#include "string_42.h"

static void	type_change(char *line, t_room_type *type)
{
	if (ft_strequ(line, "##start"))
		*type = START;
	else if (ft_strequ(line, "##end"))
		*type = END;
}

static bool	type_check(t_env *e, t_room_type type)
{
	if (e->start != (size_t)-1 && type == START)
		return (false);
	else if (e->end != (size_t)-1 && type == END)
		return (false);
	return (true);
}

t_error		*parser_room(t_env *e, char **line)
{
	int			ret;
	t_room_type	type;

	type = BASIC;
	while ((ret = get_next_line(0, line)) == 1)
	{
		anthill_add(e->anthill, line);
		if (*line[0] == '#')
		{
			type_change(*line, &type);
			if (type_check(e, type) == false)
				return (parser_error("Doublon start or end."));
		}
		else if (*line[0] != 'L' && room_parse(e, *line, type))
			type = BASIC;
		else
			break ;
	}
	if (ret != 1)
	{
		if (ret == 0)
			ft_strdel(line);
		return (parser_error("No rooms, no pipes: no solution."));
	}
	return (NULL);
}
