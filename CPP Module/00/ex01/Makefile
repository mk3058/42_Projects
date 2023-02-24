CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
TARGET = PhoneBook

SRCS = Contact.cpp PhoneBook.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

HEADER_DIR = ./

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