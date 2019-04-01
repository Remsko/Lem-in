/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjacency.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:13:08 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/01 14:16:36 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADJACENCY_H
# define ADJACENCY_H 1

#include "types.h"

t_adjacency *adjacency_new(t_room **rooms, t_graph *graph);

void adjacency_free(t_adjacency *adj, size_t size);

#endif