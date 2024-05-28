# Variables

NAME_MAN			= push_swap
INCLUDE_MAN			= -I mandatory/include
LIBFT				= libftplus
SRC_DIR_MAN			= mandatory/src/
OBJ_DIR_MAN			= mandatory/obj/
CC					= cc
CFLAGS				= -Wall -Werror -Wextra -g -fsanitize=address
RM					= rm -rf
AR					= ar rcs

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Sources

SRC_FILES_MAN	=	index main push_instruct quick_sort rev_rotate_instruct\
					rotate_instruct swap_instruct sort_handling sort_utils\


SRC_MAN 		= 	$(addprefix $(SRC_DIR_MAN), $(addsuffix .c, $(SRC_FILES_MAN)))
OBJ_MAN 		= 	$(addprefix $(OBJ_DIR_MAN), $(addsuffix .o, $(SRC_FILES_MAN)))

###

OBJF			=	.cache_exists

all:		$(NAME_MAN) $(NAME_BON)

$(NAME_MAN):	$(OBJ_MAN)
			@make -C $(LIBFT)
			@$(CC) $(CFLAGS) $(OBJ_MAN) -L$(LIBFT) -lftplus -o $(NAME_MAN)
			@echo "$(GREEN)push_swap compiled!$(DEF_COLOR)"

$(OBJ_DIR_MAN)%.o: $(SRC_DIR_MAN)%.c | $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(INCLUDE_MAN) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR_MAN)

clean:
			@$(RM) -rf $(OBJ_DIR_MAN)
			@make clean -C $(LIBFT)
			@echo "$(BLUE)push_swap and checker object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME_MAN)
			@$(RM) -f $(LIBFT)/libftplus.a
			@echo "$(CYAN)push_swap executable files cleaned!$(DEF_COLOR)"
			@echo "$(CYAN)checker executable files cleaned!$(DEF_COLOR)"
			@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for push_swap and checker$(DEF_COLOR)"

.PHONY:		all clean fclean re

