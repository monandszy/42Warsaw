NAME = test_runner.out
CC = cc
CFLAGS = -g 
# -Wall -Wextra -Werror
SRC = \
    main.c

OBJ = $(SRC:.c=.o)
OBJ_PATH = $(addprefix $(OBJ_DIR)/, $(OBJ))
OBJ_DIR = ./objs
LIB_DIR = ./../code

all: compile $(NAME)

compile: $(OBJ_DIR) $(OBJ)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$@ 

$(NAME): lib_make
	$(CC) $(CFLAGS) $(OBJ_PATH) $(LIB_DIR)/libftprintf.a -o $(NAME) -lbsd

lib_make:
	make bonus -C $(LIB_DIR)

test: 
	./$(NAME)

run: re test

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

