# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 10:04:27 by ltheveni          #+#    #+#              #
#    Updated: 2024/11/29 10:43:40 by ltheveni         ###   ########.fr        #
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
LIBFT = libft
SRC_DIR = srcs/
OBJ_DIR = objs/
LIB_DIR = libft/

# Config
SHELL = /bin/bash
CC = gcc

INCLUDE = -I includes
CFLAGS = -Wall -Werror -Wextra
LIBFLAGS = -L $(LIB_DIR) -lft
RM = rm -rf

# C program
SRCS = $(shell find $(SRC_DIR) -name '*.c' | xargs basename -a)
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

# Recipe
all: $(LIBFT) $(NAME)

$(NAME): $(LIB_DIR)/$(LIBFT).a $(OBJS)
	@printf "$(_END)\nCompiled source files\n"
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBFLAGS) -o $@
	@printf "$(_GREEN)Finish compiling $(NAME)!\n"
	@printf "Try \"./$(NAME)\" to use$(_END)\n"

$(LIBFT):
	@make -C $(LIB_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@if [ ! -d $(OBJ_DIR) ];then mkdir $(OBJ_DIR); fi
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@printf "$(_GREEN)█$(_END)"

clean:
	@printf "$(_YELLOW)Removing object files ...$(_END)\n"
	@make clean -C $(LIB_DIR)
	@$(RM) $(OBJ_DIR)

fclean:
	@printf "$(_RED)Removing object files and program ...$(_END)\n"
	@make fclean -C $(LIB_DIR)
	@$(RM) $(NAME) $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re libft
