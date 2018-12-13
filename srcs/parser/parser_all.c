/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:24:09 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/13 16:42:27 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "write_42.h"
#include "array_42.h"
#include "parser.h"

bool    parser_all(t_env *e)
{
    char *line;

    if (parser_ant(e->anthill, &line, &e->ants) == false)
    {
        ft_putstr("Parsing finish while reading ants...\n");
        return (false);
    }
    /*if (parser_room(, &line) == false)
    {
        ft_putstr("Parsing finish while reading rooms...\n");
        return (false);
    }
    if (parser_pipe(, &line) == false)
    {
        ft_putstr("Parsing finish while reading pipes...\n");
        return (false);
    }
    */
    array_fit((t_array *)e->anthill);
    return (true);
}