/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_karp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:08:43 by rpinoit           #+#    #+#             */
/*   Updated: 2019/03/02 18:15:00 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "algorithm.h"
#include "types.h"

t_karp *new_karp(unsigned int start, unsigned int end, size_t size)
{
    t_karp *karp;
    
    if ((karp = (t_karp *)malloc(sizeof(t_karp))) == NULL)
        return (NULL);
    if ((karp->visited = (bool *)malloc(sizeof(bool) * size)) == NULL)
        return (NULL);
    if ((karp->parent = (unsigned int *)malloc(sizeof(int) * size)) == NULL)
    {
        free_karp(karp);
        return (NULL);
    }
    karp->source = start;
    karp->sink = end;
    return (karp);
}