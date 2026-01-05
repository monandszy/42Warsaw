NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MAIN = main.c
SRCS = \
	utils.c

MOBJ = $(MAIN:.c=.o)
OBJS = $(SRCS:.c=.o)
OBJ_PATHS = $(addprefix $(OBJS_DIR)/, $(OBJS))
MOBJ_PATH = $(addprefix $(OBJS_DIR)/, $(MOBJ))
OBJS_DIR = ./objs

LIB_DIR = libft

all: compile $(NAME)

compile: mkdirs $(OBJS) $(MOBJ)

mkdirs:
	mkdir -p $(OBJS_DIR)
	mkdir -p $(OBJS_DIR)/executor
	mkdir -p $(OBJS_DIR)/parser

%.o: %.c
	$(CC) $(CFLAGS) -I. -I./$(LIB_DIR) -c $< -o $(OBJS_DIR)/$@ 

$(NAME): lib_make
	$(CC) $(CFLAGS) $(OBJ_PATHS) $(MOBJ_PATH) $(LIB_DIR)/libft.a -o $(NAME) -lbsd -lreadline

archive:
	cp $(LIB_DIR)/libft.a $(NAME).a
	ar rcs $(NAME).a $(OBJ_PATHS)

test: 
	./$(NAME)

run: re test

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME) $(NAME).a

re: fclean all

lib_make:
	make bonus -C $(LIB_DIR) > /dev/null 2>&1

.PHONY: all clean fclean re test lib_make
