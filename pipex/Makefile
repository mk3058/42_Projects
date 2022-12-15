NAME = pipex
CC = cc
CFALGS = -Wall -Wextra -Werror

GNL = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
FTPRINTF_DIR = ./ft_printf
FTPRINTF_LIB = libftprintf.a
LIBFT_DIR = ./libft
LIBFT_LIB = libft.a

SRCS_MANDATORY = $(GNL) pipex.c error_handler.c execute_cmd.c heredoc.c file_out.c
OBJS_MANDATORY = $(SRCS_MANDATORY:.c=.o)
#SRCS_BONUS = 
#OBJS_BONUS = 


all : $(NAME)

bonus : $(OBJS_BONUS)
	@make ft
	@make ftprintf
	@touch bonus
	@rm -f all
	$(CC) $(CFLAGS) $(SRCS_BONUS) -L$(LIBFT_DIR) -lft -L$(FTPRINTF_DIR) -lftprintf -o $(NAME)

$(NAME) : $(OBJS_MANDATORY)
	@make ft
	@make ftprintf
	@touch all
	@rm -f bonus
	$(CC) $(CFLAGS) $(SRCS_MANDATORY) -L$(LIBFT_DIR) -lft -L$(FTPRINTF_DIR) -lftprintf -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $(INC) -o $@ $<

ft : 
	@make -C $(LIBFT_DIR)

ftprintf : 
	@make -C $(FTPRINTF_DIR)

clean :
	@rm -f all
	@rm -f bonus
	@make -C $(LIBFT_DIR) fclean
	@make -C $(FTPRINTF_DIR) fclean
	rm -f $(OBJS_MANDATORY)
	rm -f $(OBJS_BONUS)
	
fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re ft ftprintf
