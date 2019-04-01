/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 12:30:58 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/01 16:45:02 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "types.h"
#include "string_42.h"

t_room	*room_create(char *name, t_room_type type)
{
	t_room *new;

	if ((new = (t_room *)malloc(sizeof(t_room))) != NULL)
	{
		if ((new->name = ft_strdup(name)) == NULL)
		{
			free(new);
			return (NULL);
		}
		new->pipes = 0;
		new->self_index = 0;
		new->type = type;
	}
	return (new);
}
