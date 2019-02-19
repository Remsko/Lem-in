/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:55:07 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/19 09:54:00 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "types.h"

void    algorithm_launch(t_env *env);

int edmonds_karp(t_graph *graph, t_adjacency *adj, t_karp *karp);

#endif