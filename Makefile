# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 10:04:27 by ltheveni          #+#    #+#              #
#    Updated: 2024/12/07 10:15:27 by ltheveni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_GREY	= \033[30m
_RED	= \033[31m
_GREEN	= \033[32m
_YELLOW	= \033[33m
_BLUE	= \033[34m
_PURPLE	= \033[35m
_CYAN	= \033[36m
_WHITE	= \033[37m
_END	= \033[0m

NAME = push_swap
NAME_BONUS = checker
LIBFT = libft
SRC_DIR = srcs/
SRC_BONUS_DIR = bonus/
OBJ_DIR = objs/
OBJ_BONUS_DIR = $(OBJ_DIR)bonus/
LIB_DIR = libft/

# Config
SHELL = /bin/bash
CC = gcc

INCLUDE = -I includes
CFLAGS = -Wall -Werror -Wextra
LIBFLAGS = -L $(LIB_DIR) -lft
RM = rm -rf

# C program
SRCS = $(shell find $(SRC_DIR) -name '*.c')
OBJS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

SRCS_BONUS = $(shell find $(SRC_BONUS_DIR) -name '*.c')
OBJS_BONUS = $(patsubst $(SRC_BONUS_DIR)%.c, $(OBJ_BONUS_DIR)%.o, $(SRCS_BONUS))

# Recipe
all: $(LIBFT) $(NAME)

bonus: $(LIBFT) $(NAME_BONUS)

$(NAME): $(LIB_DIR)/$(LIBFT).a $(OBJS)
	@printf "$(_END)\nCompiled source files\n"
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBFLAGS) -o $@
	@printf "$(_GREEN)Finish compiling $(NAME)!\n"
	@printf "Try \"./$(NAME)\" to use$(_END)\n"

$(NAME_BONUS): $(LIB_DIR)/$(LIBFT).a $(OBJS_BONUS)
	@printf "$(_END)\nCompiled source files\n"
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS_BONUS) $(LIBFLAGS) -o $@
	@printf "$(_GREEN)Finish compiling $(NAME_BONUS)!\n"
	@printf "Try \"./$(NAME_BONUS)\" to use$(_END)\n"

$(LIBFT):
	@make -C $(LIB_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@printf "$(_GREEN)█$(_END)"

$(OBJ_BONUS_DIR)%.o: $(SRC_BONUS_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@printf "$(_GREEN)█$(_END)"

clean:
	@printf "$(_YELLOW)Removing object files ...$(_END)\n"
	@make clean -C $(LIB_DIR)
	@$(RM) $(OBJ_DIR)

fclean:
	@printf "$(_RED)Removing object files and program ...$(_END)\n"
	@make fclean -C $(LIB_DIR)
	@$(RM) $(NAME) $(NAME_BONUS) $(OBJ_DIR)

re: fclean all

.PHONY: all bonus clean fclean re libft
