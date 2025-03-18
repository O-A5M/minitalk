# variables

NAME = $(SERVER) $(CLIENT)
SRC_SERVER = server.c ft_putnbr_fd.c
SRC_CLIENT = client.c ft_atoi.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
SERVER = server
CLIENT = client
CC = cc
CFLAGS = -Wall -Wextra -Werror

# the rules

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(SERVER)

$(CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(CLIENT)

clean:
	rm -fr $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	rm -fr $(NAME)

re: fclean all

.PHONY: clean
.SECONDARY: $(OBJ_SERVER) $(OBJ_CLIENT)
