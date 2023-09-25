NAME = minitalk

SERVER = server
CLIENT = client

SERVER_SRC = server.c
CLIENT_SRC = client.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)


LIBS = -l "1. Libft/libft.a" "3. ft_printf/libftprintf.a"

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

MAKE = make

all: $(NAME)

$(SERVER): $(SERVER_OBJ)
	$(CC) $(CFLAGS) "1. Libft/libft.a" "3. ft_printf/libftprintf.a" $(SERVER_OBJ) -o $(SERVER)

$(CLIENT): $(CLIENT_OBJ)
	$(CC) $(CFLAGS) "1. Libft/libft.a" "3. ft_printf/libftprintf.a" $(CLIENT_OBJ) -o $(CLIENT)

$(NAME): $(CLIENT) $(SERVER)


clean:
	$(RM) $(SERVER_OBJ)
	$(RM) $(CLIENT_OBJ)

fclean: clean
	$(RM) $(SERVER)
	$(RM) $(CLIENT)

re: fclean
	$(MAKE) all

.PHONY: NAME all clean fclean re
