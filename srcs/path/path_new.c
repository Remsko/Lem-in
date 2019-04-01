/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:06:03 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/01 15:06:18 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "types.h"

t_path	*path_new(t_karp *karp, size_t length)
{
	t_path *path;
	size_t u;

	if ((path = (t_path *)malloc(sizeof(t_path))) != NULL)
	{
		if ((path->list = (size_t *)malloc(sizeof(size_t) * length)) == NULL)
		{
			free(path);
			return (NULL);
		}
		path->length = length;
		u = karp->sink;
		while (u != karp->source)
		{
			path->list[length - 1] = u;
			u = karp->parent[u];
			--length;
		}
		path->list[length - 1] = u;
	}
	return (path);
}
