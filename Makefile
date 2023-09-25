NAME = minitalk

SERVER = server
CLIENT = client

SERVER_SRC = server.c
CLIENT_SRC = client.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)


LIBFT_DIR = "1. Libft"
PRINTF_DIR = "3. ft_printf"

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

MAKE = make

all: $(NAME)

$(SERVER): $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(LIBFT) $(PRINTF) $(SERVER_OBJ) -o $(SERVER)

$(CLIENT): $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(LIBFT) $(PRINTF) $(CLIENT_OBJ) -o $(CLIENT)

$(NAME): $(LIBFT) $(PRINTF) $(CLIENT) $(SERVER)

$(LIBFT): 
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	$(RM) $(SERVER_OBJ)
	$(RM) $(CLIENT_OBJ)

fclean: clean
	$(RM) $(SERVER)
	$(RM) $(CLIENT)

re: fclean
	$(MAKE) all

.PHONY: NAME all clean fclean re
