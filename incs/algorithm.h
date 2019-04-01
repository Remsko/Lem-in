/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:55:07 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/01 18:46:11 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "types.h"

void algorithm_paths(t_env *env);

void edmonds_karp(t_env *env, t_karp *karp);

bool bfs_flow(t_graph *graph, t_adjacency *adj, t_karp *karp);

bool bfs_capacity(t_graph *graph, t_adjacency *adj, t_karp *karp);

t_karp *new_karp(size_t start, size_t end, size_t size);

void free_karp(t_karp *karp);

void algorithm_ants(t_env *e);

bool bfs(t_graph *graph, t_adjacency *adj, t_karp *karp, bool (*edge_condition)(t_edge *edge));

#endif