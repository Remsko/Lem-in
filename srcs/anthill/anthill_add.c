/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:23:52 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/01 14:51:01 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "array_42.h"
#include "error_42.h"
#include "types.h"

void	anthill_add(t_anthill *anthill, char **line)
{
	array_append((t_array *)anthill, (void *)line);
	if (anthill->lines == NULL)
		error_malloc("anthill_add");
}
