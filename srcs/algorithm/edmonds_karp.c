/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 11:12:30 by rpinoit           #+#    #+#             */
/*   Updated: 2019/03/31 22:20:30 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <float.h>
#include "array_42.h"
#include "path.h"
#include "algorithm.h"
#include "graph.h"
#include "types.h"

void graph_augment_flow(t_graph *graph, t_karp *karp)
{
    unsigned int v;
    unsigned int u;

    v = karp->sink;
    while (v != karp->source)
    {
        u = karp->parent[v];
        graph->edge[v][u].flow -= 1;
        graph->edge[u][v].flow += 1;
        v = karp->parent[v];
    }
}

float rentability_calcul(t_run *run, int ants)
{
    size_t index;
    size_t total;

    index = 0;
    total = 0;
    while (index < run->length)
    {
        total += run->paths[index]->length;
        ++index;
    }
    //("#total = %zu ; run->length = %zu ; ants = %zu\n", total, run->length, (size_t)ants);
    return ((float)(((float)total + (float)ants) / (float)run->length));
}

int edmonds_karp(t_env *e, t_karp *karp)
{
    t_run *run;
    t_graph *copy;
    t_karp *karp_tmp;
    float rentability;
    float rentability_tmp;
    int max_flow;

    max_flow = 0;
    rentability_tmp = FLT_MAX;
    while (bfs_capacity(e->graph, e->adj, karp))
    {
        graph_augment_flow(e->graph, karp);
        karp_tmp = new_karp(karp->source, karp->sink, e->graph->size);
        copy = graph_copy(e->graph);
        //graph_print(copy);
        run = path_build(copy, e->adj, karp_tmp);
        //graph_print(copy);
        rentability = rentability_calcul(run, e->ants);
        //printf("#rentability = %f\n", rentability);
        if (rentability < rentability_tmp)
        {
            if (e->run != NULL)
                array_dispose((t_array *)e->run, &path_free);
            rentability_tmp = rentability;
            e->run = run;
            //path_print(e->run, e->map);
        }
        else
            array_dispose((t_array *)run, &path_free);
        free_karp(karp_tmp);
        graph_free(copy);
        max_flow += 1;
    }
    return (max_flow);
}