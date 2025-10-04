NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = \
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

OBJS = $(SRCS:.c=.o)
OBJ_PATHS = $(addprefix $(OBJS_DIR)/, $(OBJS))
OBJS_DIR = ./objs

libft.a: all
all: compile archive

mkdirs:
	mkdir -p $(OBJS_DIR)

compile: mkdirs $(OBJS)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $(OBJS_DIR)/$@

archive:
	ar rcs $(NAME) $(OBJ_PATHS)

clean:
	rm -rf $(OBJS_DIR) libft.h.gch

fclean: clean
	rm -rf $(NAME)

re: fclean all

breaker: fclean compile
	$(CC) -nostartfiles -shared -fPIC -ldl $(CFLAGS) -o libft.so $(OBJ_PATHS)

# Prevents confusing a flag's name for a file
.PHONY: all clean fclean re
