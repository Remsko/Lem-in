/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:06:03 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/25 16:30:00 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "types.h"

#include<stdio.h>
t_path *path_new(unsigned int *parent, size_t length, unsigned int source, unsigned int sink)
{
    t_path *path;
    unsigned int precedent;

    if ((path = (t_path *)malloc(sizeof(t_path))) != NULL)
    {
        if ((path->next = (unsigned int *)malloc(sizeof(unsigned int) * length)) == NULL)
        {
            free(path);
            return (NULL);
        }
        path->length = length;
        precedent = sink;
        while (precedent != source)
        {
            path->next[length - 1] = precedent;
            precedent = parent[precedent];
            --length;
        }
        path->next[length - 1] = precedent;
    }
    return (path);
}