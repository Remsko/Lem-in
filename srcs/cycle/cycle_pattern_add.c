/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_pattern_add.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:25:41 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/19 16:32:59 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "error_42.h"
#include "conv_42.h"
#include "array_42.h"
#include "types.h"

void cycle_pattern_add(t_cycle *cycle, char *name, int ant)
{
    char *n;
    int index;
    
    if (cycle->length != 0)
        array_append((t_array *)cycle, (void *)" ");
    array_append((t_array *)cycle, (void *)"L");
    if ((n = ft_itoa(ant)) == NULL)
        error_malloc("cycle_pattern_add");
    index = 0;
    while (n[index] != '\0')
    {
        array_append((t_array *)cycle, (void *)&n[index]);
        ++index;
    }
    free(n);
    array_append((t_array *)cycle, (void *)"-");
    index = 0;
    while (name[index] != '\0')
    {
        array_append((t_array *)cycle, (void *)&name[index]);
        ++index;
    }
}