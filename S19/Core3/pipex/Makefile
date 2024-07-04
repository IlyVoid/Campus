# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/04 13:39:33 by quvan-de          #+#    #+#              #
#    Updated: 2024/07/04 15:16:03 by quvan-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Naming
PROG    = pipex
PROG_B  = pipex_bonus

SRC_DIR = src
OBJS_DIR = objs

SRCS    = $(SRC_DIR)/pipex.c $(SRC_DIR)/utils.c
SRCS_B  = $(SRC_DIR)/pipex_bonus.c $(SRC_DIR)/utils.c $(SRC_DIR)/utils_bonus.c
OBJS    = $(SRCS:$(SRC_DIR)/%.c=$(OBJS_DIR)/%.o)
OBJS_B  = $(SRCS_B:$(SRC_DIR)/%.c=$(OBJS_DIR)/%.o)

HEADER  = -Iinclude

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -g

# Colors
GREEN   = \033[0;92m
YELLOW  = \033[0;93m
RED     = \033[0;91m
WHITE   = \033[0;97m

.SILENT:

# Targets
all: tmp lib $(PROG)

bonus: tmp lib $(PROG_B)

lib:
	@echo "$(YELLOW)---- Compiling lib ----$(WHITE)"
	@make re -C ./libftplus

tmp:
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(HEADER) -c -o $@ $<
	@echo "$(GREEN)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(WHITE)"

$(PROG): $(OBJS)
	@$(CC) $(OBJS) -Llibftplus -lftplus -o $(PROG)
	@echo "$(GREEN)Pipex Compiled! ᕦ($(RED)♥$(GREEN)_$(RED)♥$(GREEN))ᕤ$(WHITE)\n"

$(PROG_B): $(OBJS_B)
	@$(CC) $(OBJS_B) -Llibftplus -lftplus -o $(PROG_B)
	@echo "$(GREEN)Pipex Bonus Compiled! ᕦ($(RED)♥$(GREEN)_$(RED)♥$(GREEN))ᕤ$(WHITE)\n"

clean:
	@echo "$(RED)Deleting object files$(WHITE)"
	@make clean -C ./libftplus
	@rm -rf $(OBJS) $(OBJS_B)

fclean: clean
	@echo "$(RED)Deleting executables$(WHITE)"
	@make fclean -C ./libftplus
	@rm -rf $(PROG)
	@rm -rf $(PROG_B)
	@echo "\n$(RED)Deleting EVERYTHING! ⌐(ಠ۾ಠ)¬$(WHITE)\n"

re: fclean all

re_bonus: fclean bonus

party:
	@printf "\033c"
	@echo "\n\033[35m♪┏(・o･)┛♪"
	@sleep 1
	@printf "\033c"
	@echo "\033[1;33m♪┗(・o･)┓♪"
	@sleep 1
	@printf "\033c"
	@echo "\n\033[36m♪┏(・o･)┛♪"
	@sleep 1
	@printf "\033c"
	@echo "\033[34m♪┗(・o･)┓♪\n"

.PHONY: all clean fclean re re_bonus bonus party

