NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = \
	ft_printf.c \
	formatter.c \
	utils.c
OBJ = $(SRC:.c=.o)
OBJ_DIR = objs
LIB_DIR = libft
OBJ_PATH = $(addprefix $(OBJ_DIR)/, $(OBJ))

$(NAME): all

all: libmake $(OBJ) archive

%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

libmake:
	make -C $(LIB_DIR) > /dev/null 2>&1

archive:
	ar rcs $(NAME) $(LIB_DIR)/libft.a $(OBJ_PATH)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME) printf.h.gch

re: fclean all

.PHONY: all comile archive fclean clean re
