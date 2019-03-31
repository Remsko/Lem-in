/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_launch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 18:23:17 by rpinoit           #+#    #+#             */
/*   Updated: 2019/03/31 20:49:46 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "room.h"
#include "types.h"
#include "algorithm.h"
#include "path.h"
#include "write_42.h"
#include <stdio.h>

void algorithm_launch(t_env *env)
{
    t_karp *karp;
    int max_flow;

    if (env->start == (unsigned int)-1 || env->end == (unsigned int)-1)
        return (ft_putstr("ERROR\n"));
    karp = new_karp(env->start, env->end, env->graph->size);
    max_flow = edmonds_karp(env, karp);
    free_karp(karp);
    (void)max_flow;
    //printf("#max_flow = %d\n", max_flow);
    if (env->run == NULL)
        return (ft_putstr("ERROR\n"));
}