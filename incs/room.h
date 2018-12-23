/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 12:28:45 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/23 21:41:58 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOM_H
#define ROOM_H

#include "types.h"

size_t  room_index(t_map *map, char *name);

void    room_add(t_map *map, t_room **room);

t_room  *room_create(char *name, t_room_type type);

t_error *room_check(char **split, size_t length);

void    room_print(t_map *map);

#endif