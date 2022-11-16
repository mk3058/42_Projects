CC = cc
CFALGS = -Wall -Wextra -Werror
INC = -I ./libft/libft.h -I ./printf.h
NAME = libftprintf.a
SRCS = field_parser.c find_length.c format_parser.c ft_printf.c hex_to_string.c nbr_to_string.c txt_to_string.c print_txt.c print_va.c ft_itoa.c \
print_width.c allocate_memory.c input_check.c util_func.c \
./libft/ft_bzero.c ./libft/ft_atoi.c ./libft/ft_calloc.c ./libft/ft_isdigit.c ./libft/ft_strchr.c ./libft/ft_strlen.c ./libft/ft_memcpy.c ./libft/ft_memset.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

bonus : $(OBJS)
	rm -f all
	touch bonus
	ar rc $(NAME) $(OBJS)

$(NAME) : $(OBJS)
	rm -f bonus
	touch all
	ar rc $(NAME) $(OBJS)

.c.o :
	$(CC) $(CFLAGS) -c $(INC) -o $@ $<

clean :
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME)
	rm -f all
	rm -f bonus

re : fclean all

.PHONY : clean fclean re
