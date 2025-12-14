NAME = test_runner.out
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = \
	main.c \

OBJS = $(SRCS:.c=.o)
OBJ_PATHS = $(addprefix $(OBJS_DIR)/, $(OBJS))
OBJS_DIR = ./objs

LIB_DIR = ./../code

all: compile $(NAME)

compile: mkdirs $(OBJS)

mkdirs:
	mkdir -p $(OBJS_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(OBJS_DIR)/$@ 

$(NAME): lib_make
	$(CC) $(CFLAGS) $(OBJ_PATHS) $(LIB_DIR)/minishell.a -o $(NAME) -lbsd -lreadline

lib_make:
	make compile archive -C $(LIB_DIR)

test: 
	./$(NAME)

run: re test

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re test lib_make
