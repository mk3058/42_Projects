CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
TARGET = megaphone

SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

%.o : %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CXXFLAGS) $^ -o $@

all : $(NAME)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(OBJS) $(TARGET)

re: fclean all

.PHONY : all clean fclean re