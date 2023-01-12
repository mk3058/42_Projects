NAME = philo
CC = CC
CFLAGS = -Wall -Wextra -Werror

SRCS_MANDATORY = philo.c thread.c monitor.c func.c func2.c
OBJS_MANDATORY = $(SRCS_MANDATORY:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS_MANDATORY)
	$(CC) $(CFLAGS) $(SRCS_MANDATORY) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $(INC) -o $@ $<

clean :
	rm -f $(OBJS_MANDATORY)
	
fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re