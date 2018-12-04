#ifndef LEM_IN_H
#define LEM_IN_H

#include "list_42.h"

typedef enum	t_room_type
{
	basic = 0,
	start = 1,
	end = 2,
}				t_room_type;

typedef struct	s_room
{
	char		*name;
	int			*pipe_index;
	int			self_index;
	t_room_type	type;
}				t_room;

typedef struct	s_anthill
{
	t_list		list;
	char		*line;
}				t_anthill;

typedef struct	s_env
{
//	int			**graph;
//	t_room		*start;
//	t_room		*end;
	t_anthill	*anthill;
	int			ants;
}				t_env;

#endif
