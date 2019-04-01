/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:39:50 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/01 19:33:12 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANTHILL_H
# define ANTHILL_H

# include "types.h"

void	anthill_add(t_anthill *anthill, char **line);

void	anthill_print(t_anthill *anthill);

#endif
