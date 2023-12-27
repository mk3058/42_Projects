# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD

# Binary name
BINARY_NAME ?= ex02

# Exclude sources
exclude_srcs ?=

# Find all cpp files and header files in the current directory and subdirectories
ifeq ($(exclude_srcs),)
SRCS = $(shell find ./ -name '*.cpp')
else
SRCS = $(shell find ./ -name '*.cpp' | grep -vE "$(exclude_srcs)")
endif

OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

# Include directories
INCDIRS = $(shell find ./ -type d)
INCFLAGS = $(addprefix -I,$(INCDIRS))

# Check if SRCS is empty
ifeq ($(SRCS),)
$(error No .cpp files found to compile)
endif

# Colors for progress bar
GREEN = \033[0;32m
NC = \033[0m

# Rule to compile everything
all: $(BINARY_NAME)

$(BINARY_NAME): $(OBJS)
	@echo "$(GREEN)Linking...$(NC)"
	@$(CXX) $(OBJS) -o $(BINARY_NAME)
	@echo "$(GREEN)Compilation finished!$(NC)"

-include $(DEPS)

%.o: %.cpp
	@echo "$(GREEN)Compiling $<...$(NC)"
	@$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $< -o $@

# Rule to clean object files and dependency files
clean:
	@echo "$(GREEN)Cleaning object files and dependency files...$(NC)"
	@rm -f $(OBJS) $(DEPS)

# Rule to clean everything
fclean: clean
	@echo "$(GREEN)Cleaning binary...$(NC)"
	@rm -f $(BINARY_NAME)

# Rule to recompile everything
re: fclean all

.PHONY: all clean fclean re
