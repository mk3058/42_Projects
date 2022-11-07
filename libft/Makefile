CC = cc
NAME = libft.a
SRCS = ft_isalnum.c ft_isprint.c ft_strlcpy.c ft_tolower.c ft_isalpha.c ft_memchr.c ft_memset.c ft_strlen.c ft_toupper.c ft_atoi.c ft_isascii.c ft_memcmp.c ft_strchr.c ft_strncmp.c ft_bzero.c ft_isdigit.c ft_memcpy.c ft_strlcat.c ft_strnstr.c
OBJS = $(SRCS:.c=.o)
INC = ./
CFALGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

.c.o :
	$(CC) $(CFLAGS) -c -I $(INC) -o $@ $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re