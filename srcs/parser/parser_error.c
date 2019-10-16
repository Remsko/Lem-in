/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:01:00 by rpinoit           #+#    #+#             */
/*   Updated: 2019/10/16 14:00:48 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "error_42.h"
#include "write_42.h"
#include "string_42.h"

static void	msg_printf(void *msg)
{
	(void)msg;
	//ft_putendl((char *)msg);
}

static void	msg_free(void *msg)
{
	free(msg);
}

t_error		*parser_error(char *msg)
{
	msg = ft_strdup(msg);
	return (error_create(msg, &msg_printf, &msg_free, 1));
}
