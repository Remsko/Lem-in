/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjacency.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:13:08 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/19 10:42:32 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADJACENCY_H
#define ADJACENCY_H

#include "types.h"

t_adjacency *new_adjacency(t_room **rooms, t_graph *graph);

void free_adjacency(t_adjacency *adj, size_t size);

#endif