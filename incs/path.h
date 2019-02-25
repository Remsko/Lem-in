/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:33:42 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/21 17:50:06 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
#define PATH_H

#include "types.h"

void    path_add(t_run *run, t_path *path);

t_path *path_new(unsigned int *parent, size_t length, unsigned int source, unsigned int sink);

void path_print(t_run *run, t_map *map);

#endif