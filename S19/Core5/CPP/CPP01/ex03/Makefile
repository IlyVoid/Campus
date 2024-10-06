# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/06 18:45:43 by quvan-de          #+#    #+#              #
#    Updated: 2024/10/06 18:47:19 by quvan-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the final executable
NAME = human_attack

# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Source files and corresponding object files
SRCS = main.cpp Implementation/Weapon.cpp Implementation/HumanA.cpp Implementation/HumanB.cpp
OBJS = $(SRCS:.cpp=.o)

# Rule to link the object files and create the final executable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "[DEBUG] Build complete: $(NAME) has been created."

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJS)
	@echo "[DEBUG] Object files cleaned up."

# Clean up everything, including the final executable
fclean: clean
	rm -f $(NAME)
	@echo "[DEBUG] All files cleaned, including executable."

# Rebuild the project from scratch
re: fclean $(NAME)

# Define .PHONY to avoid conflicts with files named clean, fclean, or re
.PHONY: clean fclean re
