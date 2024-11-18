# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timatias <timatias@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 18:18:29 by timatias          #+#    #+#              #
#    Updated: 2024/11/18 06:15:14 by timatias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude
READLINE_FLAGS = -lreadline

SRCS = src/main.c src/prompt.c src/parser.c src/executor.c \
       src/builtins/ft_echo.c src/builtins/ft_cd.c src/builtins/ft_pwd.c src/builtins/ft_ls.c \
       src/utils/utils.c src/utils/utils01.c src/utils/ft_strcpy.c 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(READLINE_FLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
