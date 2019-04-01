/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_paths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 18:23:17 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/01 00:09:05 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "room.h"
#include "types.h"
#include "algorithm.h"
#include "path.h"
#include "write_42.h"

#include <stdlib.h>
#include "array_42.h"
#include <stdio.h>

void start_end(t_env *env)
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

void algorithm_paths(t_env *env)
{
    t_karp *karp;

    if (env->map->length == 2)
        return (start_end(env));
    karp = new_karp(env->start, env->end, env->graph->size);
    edmonds_karp(env, karp);
    free_karp(karp);
    if (env->run == NULL)
        return (ft_putstr("ERROR\nNo path were found."));
}