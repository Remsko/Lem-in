/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 12:30:58 by rpinoit           #+#    #+#             */
/*   Updated: 2019/10/18 14:06:46 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "types.h"
#include "string_42.h"
#include "memory_42.h"

t_room	*room_create(char *name, t_room_type type)
{
	t_room *new;

	if ((new = (t_room *)ft_memalloc(sizeof(t_room))) != NULL)
	{
		if ((new->name = ft_strdup(name)) == NULL)
		{
			free(new);
			return (NULL);
		}
		new->type = type;
	}
	return (new);
}
