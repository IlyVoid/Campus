# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/22 14:58:31 by quvan-de          #+#    #+#              #
#    Updated: 2024/08/22 17:20:41 by quvan-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
OBJS_DIR = objs/
SRCS_DIR = src/
UTILS_DIR = utils/
HEADER = -I lib/

SRCS = $(SRCS_DIR)main.c \
      $(UTILS_DIR)ftlib.c \
      $(UTILS_DIR)parse_args.c \
      $(SRCS_DIR)philo_actions.c \
      $(SRCS_DIR)philo_states.c \
      $(SRCS_DIR)philo_threads.c \
      $(SRCS_DIR)simulation_init.c \
      $(SRCS_DIR)health_monitor.c \
      $(UTILS_DIR)print_status.c \
	  $(UTILS_DIR)utils.c \
	  $(UTILS_DIR)val_args.c

OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

# Colors
GREEN   = \033[0;92m
YELLOW  = \033[0;93m
RED     = \033[0;91m
WHITE   = \033[0;97m

# Targets
all: tmp $(NAME)

tmp:
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(CC) $(CFLAGS) $(HEADER) -c -o $@ $<
	@echo "$(GREEN)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(WHITE)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(HEADER) -o $(NAME) $(OBJS)
	@echo "$(GREEN)Philo Compiled! ᕦ($(RED)♥$(GREEN)_$(RED)♥$(GREEN))ᕤ$(WHITE)\n"

clean:
	@echo "$(RED)Deleting object files$(WHITE)"
	@rm -rf $(OBJS)

fclean: clean
	@echo "$(RED)Deleting executables$(WHITE)"
	@rm -rf $(NAME)
	@echo "\n$(RED)Deleting EVERYTHING! ⌐(ಠ۾ಠ)¬$(WHITE)\n"

re: fclean all

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
