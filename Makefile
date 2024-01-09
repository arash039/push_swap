# Compiler and compiler flags
CC = 		cc
CFLAGS = 	-Wall -Werror -Wextra
VFLAGS = 	-g -Wall

# Target executable
NAME = 		push_swap

# Source files
SRCS = 		list_utils.c\
			 main.c\
			 operation_a.c\
			 operation_b.c\
			 push_swap.c\
			 calculator.c\
			 sort_utils.c\
			 sort.c\
			 operation_joint.c\
			 base_utils.c\
			 printf_utils.c\
			 input_check.c\
			 rotator.c

# Object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(NAME)

# Rule to build the executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ 

# Rule to compile source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to check memory leak
VALGRIND: CFLAGS = $(VFLAGS)
VALGRIND: $(NAME)
	valgrind --leak-check=full ./$(NAME) 

# Run the program with arguments
run:
	./$(NAME) $(ARGS)

# Clean
clean:
	rm -f $(OBJS) $(NAME)

