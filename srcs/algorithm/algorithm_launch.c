/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_launch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 18:23:17 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/18 21:31:11 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "room.h"
#include "types.h"
#include "algorithm.h"
#include <stdio.h>
/*
int get_start(t_map *map)
{
    return ((int)room_bytype(map, START));
}

int get_end(t_map *map)
{
    return ((int)room_bytype(map, END));
}
*/
void    algorithm_launch(t_env *env)
{
    int max_flow;

    max_flow = edmonds_karp(env->graph, env->adj, env->start, env->end);
    printf("max_flow = %d\n", max_flow);
}