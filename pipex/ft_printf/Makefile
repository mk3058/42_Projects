NAME = libftprintf.a
CC = cc
CFALGS = -Wall -Wextra -Werror
INC = -I ./libft/libft.h -I ./ft_printf_bonus.h
SRCS_MANDATORY = \
format_parser.c ft_printf.c print_hex.c print_nbr.c \
print_txt.c print_va.c func.c
OBJS_MANDATORY = $(SRCS_MANDATORY:.c=.o)
SRCS_BONUS = \
allocate_memory_bonus.c field_parser_bonus.c find_length_bonus.c format_parser_bonus.c \
ft_printf_bonus.c hex_to_string_bonus.c itoa_bonus.c nbr_to_string_bonus.c \
print_result_bonus.c print_va_bonus.c txt_to_string_bonus.c util_func_bonus.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
LIBFT_DIR = ./libft
LIBFT_LIB = libft.a

all : $(NAME)

bonus : $(OBJS_BONUS)
	make ft
	ar rc $(NAME) $(OBJS_BONUS)
	touch bonus

$(NAME) : $(OBJS_MANDATORY)
	ar rc $(NAME) $(OBJS_MANDATORY)
	touch all

%.o : %.c
	$(CC) $(CFLAGS) -c $(INC) -o $@ $<

ft : 
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT_LIB) ./$(NAME)
	make -C $(LIBFT_DIR) fclean

clean :
	rm -f $(OBJS_MANDATORY)
	rm -f $(OBJS_BONUS)

fclean : clean
	rm -f all
	rm -f bonus
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re ft
