NAME = push_swap
BNAME = checker
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
SRC =  \
	sort_utils.c \
	mini_sorter.c \
	chunker.c \
	move_executor.c \
	move_reverser.c \
	int_arr_utils.c \
	to_string.c \
	executor.c \
	calculator.c \
	initialize_utils.c \
	memory_utils.c \
	dlist_utils.c \
	validator.c \
	planner.c \
	swapper.c \
	pusher.c \
	rotator.c \
	rev_rotator.c
BONUS = \
	check_utils.c

MAIN = ps.c
BMAIN = sc.c

OBJ_DIR = objs
LIB_DIR = printf
SRC_DIR = ps
BSRC_DIR = sc

#SRC_PATH = $(addprefix $(SRC_DIR)/, $(SRC))
#BSRC_PATH = $(addprefix $(BSRC_DIR)/, $(BONUS))

MOBJ = $(OBJ_DIR)/$(MAIN:.c=.o)
BMOBJ = $(OBJ_DIR)/$(BMAIN:.c=.o)
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
BOBJ = $(addprefix $(OBJ_DIR)/, $(BONUS:.c=.o))

all: $(MOBJ) $(OBJ) libmake compile_ps

bonus: $(BMOBJ) $(OBJ) $(BOBJ) libmake compile_sc

$(NAME): all
$(BNAME): bonus

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(BSRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

compile_ps:
	$(CC) $(CFLAGS) $(MOBJ) $(OBJ) ./$(LIB_DIR)/libftprintf.a -o $(NAME)

compile_sc:
	$(CC) $(CFLAGS) $(BMOBJ) $(OBJ) $(BOBJ) ./$(LIB_DIR)/libftprintf.a -o $(BNAME)

run: all
	./$(NAME)

test: bonus
	./$(BNAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

libmake:
	make bonus -C $(LIB_DIR) > /dev/null 2>&1

clean:
	make -C $(LIB_DIR) fclean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME) $(BNAME)

re: fclean all

.PHONY: all compile_sc compile_ps fclean clean re bonus libmake test run $(NAME) $(BNAME)
