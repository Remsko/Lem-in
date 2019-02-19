/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:12:27 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/19 10:37:53 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "array_42.h"
#include "free_42.h"

#include "graph.h"
#include "types.h"
#include "garbage.h"
#include "adjacency.h"

void    garbage_all(t_env *env)
{
    if (env != NULL)
    {
        if (env->anthill != NULL)
            array_dispose((t_array *)env->anthill, &free_2d_char);
        if (env->map != NULL)
            array_dispose((t_array *)env->map, &garbage_rooms);
        if (env->graph != NULL)
            free_adjacency(env->adj, env->graph->size);
        free_graph(env->graph);
        rb_tree_delete(env->root);
        free(env);
    }
}