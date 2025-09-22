NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = \
	file.c
OBJECTS = $(SOURCES:.c=.o)

libft.a: all
all: compile archive

compile: $(OBJECTS)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

archive:
	ar rcs $(NAME) $(OBJECTS)

clean:
	rm -rf $(OBJECTS) libft.h.gch

fclean:
	rm -rf $(NAME)

re: fclean all

# Prevents confusing a flag's name for a file
.PHONY: all clean fclean re
