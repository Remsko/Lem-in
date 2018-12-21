/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:21:47 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/21 20:21:35 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
#define TYPES_H

#include <stddef.h>

typedef enum t_room_type
{
    basic = 0,
    start = 1,
    end = 2,
} t_room_type;

typedef struct s_room
{
    char *name;
    int *pipe_index;
    int self_index;
    t_room_type type;
} t_room;

typedef struct s_anthill
{
    char **lines;
    size_t length;
    size_t capacity;
    size_t size;
} t_anthill;

typedef struct s_map
{
    t_room **rooms;
    size_t length;
    size_t capacity;
    size_t size;
} t_map;

typedef struct s_env
{
    //	t_room		*start;
    //	t_room		*end;
    t_map     *map;
    t_anthill   *anthill;
    int ants;
} t_env;

#endif