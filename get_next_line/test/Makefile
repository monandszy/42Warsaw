# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/15 14:35:54 by sandrzej          #+#    #+#              #
#    Updated: 2025/10/17 12:23:53 by sandrzej         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_runner.out
CC = cc
CFLAGS = -g \
-D BUFFER_SIZE=16 \
 -Wall -Wextra -Werror
SRC = \
	main.c
EX_SRC_N = \
	get_next_line.c \
	get_next_line_utils.c
BEX_SRC_N = \
	get_next_line_bonus.c \
	get_next_line_utils_bonus.c

EX_DIR = ./../code

OBJ = $(SRC:.c=.o)
OBJ_DIR = ./objs
all: base

base: $(OBJ) 
	$(CC) $(CFLAGS) -c $(EX_DIR)/get_next_line.c -o $(OBJ_DIR)/gnl.o && \
	$(CC) $(CFLAGS) -c $(EX_DIR)/get_next_line_utils.c -o $(OBJ_DIR)/gnlu.o && \
	$(CC) $(CFLAGS) $(OBJ_DIR)/$(OBJ) $(OBJ_DIR)/gnl.o $(OBJ_DIR)/gnlu.o -o $(NAME) -lbsd
bonus: $(OBJ)
	$(CC) $(CFLAGS) -c $(EX_DIR)/get_next_line_bonus.c -o $(OBJ_DIR)/gnlb.o && \
	$(CC) $(CFLAGS) -c $(EX_DIR)/get_next_line_utils_bonus.c -o $(OBJ_DIR)/gnlub.o && \
	$(CC) $(CFLAGS) $(OBJ_DIR)/$(OBJ) $(OBJ_DIR)/gnlb.o $(OBJ_DIR)/gnlub.o -o $(NAME) -lbsd

%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

test: 
	./$(NAME)

run: re test

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
