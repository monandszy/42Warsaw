NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = \
	ft_printf.c
OBJ = $(SRC:.c=.o)
OBJ_DIR = objs
LIBFT_PATH = libft
OBJ_PATH = $(addprefix $(OBJ_DIR)/, $(OBJ))

$(NAME): all

all: $(OBJ) archive

%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

archive:
	ar rcs $(NAME) $(OBJ_PATH)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME) printf.h.gch

re: fclean all

.PHONY: all comile archive fclean clean re
