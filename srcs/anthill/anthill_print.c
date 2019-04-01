/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:54:28 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/01 14:52:17 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "write_42.h"

void	anthill_print(t_anthill *anthill)
{
	size_t i;

	i = 0;
	while (i < anthill->length)
	{
		if (anthill->lines[i] != NULL)
			ft_putendl(anthill->lines[i]);
		++i;
	}
}
