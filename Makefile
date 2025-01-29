# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 18:06:37 by eguelin           #+#    #+#              #
#    Updated: 2025/01/29 18:46:20 by eguelin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

# **************************************************************************** #
#                                   Variable                                   #
# **************************************************************************** #

NAME		= libft.a
OBJS_DIR	= .objs/
SRCS_DIR	= srcs/
INCS_DIR	= includes/
UTILS_DIR	= utils/
PRINT_DIR	= print/
STR_DIR		= str/
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
INCS		= -I $(INCS_DIR)
INCS_UTILS	= $(INCS) -I $(INCS_DIR)$(UTILS_DIR)
ARC			= ar rcs
PRINT		= @printf
LIB			= -L. -lft
RM			= rm -fr

# **************************************************************************** #
#                                    Colors                                    #
# **************************************************************************** #

BLACK	= \033[30m
RED		= \033[31m
GREEN	= \033[32m
YELLOW	= \033[33m
BLUE	= \033[34m
PURPLE	= \033[35m
CYAN	= \033[36m
WHITE	= \033[37m
DEFAULT	= \033[0m

# **************************************************************************** #
#                                    Message                                   #
# **************************************************************************** #

COMP_MSG		= "$(GREEN)Compilation $(NAME) $(DEFAULT)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(DEFAULT)\n"
CLEAN_MSG		= "$(RED)Cleaning $(NAME) $(DEFAULT)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(DEFAULT)\n"
FULL_CLEAN_MSG	= "$(PURPLE)Full cleaning $(NAME) $(DEFAULT)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(DEFAULT)\n"

# **************************************************************************** #
#                                    Sources                                   #
# **************************************************************************** #

UTILS_FILES	= ft_put_arg_buff.c \
			  ft_put_char_buff.c \
			  ft_put_hex_buff.c \
			  ft_put_hexup_buff.c \
			  ft_put_long_buff.c \
			  ft_put_ptr_buff.c \
			  ft_put_str_buff.c \
			  ft_put_ulong_buff.c \
			  ft_put_ulongb_buff.c \
			  ft_getarg.c \
			  ft_init_pf.c \
			  ft_write_pf.c \
			  ft_print_loop.c

ALL_FILES	= $(addprefix $(UTILS_DIR), $(UTILS_FILES))

PRINT_FILES	= ft_printf.c \
			  ft_dprintf.c \
			  ft_sprintf.c \
			  ft_snprintf.c

ALL_FILES 	+= $(addprefix $(PRINT_DIR), $(PRINT_FILES))

STR_FILES	= ft_strlen.c \
			  ft_strchr.c

ALL_FILES 	+= $(addprefix $(STR_DIR), $(STR_FILES))

OBJS_FILES	= $(addprefix $(OBJS_DIR), $(ALL_FILES:.c=.o))

DEP_FILES	= $(OBJS_FILES:.o=.d)

OBJS_DIRS	= $(sort $(dir $(OBJS_FILES)))

# **************************************************************************** #
#                                     Rules                                    #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS_FILES)
	$(ARC) $(NAME) $(OBJS_FILES)
	$(PRINT) $(COMP_MSG)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIRS)
	$(CC) $(CFLAGS) $(INCS_UTILS) -MMD -MP -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)
	$(PRINT) $(CLEAN_MSG)

fclean: clean
	$(RM) $(NAME)
	$(RM) test
	$(PRINT) $(FULL_CLEAN_MSG)

re: fclean all

$(OBJS_DIRS):
	mkdir -p $@

-include $(DEP_FILES)
