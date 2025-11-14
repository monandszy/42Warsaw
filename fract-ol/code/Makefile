NAME = fract-ol
CC = cc
CFLAGS = -g  -Wall -Wextra -Werror
SRC = \
	fract-ol.c
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
	$(CC) $(CFLAGS) $(OBJ_PATH) printf/libftprintf.a minilibx/libmlx.a -o $(NAME) -lm

libmake:
	make bonus -C printf > /dev/null 2>&1
	make -C minilibx > /dev/null 2>&1

clean:
	make fclean -C printf > /dev/null 2>&1
	make fclean -C minilibx > /dev/null 2>&1
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all comile archive fclean clean re bonus libmake $(NAME)
