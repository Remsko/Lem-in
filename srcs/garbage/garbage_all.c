/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:12:27 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/21 12:19:29 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "array_42.h"
#include "free_42.h"

#include "types.h"

void    garbage_all(t_env *env)
{
    if (env != NULL)
    {
        if (env->anthill != NULL)
            array_dispose((t_array *)env->anthill, free_2d_char);
        free(env);
    }
}