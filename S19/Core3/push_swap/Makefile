# Variables

NAME_MAN			= push_swap
NAME_BON			= checker
INCLUDE_MAN			= -I mandatory/include
INCLUDE_BON			= -I bonus/include
LIBFT				= libftplus
SRC_DIR_MAN			= mandatory/src/
SRC_DIR_BON			= bonus/src/
OBJ_DIR_MAN			= mandatory/obj/
OBJ_DIR_BON			= bonus/obj
CC					= cc
CFLAGS				= -Wall -Werror -Wextra -g
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

SRC_FILES_BON	=	checker push_instruct_bonus rev_rotate_instruct_bonus\
					rotate_instruct_bonus swap_instruct_bonus utils_bonus\

SRC_MAN 		= 	$(addprefix $(SRC_DIR_MAN), $(addsuffix .c, $(SRC_FILES_MAN)))
SRC_BON			=	$(addprefix $(SRC_DIR_BON), $(addsuffix .c, $(SRC_FILES_BON)))
OBJ_MAN 		= 	$(addprefix $(OBJ_DIR_MAN), $(addsuffix .o, $(SRC_FILES_MAN)))
OBJ_BON			=	$(addprefix $(OBJ_DIR_BON), $(addsuffix .o, $(SRC_FILES_BON)))

###

OBJF		=	.cache_exists

all:		$(NAME_MAN) $(NAME_BON)

$(NAME_MAN):	$(OBJ_MAN)
			@make -C $(LIBFT)
			@$(CC) $(CFLAGS) $(OBJ_MAN) -L$(LIBFT) -lftplus -o $(NAME_MAN)
			@echo "$(GREEN)push_swap compiled!$(DEF_COLOR)"

$(NAME_BON):	$(OBJ_BON)
			@make -C $(LIBFT)
			@$(CC) $(CFLAGS) $(OBJ_BON) -L$(LIBFT) -lftplus -o $(NAME_BON)
			@echo "$(GREEN)checker compiled!$(DEF_COLOR)"

$(OBJ_DIR_MAN)%.o: $(SRC_DIR_MAN)%.c | $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(INCLUDE_MAN) -c $< -o $@

$(OBJ_DIR_BON)%.o: $(SRC_DIR_BON)%.c | $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(INCLUDE_BON) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR_MAN) $(OBJ_DIR_BON)

clean:
			@$(RM) -rf $(OBJ_DIR_MAN) $(OBJ_DIR_BON)
			@make clean -C $(LIBFT)
			@echo "$(BLUE)push_swap and checker object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME_MAN) $(NAME_BON)
			@$(RM) -f $(LIBFT)/libftplus.a
			@echo "$(CYAN)push_swap executable files cleaned!$(DEF_COLOR)"
			@echo "$(CYAN)checker executable files cleaned!$(DEF_COLOR)"
			@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for push_swap and checker$(DEF_COLOR)"

.PHONY:		all clean fclean re

