NAME = test_runner.out
CC = cc
CFLAGS = -g 
# -Wall -Wextra -Werror
PROGRAM_SRC = \
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
	ft_lstmap.c \
	main_utils.c \
	sorter.c \
	validator.c \
	sorter.c \
	planner.c \
	swapper.c \
	pusher.c \
	rotator.c \
	rev_rotator.c
BONUS = \
	check_utils.c
SRC = \
    main.c

OBJ = $(SRC:.c=.o)
POBJ = $(PROGRAM_SRC:.c=.o)
PROGRAM_OBJ_PATH = $(addprefix $(PROGRAM_DIR)/objs/, $(POBJ))
OBJ_PATH = $(addprefix $(OBJ_DIR)/, $(OBJ))
OBJ_DIR = ./objs
PROGRAM_DIR = ./../code

all: compile $(NAME)

compile: $(OBJ_DIR) $(OBJ)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$@ 

$(NAME): program_make
	$(CC) $(CFLAGS) $(OBJ_PATH) $(PROGRAM_OBJ_PATH) -o $(NAME) -lbsd

program_make:
	make bonus -C $(PROGRAM_DIR)
	cp $(PROGRAM_DIR)/push_swap push_swap
	$(PROGRAM_DIR)/checker checker

test:
	./$(NAME)

run: re test

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
