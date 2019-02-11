/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:12:27 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/11 13:26:52 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "array_42.h"
#include "free_42.h"

#include "graph.h"
#include "types.h"
#include "garbage.h"

void    garbage_all(t_env *env)
{
    if (env != NULL)
    {
        if (env->anthill != NULL)
            array_dispose((t_array *)env->anthill, &free_2d_char);
        if (env->map != NULL)
            array_dispose((t_array *)env->map, &garbage_rooms);
        free_graph(env->graph);
        free(env);
    }
}