/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_karp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:08:43 by rpinoit           #+#    #+#             */
/*   Updated: 2019/10/18 13:53:26 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "memory_42.h"
#include "algorithm.h"
#include "types.h"

t_karp	*new_karp(size_t start, size_t end, size_t size)
{
	t_karp *karp;

	if ((karp = (t_karp *)ft_memalloc(sizeof(t_karp))) == NULL)
		return (NULL);
	if ((karp->visited = (bool *)ft_memalloc(sizeof(bool) * size)) == NULL)
	{
		free_karp(karp);
		return (NULL);
	}
	if ((karp->parent = (size_t *)ft_memalloc(sizeof(size_t) * size)) == NULL)
	{
		free_karp(karp);
		return (NULL);
	}
	karp->source = start;
	karp->sink = end;
	return (karp);
}
