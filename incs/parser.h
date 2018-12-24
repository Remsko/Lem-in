/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:20:42 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/24 16:54:06 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H

#include "error_42.h"
#include "types.h"

t_error *parser_all(t_env *e);

t_error *parser_ant(t_anthill *anthill, char **line, int *ants);

t_error *parser_room(t_map *map, t_anthill *anthill, char **line);

t_error *parser_pipe(t_map *map, t_anthill *anthill, char **line);

#endif