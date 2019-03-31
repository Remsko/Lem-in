/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:40:48 by rpinoit           #+#    #+#             */
/*   Updated: 2019/03/31 19:58:34 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "write_42.h"

void path_print(t_run *run, t_map *map)
{
    t_path *path;
    size_t run_index;
    size_t path_index;
    unsigned int room;

    run_index = 0;
    while (run_index < run->length)
    {
        path = run->paths[run_index];
        path_index = 0;
        ft_putstr("#");
        while (path_index < path->length - 1)
        {
            room = path->list[path_index];
            ft_putstr(map->rooms[room]->name);
            ft_putstr("->");
            ++path_index;
        }
        room = path->list[path_index];
        ft_putendl(map->rooms[room]->name);
        ++run_index;
    }
}