NAME = lem-in
CC = gcc
RM = rm -rf

INC_PATH += ./incs
INC_NAME += types.h
INC_NAME += parser.h
INC_NAME += anthill.h
INC_NAME += garbage.h
INC_NAME += room.h
INC_NAME += graph.h
INC_NAME += algorithm.h
INC_NAME += adjacency.h
INC_NAME += path.h
INC_NAME += cycle.h
INC_NAME += ant.h

INC = $(addprefix $(INC_PATH)/,$(INC_NAME))

CFLAGS = -Wall -Werror -Wextra -Wconversion
CPPFLAGS = $(addprefix -I,$(INC_PATH))

SRC_PATH = srcs
SRC_NAME += main.c

SRC_SUB += parser
SRC_NAME += parser_error.c
SRC_NAME += parser_all.c
SRC_NAME += parser_ant.c
SRC_NAME += parser_room.c
SRC_NAME += parser_pipe.c

SRC_SUB += anthill
SRC_NAME += anthill_add.c
SRC_NAME += anthill_print.c

SRC_SUB += garbage
SRC_NAME += garbage_all.c
SRC_NAME += garbage_rooms.c

SRC_SUB += graph
SRC_NAME += graph_copy.c
SRC_NAME += graph_free.c
SRC_NAME += graph_new.c
SRC_NAME += graph_print.c

SRC_SUB += room
SRC_NAME += room_parse.c
SRC_NAME += room_add.c
SRC_NAME += room_create.c
SRC_NAME += room_check.c
SRC_NAME += room_print.c
SRC_NAME += room_insert.c
SRC_NAME += room_search.c
SRC_NAME += room_free.c

SRC_SUB += algorithm
SRC_NAME += algorithm_paths.c
SRC_NAME += algorithm_ants.c
SRC_NAME += edmonds_karp.c
SRC_NAME += new_karp.c
SRC_NAME += free_karp.c
SRC_NAME += bfs.c
SRC_NAME += bfs_superposition.c

SRC_SUB += adjacency
SRC_NAME += adjacency_new.c
SRC_NAME += adjacency_free.c

SRC_SUB += cycle
SRC_NAME += cycle_add.c
SRC_NAME += cycle_print.c
SRC_NAME += cycle_pattern_add.c

SRC_SUB += path
SRC_NAME += path_add.c
SRC_NAME += path_new.c
SRC_NAME += path_print.c
SRC_NAME += path_free.c
SRC_NAME += path_build.c
SRC_NAME += path_start_end.c

SRC_SUB += ant
SRC_NAME += ant_new.c
SRC_NAME += ant_forward.c
SRC_NAME += ant_arrived.c

vpath %.c $(SRC_PATH) $(addprefix $(SRC_PATH)/, $(SRC_SUB))

OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:%.c=%.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME)) 

LIB_PATH = Libc
LIB = $(LIB_PATH)/libft.a
CFLAGS += -I$(LIB_PATH)/incs
LDFLAGS += -L $(LIB_PATH) -lft


all: $(NAME)


$(NAME): $(OBJ) | $(LIB)
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJ): $(INC) | $(OBJ_PATH)
$(OBJ): $(OBJ_PATH)/%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_PATH):
	mkdir -p $@

$(LIB):
	make -C $(LIB_PATH)

clean:
	$(RM) $(OBJ_PATH)
	make -C $(LIB_PATH) clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
