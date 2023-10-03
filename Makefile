NAME = minitalk

SERVER = server
CLIENT = client

SERVER_SRC = server.c
CLIENT_SRC = client.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

SERVER_BONUS_SRC = server_bonus.c
CLIENT_BONUS_SRC = client_bonus.c

SERVER_BONUS_OBJ = $(SERVER_BONUS_SRC:.c=.o)
CLIENT_BONUS_OBJ = $(CLIENT_BONUS_SRC:.c=.o)

LIBFT_DIR = libft
PRINTF_DIR = ft_printf

LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
MAKE = make

all: $(NAME)

$(SERVER): $(LIBFT) $(PRINTF) $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(LIBFT) $(PRINTF) $(SERVER_OBJ) -o $(SERVER)

$(CLIENT): $(LIBFT) $(PRINTF) $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(LIBFT) $(PRINTF) $(CLIENT_OBJ) -o $(CLIENT)

$(NAME): $(LIBFT) $(PRINTF) $(CLIENT) $(SERVER)

$(LIBFT): 
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	$(RM) $(SERVER_OBJ)
	$(RM) $(CLIENT_OBJ)
	$(RM) $(SERVER_BONUS_OBJ)
	$(RM) $(CLIENT_BONUS_OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)

fclean: clean
	$(RM) $(SERVER)
	$(RM) $(CLIENT)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)

re: fclean
	$(MAKE) all

bonus: $(LIBFT) $(PRINTF) $(SERVER_BONUS_OBJ) $(CLIENT_BONUS_OBJ)
	$(CC) $(CFLAGS) $(LIBFT) $(PRINTF) $(SERVER_BONUS_OBJ) -o $(SERVER)
	$(CC) $(CFLAGS) $(LIBFT) $(PRINTF) $(CLIENT_BONUS_OBJ) -o $(CLIENT)

.PHONY: all NAME clean fclean re bonus
