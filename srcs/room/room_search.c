/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:11:06 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/01 16:44:44 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "string_42.h"
#include "rb_tree_42.h"

static int	cmp_room_name(void *data1, void *data2)
{
	t_room	*room;
	char	*name;

	name = (char *)data1;
	room = (t_room *)data2;
	return (ft_strcmp(name, room->name));
}

t_room		*room_search(t_rb_tree *root, char *name)
{
	t_rb_tree *node;

	if ((node = rb_tree_search(root, (void *)name, &cmp_room_name)) == NULL)
		return (NULL);
	if (cmp_room_name((void *)name, node->data) != 0)
		return (NULL);
	return ((t_room *)node->data);
}
