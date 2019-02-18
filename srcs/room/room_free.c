/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 21:27:45 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/18 21:30:39 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "types.h"

void room_free(t_room *room)
{
    if (room != NULL)
    {
        if (room->name != NULL)
            free(room->name);
        free(room);
    }
}