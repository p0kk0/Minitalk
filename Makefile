NAME = minitalk.a

SERVER = server
CLIENT = client

SERVER_SRC = server.c
CLIENT_SRC = client.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f


$(SERVER): $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ)

$(CLIENT): $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ)

$(NAME): $(CLIENT) $(SERVER)

all: $(NAME)

clean:
	$(RM) $(SERVER_OBJ)
	$(RM) $(CLIENT_OBJ)

fclean: clean
	$(RM) $(SERVER)
	$(RM) $(CLIENT)

re: fclean
	$(MAKE)all

.PHONY: NAME all clean fclean re
