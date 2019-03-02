/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 13:07:09 by rpinoit           #+#    #+#             */
/*   Updated: 2019/03/02 13:13:12 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "types.h"

void    path_free(void *ptr, size_t size)
{
    t_path **paths;
    size_t  i;

    i = 0;
    paths = (t_path **)ptr;
    if (paths != NULL)
    {
        while (i < size)
        {
            if (paths[i] != NULL)
            {
                if (paths[i]->next != NULL)
                    free(paths[i]->next);
                free(paths[i]);
            }
            ++i;
        }
        free(paths);
    }
}