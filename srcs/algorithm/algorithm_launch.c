/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_launch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 18:23:17 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/09 18:27:40 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

int get_start(t_map *map)
{
    return (room_bytype(map, START));
}

int get_end(t_map *map)
{
    return (room_bytype(map, END));
}

void    alogirthm_launch(t_env *env)
{
    int max_flow;

    env->start = get_start(env->map);
    env->end = get_end(env->map);
    max_flow = edmonds_karp(env->graph, env->start, env->end);
}