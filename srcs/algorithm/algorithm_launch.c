/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_launch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 18:23:17 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/19 10:12:11 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "room.h"
#include "types.h"
#include "algorithm.h"
#include <stdlib.h>
#include <stdio.h>

static void free_karp(t_karp *karp)
{
    if (karp->visited != NULL)
        free(karp->visited);
    if (karp->parent != NULL)
        free(karp->parent);
}

static bool new_karp(t_env *e, t_karp *karp)
{
    if ((karp->visited = (bool *)malloc(sizeof(bool) * (size_t)e->graph->row)) == NULL)
        return (false);
    if ((karp->parent = (int *)malloc(sizeof(int) * (size_t)e->graph->row)) == NULL)
    {
        free_karp(karp);
        return (false);
    }
    karp->source = e->start;
    karp->sink = e->end;
}

void algorithm_launch(t_env *env)
{
    t_karp karp;
    int max_flow;

    if (new_karp(env, &karp) == false)
        return (ft_putstr("Failed to init karp structure.\n"));
    max_flow = edmonds_karp(env->graph, env->adj, &karp);
    free_karp(&karp);
    printf("#max_flow = %d\n", max_flow);
}