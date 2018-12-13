NAME = lem-in
CC = gcc
RM = rm -rf

INC_PATH += ./incs
INC_NAME += lem_in.h

INC_NAME += lem_in.h
INC = $(addprefix $(INC_PATH)/,$(INC_NAME))

CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = $(addprefix -I,$(INC_PATH))

SRC_PATH = srcs
SRC_NAME += main.c

vpath %.c $(SRC_PATH) $(addprefix $(SRC_PATH)/, $(SRC_SUB))

OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:%.c=%.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME)) 

LIB_PATH = libc
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
	$(MAKE) -C $(LIB_PATH)

clean:
	$(RM) $(OBJ_PATH)
	$(MAKE) -C $(LIB_PATH) clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
