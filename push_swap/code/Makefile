NAME = push_swap
BNAME = checker
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
PRINTF_SRC = \
	ft_printf.c \
	extractor.c \
	converter.c \
	digit_converter.c \
	formatter.c \
	utils.c \
	processor_bonus.c \
	precision_applier_bonus.c \
	prefix_creator_bonus.c \
	assembler_bonus.c \
	ft_isalpha.c \
	ft_isalnum.c \
	ft_isdigit.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strlen.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_memchr.c \
	ft_strnstr.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strncmp.c \
	ft_memcmp.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

SRC =  \
	sort_checker.c \
	lis.c \
	chunker.c \
	move_executor.c \
	move_reverser.c \
	int_arr_utils.c \
	to_string.c \
	executor.c \
	calculator.c \
	rr_calculator.c \
	rrr_calculator.c \
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
PRINTF_OBJ = $(addprefix $(OBJ_DIR)/, $(PRINTF_SRC:.c=.o))

all: $(MOBJ) $(OBJ) libmake compile_ps

bonus: $(BMOBJ) $(OBJ) $(BOBJ) libmake compile_sc

$(NAME): all
$(BNAME): bonus

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(BSRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

compile_ps:
	$(CC) $(CFLAGS) $(MOBJ) $(OBJ) $(PRINTF_OBJ) -o $(NAME)

compile_sc:
	$(CC) $(CFLAGS) $(BMOBJ) $(OBJ) $(BOBJ) $(PRINTF_OBJ) -o $(BNAME)

run: all
	./$(NAME)

test: bonus
	./$(BNAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

libmake:
	make bonus -C $(LIB_DIR) > /dev/null 2>&1
	cp $(LIB_DIR)/$(OBJ_DIR)/* $(OBJ_DIR)

clean:
	make -C $(LIB_DIR)/libft fclean
	make -C $(LIB_DIR) fclean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME) $(BNAME)

re: fclean all

.PHONY: all compile_sc compile_ps fclean clean re bonus libmake test run $(NAME) $(BNAME)
