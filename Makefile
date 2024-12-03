SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -D_DEFAULT_SOURCE

LIBFT_DIR = libft
PRINTF_DIR = printf

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

all: server client

bonus: server client

server: server.o $(LIBFT) $(PRINTF)
	$(CC) -o $@ $< -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

client: client.o $(LIBFT) $(PRINTF)
	$(CC) -o $@ $< -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

%.o: %.c
	$(CC) -c $(CFLAGS) $<

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

clean:
	rm -f $(OBJECTS)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f server client $(LIBFT) $(PRINTF)

re: fclean all

.PHONY: all bonus libft printf clean fclean re
