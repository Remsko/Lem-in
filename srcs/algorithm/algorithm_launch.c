/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_launch.c                                 :+:      :+:    :+:   */
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

void algorithm_launch(t_env *env)
{
    t_karp *karp;
    int max_flow;

    if (env->map->length == 2)
    {
        env->run = (t_run *)array_create(sizeof(t_path *));
        t_path *new = malloc(sizeof(t_path));
        new->list = malloc(sizeof(unsigned int) * 2);
        new->list[0] = env->start;
        new->list[1] = env->end;
        new->length = 2;
        path_add(env->run, new);
        return ;
    }
    karp = new_karp(env->start, env->end, env->graph->size);
    max_flow = edmonds_karp(env, karp);
    free_karp(karp);
    (void)max_flow;
    //printf("#max_flow = %d\n", max_flow);
    if (env->run == NULL)
        return (ft_putstr("ERROR\nNo path were found."));
}