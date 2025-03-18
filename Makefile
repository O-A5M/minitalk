# flags variables

CC = cc
CFLAGS = -Wall -Wextra -Werror

# mandatory variables

NAME = $(SERVER) $(CLIENT)
SRC_SERVER = server.c ft_putnbr_fd.c
SRC_CLIENT = client.c ft_atoi.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
SERVER = server
CLIENT = client

# bonus variables

SRC_SERVER_B = server_bonus.c ft_putnbr_fd_bonus.c
SRC_CLIENT_B = client_bonus.c ft_atoi_bonus.c
OBJ_SERVER_B = $(SRC_SERVER_B:.c=.o)
OBJ_CLIENT_B = $(SRC_CLIENT_B:.c=.o)
SERVER_B = server_bonus
CLIENT_B = client_bonus
NAME_B = $(SERVER_B) $(CLIENT_B)

# the rules

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(SERVER)

$(CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(CLIENT)

bonus: $(SERVER_B) $(CLIENT_B)

$(SERVER_B): $(OBJ_SERVER_B)
	$(CC) $(CFLAGS) $(OBJ_SERVER_B) -o $(SERVER_B)

$(CLIENT_B): $(OBJ_CLIENT_B)
	$(CC) $(CFLAGS) $(OBJ_CLIENT_B) -o $(CLIENT_B)

clean:
	rm -fr $(OBJ_CLIENT) $(OBJ_SERVER)
	rm -fr $(OBJ_CLIENT_B) $(OBJ_SERVER_B)

fclean: clean
	rm -fr $(NAME)
	rm -fr $(NAME_B)


re: fclean all

.PHONY: clean
.SECONDARY: $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_B) $(OBJ_CLIENT_B)
