NAME = push_swap
CC = cc
CFALGS = -Wall -Wextra -Werror

DEQUE = ./deque/deque.c ./deque/deque_func.c
GNL = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
LIBFT_DIR = ./libft
LIBFT_LIB = libft.a

INC = -I ./libft/libft.h -I ./deque.h -I ./push_swap.c -I ./get_next_line/get_next_line_h
SRCS_MANDATORY = $(DEQUE) command.c command2.c command3.c \
arguments.c error_handler.c push_swap.c sort.c count_cmd.c manual_sort.c func.c
OBJS_MANDATORY = $(SRCS_MANDATORY:.c=.o)
SRCS_BONUS = $(DEQUE) $(GNL) ./checker/checker.c command.c command2.c command3.c error_handler.c func.c arguments.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)


all : $(NAME)

bonus : $(OBJS_BONUS)
	make ft
	gcc $(SRCS_BONUS) -L$(LIBFT_DIR) -lft -o my_checker
	touch bonus
	rm all

$(NAME) : $(OBJS_MANDATORY)
	make ft
	gcc $(SRCS_MANDATORY) -L$(LIBFT_DIR) -lft -o $(NAME)
	touch all
	rm bonus

%.o : %.c
	$(CC) $(CFLAGS) -c $(INC) -o $@ $<

ft : 
	make -C $(LIBFT_DIR)
	make -C $(LIBFT_DIR) clean

clean :
	rm -f $(OBJS_MANDATORY)
	rm -f $(OBJS_BONUS)
	rm -f libft.a

fclean : clean
	rm -f all
	rm -f bonus
	rm -f libft.a
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re : fclean all

.PHONY : clean fclean re ft
