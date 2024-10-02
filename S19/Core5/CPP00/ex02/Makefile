# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/02 11:12:39 by quvan-de          #+#    #+#              #
#    Updated: 2024/10/02 11:12:43 by quvan-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Source files
SRCS = Account.cpp tests.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Output executable
EXEC = account_program

# Rules
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re

