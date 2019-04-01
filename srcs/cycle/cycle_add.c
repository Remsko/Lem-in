/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:08:40 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/01 15:17:07 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "error_42.h"
#include "array_42.h"

void	cycle_add(t_cycle *cycle, char c)
{
	array_append((t_array *)cycle, (void *)&c);
	if (cycle->line == NULL)
		error_malloc("cycle_add");
}
