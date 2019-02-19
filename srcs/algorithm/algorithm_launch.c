/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_launch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 18:23:17 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/19 13:05:29 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "room.h"
#include "types.h"
#include "algorithm.h"
#include "write_42.h"
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
    if ((karp->visited = (bool *)malloc(sizeof(bool) * e->graph->size)) == NULL)
        return (false);
    if ((karp->parent = (unsigned int *)malloc(sizeof(int) * e->graph->size)) == NULL)
    {
        free_karp(karp);
        return (false);
    }
    karp->source = e->start;
    karp->sink = e->end;
    return (true);
}

void algorithm_launch(t_env *env)
{
    t_karp karp;
    int max_flow;

    if (new_karp(env, &karp) == false)
        return (ft_putstr("Failed to init karp structure.\n"));
    max_flow = edmonds_karp(env->graph, env->adj, &karp);
    free_karp(&karp);
    (void)max_flow;
    //printf("#max_flow = %d\n", max_flow);
    /* test */
    /*
    while (max_flow > 0)
    {
        printf("#");
        if ((new_karp(env, &karp)) == false)
            return (ft_putstr("Failed to init karp structure.\n"));
        graph_consumer(env->graph, env->adj, &karp);

        unsigned int v = karp.sink;
        while (v != karp.source)
        {
            printf("%s<-", env->map->rooms[v]->name);
            v = karp.parent[v];
        }
        printf("%s\n", env->map->rooms[v]->name);
        free_karp(&karp);
        --max_flow;
    }
    */
}