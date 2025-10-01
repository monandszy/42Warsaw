NAME = test_runner.out
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = \
	main.c \
	is_x.c \
	to_x.c \
	mem_mani.c \
	str_mani.c \
	search.c \
	cmp.c \
	misc.c \
	adv_str_mani.c \
	str_mapi.c \
	file_mani.c

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
	$(CC) $(CFLAGS) $(OBJ_PATHS) $(LIB_DIR)/libft.a -o $(NAME) -lbsd

lib_make:
	make -C $(LIB_DIR)

test: 
	./$(NAME)

run: re test

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re test lib_make
