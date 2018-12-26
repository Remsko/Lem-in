/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_ant.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:26:55 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/26 11:47:40 by rpinoit          ###   ########.fr       */
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
	t_error	*err;
	int		ret;

	err = NULL;
    while ((ret = get_next_line(0, line)) == 1)
	{
		anthill_add(anthill, line);
		if (*line[0] != '#')
			break ;
	}
	if (ret != 1)
	{
		if (ret == 0)
			ft_strdel(line);
		err = error_create("File doesn't exist or is empty.", NULL, 1);
	}
	else if (ft_isatoi(*line, ants) == false)
		err = error_create("Wrong number of ants.", NULL, 2);
	return (err);
}
