/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:12:48 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/01 19:33:31 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_H
# define GARBAGE_H

void	garbage_all(t_env *e);

void	garbage_rooms(void *ptr, size_t size);

#endif
