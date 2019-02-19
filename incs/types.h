/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:21:47 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/19 09:47:28 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
#define TYPES_H

#include <stddef.h>
#include "rb_tree_42.h"

typedef enum e_room_type
{
    BASIC = 0,
    START = 1,
    END = 2,
} t_room_type;

typedef struct s_adjacency
{
    int *list;
    int length;
} t_adjacency;

typedef struct s_graph
{
    int **flow;
    int row;
} t_graph;

typedef struct s_room
{
    char *name;
    int pipes;
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
    t_rb_tree *root;
    t_map *map;
    t_graph *graph;
    t_adjacency *adj;
    t_anthill *anthill;
    int start;
    int end;
    int ants;
} t_env;

typedef struct s_karp
{
    int *parent;
    bool *visited;
    int source;
    int sink;
} t_karp;

#endif