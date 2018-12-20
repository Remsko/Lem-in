/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:12:27 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/20 17:54:25 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "array_42.h"
#include "free_42.h"

#include "types.h"

void    garbage_all(t_env *e)
{
    array_dispose((t_array *)e->anthill, free_2d_char);
}