/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:28:52 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/19 16:33:58 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "array_42.h"
#include "types.h"

void    cycle_print(t_cycle *cycle)
{
    array_append((t_array *)cycle, (void *)"\n");
    write(1, (const void *)cycle->line, cycle->length);
}