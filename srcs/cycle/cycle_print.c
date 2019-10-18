/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:28:52 by rpinoit           #+#    #+#             */
/*   Updated: 2019/10/18 14:29:06 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "types.h"
#include "array_42.h"

void	cycle_print(t_cycle *cycle)
{
	write(1, (const void *)cycle->line, cycle->length);
}
