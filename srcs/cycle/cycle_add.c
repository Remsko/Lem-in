/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:08:40 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/11 16:13:15 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "error_42.h"
#include "array_42.h"

void	cycle_add(t_cycle *cycle, char c)
{
	array_append((t_array *)cycle, (void *)&c);
	if (cycle->line == NULL)
		error_malloc_exit("cycle_add");
}
