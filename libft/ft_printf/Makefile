SRCS	=	ft_format_specifier.c ft_hexa_dealer.c ft_put_unsigned_nbr.c ft_printf.c \
			ft_putchar.c ft_putnbr.c ft_putstr.c
OBJS	=	$(SRCS:.c=.o)
CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -I.
AR		=	ar
ARFLAG	=	rcs
RM		=	rm -f
NAME	=	libftprintf.a

all:	$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(ARFLAG) $(NAME) $(OBJS)
clean:
			$(RM) $(OBJS)
fclean:	clean
			$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY:	all clean fclean re