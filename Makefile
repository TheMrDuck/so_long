SRC = main.c parser.c so_long_utils.c flood_fill.c

OBJ = $(SRC:.c=.o)

CC = cc
LIBFT = libft/libft.a
PRINTF = libft/ft_printf/libftprintf.a
CFLAGS = -Wall -Wextra -Werror -I. -Ilibft -Ilibft/ft_printf -g

NAME = so_long

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C libft/ft_printf

clean:
	rm -f $(OBJ)
	make -C libft clean
	make -C libft/ft_printf clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	make -C libft/ft_printf fclean

re: fclean all

.PHONY: all clean fclean re
