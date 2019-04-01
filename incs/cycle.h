/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:47:43 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/01 15:14:34 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYCLE_H
#define CYCLE_H

#include "types.h"

void cycle_pattern_add(t_cycle *cycle, char *name, int ant);

void cycle_add(t_cycle *cycle, char c);

void cycle_print(t_cycle *cycle);

#endif