NAME = fdf
INCLUDES = include
SRCS_DIR = src
OBJS_DIR = objs
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
LIBFT = libftplus
MLX = minilibx-linux

# Sources
SOURCES = map_reader.c map_size.c \
          calc.c draw.c mlx.c fdf.c \
          errors.c helpers.c draw_helper.c
SRCS = $(addprefix $(SRCS_DIR)/,$(SOURCES))
OBJS = $(addprefix $(OBJS_DIR)/,$(SOURCES:.c=.o))

# Colors
GREEN = \033[0;92m
BLUE = \033[0;94m
RED = \033[0;91m
WHITE = \033[0;97m

# Targets
all: lib mlx tmp $(NAME)

lib:
	@echo "$(GREEN)Creating libftplus files$(WHITE)"
	@make -C $(LIBFT)

mlx:
	@echo "$(GREEN)Cloning and building minilibx-linux$(WHITE)"
	@if [ ! -d "$(MLX)" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX); \
	fi
	@make -C $(MLX)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT) -L$(MLX) -lftplus -lm -lmlx -lXext -lX11
	@echo "$(GREEN)Project successfully compiled$(WHITE)"

tmp:
	@mkdir -p objs

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES)/$(NAME).h
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(WHITE)"

clean:
	@echo "$(RED)Deleting object files$(WHITE)"
	@$(RM) $(OBJS_DIR)
	@make clean -C $(LIBFT)
	@make clean -C $(MLX)

fclean: clean
	@echo "$(RED)Deleting executable and libraries$(WHITE)"
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT)
	@echo "$(RED)All files cleaned with fclean$(WHITE)"
	@echo "$(RED)Deleting minilibx-linux repository$(WHITE)"
	@$(RM) $(MLX)

re: fclean all

.PHONY: all clean fclean re lib mlx tmp
