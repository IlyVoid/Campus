# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 12:50:17 by quvan-de          #+#    #+#              #
#    Updated: 2024/06/24 12:59:38 by quvan-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Naming
NAME = fdf

SRC_DIR = src
OBJS_DIR = objs

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

HEADER = $(wildcard includes/*.h)

INCS = -I includes

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

MINILIBX = minilibx-linux

FMS = -L $(MINILIBX) -lmlx -L/usr/X11R6/lib -lXext -lX11 -lm

# Colors
GREEN = \033[0;92m
BLUE = \033[0;94m
RED = \033[0;91m
WHITE = \033[0;97m

.SILENT:

# Targets
all: mlx tmp $(NAME)

mlx:
	@echo "$(GREEN)Building minilibx-linux$(WHITE)"
	@make -C $(MINILIBX)

tmp:
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@$(CC) $(CFLAGS) $(INCS) -c -o $@ $<
	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(WHITE)"

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(FMS)
	@echo "$(GREEN)Project successfully compiled$(WHITE)"

clean:
	@echo "$(RED)Deleting object files$(WHITE)"
	@$(RM) -rf $(OBJS_DIR)
	@make clean -C $(MINILIBX)

fclean: clean
	@echo "$(RED)Deleting executable$(WHITE)"
	@$(RM) -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re mlx tmp
