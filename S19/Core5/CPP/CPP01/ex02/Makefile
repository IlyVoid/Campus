# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/06 18:02:33 by quvan-de          #+#    #+#              #
#    Updated: 2024/10/06 18:03:32 by quvan-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = brainProgram
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

# Source files
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Compile source files into object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS)

# Clean object files and the program
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Phony targets to prevent file name conflicts
.PHONY: all clean fclean re
