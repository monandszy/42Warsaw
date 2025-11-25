NAME = libftprintf.a
CC = cc
CFLAGS = -g  -Wall -Wextra -Werror
SRC = \
	ft_printf.c \
	extractor.c \
	converter.c \
	digit_converter.c \
	formatter.c \
	utils.c \
	processor_bonus.c \
	precision_applier_bonus.c \
	prefix_creator_bonus.c \
	assembler_bonus.c
OBJ = $(SRC:.c=.o)
BOBJ = $(BONUS:.c=.o)
OBJ_DIR = objs
LIB_DIR = libft
OBJ_PATH = $(addprefix $(OBJ_DIR)/, $(OBJ))

$(NAME): all

all: $(OBJ) libmake archive

bonus: OBJ += $(BOBJ)
bonus: $(BOBJ)
bonus: all

%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

libmake:
	make bonus -C $(LIB_DIR) > /dev/null 2>&1
	cp ./$(LIB_DIR)/libft.a ./$(NAME)

archive:
	ar rcs $(NAME) $(OBJ_PATH)

clean:
	rm -rf $(OBJ_DIR)
	make -C fclean $(LIB_DIR) > /dev/null 2>&1

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all comile archive fclean clean re bonus libmake
