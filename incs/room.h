/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 12:28:45 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/01 19:36:10 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOM_H
# define ROOM_H

# include <stdbool.h>
# include "types.h"
# include "error_42.h"

bool	room_parse(t_env *e, char *line, t_room_type type);

bool	room_check(char **split, size_t length);

size_t	room_index(t_map *map, char *name);

void	room_add(t_map *map, t_room *room);

t_room	*room_create(char *name, t_room_type type);

void	room_print(t_map *map);

t_room	*room_byname(t_map *map, char *name);

size_t	room_bytype(t_map *map, t_room_type type);

bool	room_insert(t_rb_tree **root, t_room *room);

t_room	*room_search(t_rb_tree *root, char *name);

void	room_free(t_room *room);

#endif
