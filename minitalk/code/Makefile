CC = cc
CFLAGS = -g -Wall -Wextra -Werror
SERVER =  \
	sutils.c
CLIENT = \
	cutils.c

SMAIN = server.c
CMAIN = client.c

OBJ_DIR = objs
LIB_DIR = printf
SERVER_DIR = server_src
CLIENT_DIR = client_src

SOBJ = $(OBJ_DIR)/$(SMAIN:.c=.o)
COBJ = $(OBJ_DIR)/$(CMAIN:.c=.o)
SSOBJ = $(addprefix $(OBJ_DIR)/, $(SERVER:.c=.o))
CCOBJ = $(addprefix $(OBJ_DIR)/, $(CLIENT:.c=.o))

all: $(SOBJ) $(COBJ) $(SSOBJ) $(CCOBJ) libmake compile_s compile_c

$(OBJ_DIR)/%.o: $(SERVER_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(CLIENT_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

compile_s:
	$(CC) $(CFLAGS) $(SOBJ) $(SSOBJ) ./$(LIB_DIR)/libftprintf.a -o server

compile_c:
	$(CC) $(CFLAGS) $(COBJ) $(CCOBJ) ./$(LIB_DIR)/libftprintf.a -o client

run: all
	./server

test: bonus
	./client

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

libmake:
	make bonus -C $(LIB_DIR) > /dev/null 2>&1

clean:
	make -C $(LIB_DIR) fclean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf server client

re: fclean all

.PHONY: all compile_s compile_c fclean clean re bonus libmake test run $(NAME) $(BNAME)
