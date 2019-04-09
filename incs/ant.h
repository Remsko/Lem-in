/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 22:24:15 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/04 22:25:12 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANT_H
# define ANT_H

#include "types.h"

t_ant *ant_new(t_path *path, int *id);

void ant_forward(t_map *map, t_ant *ant, t_cycle *cycle);

bool ant_arrived(t_map *map, t_ant *ant);

#endif