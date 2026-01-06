NAME = miniRT
CC = cc
CFLAGS = -g  -Wall -Wextra -Werror
SRC = \
	main.c \
	window_utils.c \
	color_manager.c \
	file_utils.c \
	renderer.c \
	mem_utils.c
OBJ = $(SRC:.c=.o)
OBJ_DIR = objs
OBJ_PATH = $(addprefix $(OBJ_DIR)/, $(OBJ))

all: $(OBJ) libmake $(NAME)

bonus: all

%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME):
	$(CC) $(CFLAGS) $(OBJ_PATH) libft/libft.a minilibx/libmlx.a -lXext -lX11 -lm -o $(NAME)

run: all
	./$(NAME) ./../test/test-1.rt

libmake:
	make bonus -C libft > /dev/null 2>&1

clean:
	make fclean -C libft > /dev/null 2>&1
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all comile archive fclean clean re bonus libmake $(NAME) run
