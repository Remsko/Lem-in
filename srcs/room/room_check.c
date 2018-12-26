/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 12:39:29 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/26 13:36:47 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "conv_42.h"
#include "error_42.h"

#include "types.h"

bool room_check(char **split, size_t length)
{
    int useless;

    if (length != 3)
        return (false);
    else if (ft_isatoi(split[1], &useless) == false || ft_isatoi(split[2], &useless) == false)
        return (false);
    return (true);
}