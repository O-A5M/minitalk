# minitalk variables:

CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC_CLIENT = client.c ft_atoi.c ft_putnbr.c
SRC_SERVER = server.c ft_atoi.c ft_putnbr.c
OBJS_CLIENT = $(SRC_CLIENT:.c=.o)
OBJS_SERVER = $(SRC_SERVER:.c=.o)
NAME_SERVER = server
NAME_CLIENT = client

# the rules:

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(NAME_CLIENT)

clean:
	rm -rf $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: clean
	rm -fr $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: clean
.SECONDARY: $(OBJS_SERVER) $(OBJS_CLIENT)
