NAME = pipex
BNAME = semaphore_pipex
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
SEMAPHORE =  \
	sutils.c
PAIRED = \
	putils.c

SMAIN = semaphore.c
PMAIN = paired.c

OBJ_DIR = objs
S_DIR = semaphore
P_DIR = paired

SOBJ = $(OBJ_DIR)/$(SMAIN:.c=.o)
POBJ = $(OBJ_DIR)/$(PMAIN:.c=.o)
SSOBJ = $(addprefix $(OBJ_DIR)/, $(SEMAPHORE:.c=.o))
PPOBJ = $(addprefix $(OBJ_DIR)/, $(PAIRED:.c=.o))

all: $(SOBJ) $(POBJ) $(SSOBJ) $(PPOBJ) compile_s compile_p

$(OBJ_DIR)/%.o: $(S_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(P_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

compile_p:
	$(CC) $(CFLAGS) $(SOBJ) $(SSOBJ) -o $(NAME)

compile_s:
	$(CC) $(CFLAGS) $(POBJ) $(PPOBJ) -o $(BNAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME) $(BNAME)

re: fclean all

.PHONY: all compile_s compile_p fclean clean re bonus $(NAME) $(BNAME)
