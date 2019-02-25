/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:35:45 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/25 16:22:19 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"
#include "error_42.h"
#include "types.h"

void    path_add(t_run *run, t_path *path)
{
    array_append((t_array *)run, (void *)&path);
    if (run->paths == NULL)
        error_malloc("anthill_add");
}