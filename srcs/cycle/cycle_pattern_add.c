/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_pattern_add.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:25:41 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/01 19:25:46 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "types.h"
#include "cycle.h"
#include "array_42.h"
#include "conv_42.h"
#include "error_42.h"

void	cycle_pattern_add(t_cycle *cycle, char *name, int ant)
{
	char	*n;
	int		index;

	if (cycle->line[cycle->length - 1] != '\n')
		cycle_add(cycle, ' ');
	cycle_add(cycle, 'L');
	if ((n = ft_itoa(ant)) == NULL)
		error_malloc("cycle_pattern_add");
	index = 0;
	while (n[index] != '\0')
	{
		cycle_add(cycle, n[index]);
		++index;
	}
	free(n);
	cycle_add(cycle, '-');
	index = 0;
	while (name[index] != '\0')
	{
		cycle_add(cycle, name[index]);
		++index;
	}
}
