/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:33:42 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/01 19:14:57 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
#define PATH_H

#include "types.h"

void path_start_end(t_env *env);

void    path_add(t_run *run, t_path *path);

t_path *path_new(t_karp *karp, size_t length);

void    path_free(void *ptr, size_t size);

void path_print(t_run *run, t_map *map);

t_run *path_build(t_graph *graph, t_adjacency *adj, t_karp *karp);

#endif