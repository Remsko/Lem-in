/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 23:54:06 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/09 23:54:58 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
#define GRAPH_H

#include "types.h"

t_graph *new_graph(size_t size);

void free_graph(t_graph *graph);

#endif