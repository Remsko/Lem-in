/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:12:27 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/13 17:51:46 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "string_42.h"
#include "write_42.h"

#include "types.h"
#include "garbage.h"

void    garbage_all(t_env *e)
{
    size_t i;

    i = 0;
    if (e->anthill->lines != NULL)
    {
        while (i < e->anthill->length)
        {
            ft_putendl(e->anthill->lines[i]);
            free(e->anthill->lines[i]);
            //ft_putendl(e->anthill->lines[i]);
            ++i;
        }
        free(e->anthill->lines);
    }
    free(e->anthill);
}