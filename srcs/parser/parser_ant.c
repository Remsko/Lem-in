/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_ant.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:26:55 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/01 15:40:43 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "types.h"
#include "anthill.h"
#include "string_42.h"
#include "read_42.h"
#include "conv_42.h"
#include "error_42.h"

t_error	*parser_ant(t_env *e, char **line)
{
	t_error	*err;
	int		ret;

	err = NULL;
	while ((ret = get_next_line(0, line)) == 1)
	{
		anthill_add(e->anthill, line);
		if (*line[0] != '#')
			break ;
		if (ft_strnequ(*line, "##", 2))
			return (error_create("Command before number of ants.", NULL, 0));
	}
	if (ret != 1)
	{
		if (ret == 0)
			ft_strdel(line);
		err = error_create("File doesn't exist or is empty.", NULL, 1);
	}
	else if (ft_isatoi(*line, &e->ants) == false || e->ants < 1)
		err = error_create("Wrong number of ants.", NULL, 2);
	return (err);
}
