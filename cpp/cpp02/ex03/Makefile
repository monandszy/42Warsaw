NAME = out
CC = g++
CFLAGS = -g -Wall -Wextra -Werror -std=c++98
SRC = \
	main.cpp \
	Fixed.cpp \
	Point.cpp \
	bsp.cpp

OBJ = $(SRC:.cpp=.o)
OBJ_PATH = $(addprefix $(OBJ_DIR)/, $(OBJ))
OBJ_DIR = ./objs

all: compile $(NAME)

compile: $(OBJ_DIR) $(OBJ)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

%.o: %.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$@ 

$(NAME):
	$(CC) $(CFLAGS) $(OBJ_PATH) -o $(NAME) -lbsd

test: 
	./$(NAME)

run: re test

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
.PHONY: all fclean clean re test run $(NAME)

