/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_adjacency.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:10:17 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/19 10:42:12 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "types.h"

void free_adjacency(t_adjacency *adj, size_t size)
{
    size_t index;

    if (adj == NULL)
        return ;
    index = 0;
    while (index < size)
    {
        if (adj[index].list != NULL)
            free(adj[index].list);
        ++index;
    }
    free(adj);
}