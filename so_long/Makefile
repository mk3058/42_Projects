NAME = so_long
CC = CC
CFLAGS = -Wall -Wextra -Werror

GNL = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
FTPRINTF_DIR = ./ft_printf
FTPRINTF_LIB = libftprintf.a
LIBFT_DIR = ./libft
LIBFT_LIB = libft.a
MLX_DIR = ./mlx
MLX_LIB = mlx -framework OpenGL -framework Appkit

SRCS_MANDATORY = $(GNL) error_handler.c map_parser.c init_game.c so_long.c hook_handler.c
OBJS_MANDATORY = $(SRCS_MANDATORY:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS_MANDATORY)
	@make ft
	@make ftprintf
	@make mlx
	$(CC) $(CFLAGS) $(SRCS_MANDATORY) -L$(LIBFT_DIR) -lft -L$(FTPRINTF_DIR) -lftprintf \
	-L$(MLX_DIR) -l$(MLX_LIB) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $(INC) -o $@ $<

ft : 
	@make -C $(LIBFT_DIR)

ftprintf : 
	@make -C $(FTPRINTF_DIR)

mlx :
	@make -C $(MLX_DIR)

clean :
	@make -C $(LIBFT_DIR) fclean
	@make -C $(FTPRINTF_DIR) fclean
	@make -C $(MLX_DIR) clean
	rm -f $(OBJS_MANDATORY)
	
fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re ft ftprintf mlx