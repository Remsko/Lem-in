/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:54:28 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/13 17:06:32 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "write_42.h"

#include "types.h"

void anthill_print(t_anthill *anthill)
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