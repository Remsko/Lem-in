/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:23:52 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/07 17:37:12 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "list_42.h"

void    add_line(t_anthill *anthill, char **line)
{
    t_anthill *new;

    if ((new = (t_anthill *)malloc(sizeof(t_anthill))) == NULL)
        error_malloc();
    new->line = *line;
    list_add(&new->list, &anthill->list));
}