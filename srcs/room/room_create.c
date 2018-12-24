/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 12:30:58 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/24 17:25:54 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "string_42.h"

#include "types.h"

t_room  *room_create(char *name, t_room_type type)
{
    t_room *new;

    if ((new = (t_room *)malloc(sizeof(t_room))) != NULL)
    {
        new->pipes.tab = NULL;
        new->pipes.length = 0;
        new->name = ft_strdup(name);
        new->type = type;
    }
    return (new);
}