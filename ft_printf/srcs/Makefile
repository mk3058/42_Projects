CC = cc
CFALGS = -Wall -Wextra -Werror
INC = -I ./libft/libft.h -I ./printf.h
NAME = libftprintf.a
SRCS = format_parser.c ft_printf.c print_hex.c print_nbr.c print_str.c print_va.c func.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

.c.o :
	$(CC) $(CFLAGS) -c $(INC) -o $@ $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re
