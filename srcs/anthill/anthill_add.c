/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:23:52 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/19 11:33:39 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "string_42.h"
#include "array_42.h"
#include "error_42.h"

#include "types.h"

void    anthill_add(t_anthill *anthill, char **line)
{
    array_append((t_array *)anthill, (void *)line);
    if (anthill->lines == NULL)
        error_malloc("anthil_add function line 25.");
}