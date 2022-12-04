NAME = push_swap
CC = cc
CFALGS = -Wall -Wextra -Werror
INC = -I ./libft/libft.h -I ./deque.h -I ./push_swap.c
SRCS_MANDATORY = arguments.c command.c command2.c command3.c \
deque.c deque_func.c error_handler.c push_swap.c sort.c
OBJS_MANDATORY = $(SRCS_MANDATORY:.c=.o)
#SRCS_BONUS =
#OBJS_BONUS = $(SRCS_BONUS:.c=.o)
LIBFT_DIR = ./libft
LIBFT_LIB = libft.a

all : $(NAME)

bonus : $(OBJS_BONUS)
	make ft
	ar rc $(NAME) $(OBJS_BONUS)
	touch bonus

$(NAME) : $(OBJS_MANDATORY)
	make ft
	gcc $(SRCS_MANDATORY) -L. -lft -o $(NAME)
	touch all

%.o : %.c
	$(CC) $(CFLAGS) -c $(INC) -o $@ $<

ft : 
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT_LIB) ./$(LIBFT_LIB)
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
