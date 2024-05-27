# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 15:18:15 by quvan-de          #+#    #+#              #
#    Updated: 2024/05/27 14:50:08 by quvan-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME		= libftplus.a
INCLUDES	= include
SRCS_DIR 	= src/
OBJS_DIR    = obj/
CC        	= gcc
CFLAGS    	= -Wall -Werror -Wextra -I
RM        	= rm -f
AR        	= ar rcs

# Colors
DEF_COLOR 	= \033[0;39m
GRAY      	= \033[0;90m
RED       	= \033[0;91m
GREEN     	= \033[0;92m
YELLOW    	= \033[0;93m
BLUE      	= \033[0;94m
MAGENTA   	= \033[0;95m
CYAN      	= \033[0;96m
WHITE     	= \033[0;97m

# Sources
FTIS_DIR   	= checks/
FTIS       	= ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint

FTMEM_DIR  	= memory/
FTMEM      	= ft_bzero ft_calloc ft_memchr ft_memcmp ft_memmove ft_memset \
			 ft_clear_array

FTPUT_DIR  	= fd/
FTPUT      	= ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd

FTTO_DIR   	= converter/
FTTO       	= ft_atoi ft_itoa ft_tolower ft_toupper

FTSTR_DIR  	= string/
FTSTR      	= ft_split ft_strchr ft_strdup ft_striteri ft_strjoin \
             ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp \
             ft_strnstr ft_strrchr ft_strtrim ft_substr ft_strcmp	\
             ft_strjoin_free

FTLST_DIR  	= lists/
FTLST      	= ft_lstadd_back ft_lstadd_front ft_lstclear ft_lstdelone \
             ft_lstiter ft_lstlast ft_lstmap ft_lstnew ft_lstsize

FTPRINT_DIR = printf/
FTPRINT     = ft_hex ft_letters ft_nbrs ft_printf ft_putptr

FTNEXT_DIR  = next_line/
FTNEXT      = get_next_line get_next_line_utils

SRC_FILES += $(addprefix $(FTIS_DIR),$(FTIS))
SRC_FILES += $(addprefix $(FTMEM_DIR),$(FTMEM))
SRC_FILES += $(addprefix $(FTPUT_DIR),$(FTPUT))
SRC_FILES += $(addprefix $(FTTO_DIR),$(FTTO))
SRC_FILES += $(addprefix $(FTSTR_DIR),$(FTSTR))
SRC_FILES += $(addprefix $(FTLST_DIR),$(FTLST))
SRC_FILES += $(addprefix $(FTPRINT_DIR),$(FTPRINT))
SRC_FILES += $(addprefix $(FTNEXT_DIR),$(FTNEXT))

SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF        = .cache_exists

all: 		$(NAME)

$(NAME): 	$(OBJS)
			@$(AR) $(NAME) $(OBJS)
			@ranlib $(NAME)
			@echo "$(GREEN)Libftplus compiled!$(DEF_COLOR)"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c | $(OBJF)
			@mkdir -p $(@D)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJS_DIR)
			@mkdir -p $(OBJS_DIR)$(FTIS_DIR)
			@mkdir -p $(OBJS_DIR)$(FTMEM_DIR)
			@mkdir -p $(OBJS_DIR)$(FTPUT_DIR)
			@mkdir -p $(OBJS_DIR)$(FTTO_DIR)
			@mkdir -p $(OBJS_DIR)$(FTSTR_DIR)
			@mkdir -p $(OBJS_DIR)$(FTLST_DIR)
			@mkdir -p $(OBJS_DIR)$(FTPRINT_DIR)
			@mkdir -p $(OBJS_DIR)$(FTNEXT_DIR)

clean:
			@$(RM) -rf $(OBJS_DIR)
			@echo "$(BLUE)libft obj files cleaned!$(DEF_COLOR)"

fclean: 	clean
			@$(RM) -f $(NAME)
			@echo "$(CYAN)libft lib files cleaned!$(DEF_COLOR)"

re: 		fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for libftplus!$(DEF_COLOR)"

norm:
			@norminette $(SRCS) $(INCLUDES) | grep -v Norme -B1 || true

.PHONY: all clean fclean re norm
