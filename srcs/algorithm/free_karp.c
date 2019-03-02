/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_karp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:10:38 by rpinoit           #+#    #+#             */
/*   Updated: 2019/03/02 18:15:30 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "types.h"

void free_karp(t_karp *karp)
{
    if (karp != NULL)
    {
        if (karp->visited != NULL)
            free(karp->visited);
        if (karp->parent != NULL)
            free(karp->parent);
        free(karp);
    }
}