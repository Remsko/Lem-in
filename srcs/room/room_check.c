/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 12:39:29 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/23 14:51:19 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "conv_42.h"
#include "error_42.h"

#include "types.h"

t_error *room_check(char **split, size_t length)
{
    int useless;

    if (length != 3)
        return (error_create("Bad room format.", NULL, 4));
    else if (ft_isatoi(split[1], &useless) == false || ft_isatoi(split[2], &useless) == false)
        return (error_create("Room coordinates values must be at an least int.", NULL, 5));
    return (NULL);
}