/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:35:45 by rpinoit           #+#    #+#             */
/*   Updated: 2019/03/02 11:30:54 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"
#include "error_42.h"
#include "types.h"

void    path_add(t_run *run, t_path *path)
{
    array_append((t_array *)run, (void *)&path);
    if (run->paths == NULL)
        error_malloc("path_add");
}