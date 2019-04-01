/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_start_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 19:13:57 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/01 19:14:51 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "types.h"
#include "path.h"
#include "array_42.h"

void path_start_end(t_env *env)
{
    t_path *new;

    if ((env->run = (t_run *)array_create(sizeof(t_path *))) != NULL)
    {
        if ((new = (t_path *)malloc(sizeof(t_path))) == NULL
            || (new->list = (size_t *)malloc(sizeof(size_t) * 2)) == NULL)
        {
            if (new != NULL)
                free(new);
            free(env->run);
        }
        new->list[0] = env->start;
        new->list[1] = env->end;
        new->length = 2;
        path_add(env->run, new);
    }
}