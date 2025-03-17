# minitalk variables:

CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC_CLIENT = client.c ft_atoi.c
SRC_SERVER = server.c ft_atoi.c
OBJS_CLIENT = $(SRC_CLIENT:.o=.c)
OBJS_SERVER = $(SRC_SERVER:.o=.c)
NAME_SERVER = server
NAME_CLIENT = client

# the rules:

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(NAME_CLIENT)

clean: $(OBJS_CLIENT) $(OBJS_SERVER)
	rm -rf $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: clean
	rm -fr $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: clean
.SECONDARY: $(OBJS_SERVER) $(OBJS_CLIENT)
