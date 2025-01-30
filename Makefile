# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 18:06:37 by eguelin           #+#    #+#              #
#    Updated: 2025/01/30 16:15:15 by eguelin          ###   ########.fr        #
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
STR_DIR		= string/
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
INCS		= -I $(INCS_DIR)
INCS_UTILS	= $(INCS) -I $(INCS_DIR)$(UTILS_DIR)
ARC			= ar rcs
PRINT		= @printf
RM			= rm -fr

# ********************************   tests   ********************************* #

TESTS		= test
TESTS_DIR	= tests/
INCS_TESTS	= $(INCS) -I $(INCS_DIR)$(TESTS_DIR)
LIB			= -L. -lft

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

# ********************************   tests   ********************************* #

COMP_TEST_MSG	= "$(GREEN)Compilation $(TESTS) $(DEFAULT)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(DEFAULT)\n"
CLEAN_TEST_MSG	= "$(RED)Cleaning $(TESTS) $(DEFAULT)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(DEFAULT)\n"
FULL_CLEAN_TEST_MSG	= "$(PURPLE)Full cleaning $(TESTS) $(DEFAULT)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(DEFAULT)\n"

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

STR_FILES	= ft_strchr.c \
			  ft_strcmp.c \
			  ft_strcpy.c \
			  ft_strlcpy.c \
			  ft_strlen.c \
			  ft_strncmp.c \
			  ft_strncpy.c

ALL_FILES 	+= $(addprefix $(STR_DIR), $(STR_FILES))

OBJS_FILES	= $(addprefix $(OBJS_DIR), $(ALL_FILES:.c=.o))

DEP_FILES	= $(OBJS_FILES:.o=.d)

OBJS_DIRS	= $(sort $(dir $(OBJS_FILES)))

# ********************************   tests   ********************************* #

TESTS_FILES	= test.c \
			  test_utils.c

OBJS_TESTS_FILES	= $(addprefix $(OBJS_DIR)$(TESTS_DIR), $(TESTS_FILES:.c=.o))

DEP_TESTS_FILES	= $(OBJS_TESTS_FILES:.o=.d)

OBJS_TESTS_DIRS	= $(sort $(dir $(OBJS_TESTS_FILES)))

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

# ********************************   tests   ********************************* #

all_$(TESTS): $(TESTS)

$(TESTS): all $(OBJS_TESTS_FILES)
	$(CC) $(CFLAGS) $(INCS_TESTS) $(OBJS_TESTS_FILES) $(LIB) -o $(TESTS)
	$(PRINTF) $(TESTS_MSG)
	./$(TESTS)

$(OBJS_DIR)$(TESTS_DIR)%.o: $(TESTS_DIR)%.c | $(OBJS_DIR)$(TESTS_DIR)
	$(CC) $(CFLAGS) $(INCS_TESTS) -MMD -MP -c $<  -o $@

$(OBJS_DIR)$(TESTS_DIR):
	mkdir -p $@


clean_$(TESTS):
	$(RM) $(OBJS_DIR)$(TESTS_DIR)
	$(PRINTF) $(TESTS_CLEAN_MSG)

fclean_$(TESTS): clean_$(TESTS)
	$(RM) $(TESTS)
	$(PRINTF) $(TESTS_FULL_CLEAN_MSG)

re_$(TESTS): fclean all_$(TESTS)


-include $(DEP_FILES) $(DEP_TESTS_FILES)
