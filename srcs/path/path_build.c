/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_build.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 13:14:31 by rpinoit           #+#    #+#             */
/*   Updated: 2019/03/31 20:30:51 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"
#include "memory_42.h"
#include "queue_42.h"
#include "algorithm.h"
#include "path.h"
#include "types.h"

size_t graph_reduce_flow(t_graph *graph, t_karp *karp)
{
    size_t path_length;
    unsigned int v;
    unsigned int u;

    path_length = 1;
    v = karp->sink;
    while (v != karp->source)
    {
        u = karp->parent[v];
        karp->visited[u] = true;
        graph->edge[v][u].flow = 0;
        graph->edge[u][v].flow = 0;
        v = karp->parent[v];
        ++path_length;
    }
    return (path_length);
}

t_run *path_build(t_graph *graph, t_adjacency *adj, t_karp *karp)
{
    t_run *run;
    t_path *new;
    size_t path_length;
    
    run = (t_run *)array_create(sizeof(t_path *));
    ft_bzero(karp->parent, sizeof(int) * (size_t)graph->size);
    ft_bzero((void *)karp->visited, sizeof(bool) * (size_t)graph->size);
    while (bfs_flow(graph, adj, karp))
    {
        ft_bzero((void *)karp->visited, sizeof(bool) * (size_t)graph->size);
        path_length = graph_reduce_flow(graph, karp);
        //print_graph();
        new = path_new(karp, path_length);
        path_add(run, new);
    }
    return (run);
}