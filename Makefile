# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timatias <timatias@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 04:07:36 by timatias          #+#    #+#              #
#    Updated: 2024/11/20 16:02:48 by timatias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timatias <timatias@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 04:07:36 by timatias          #+#    #+#              #
#    Updated: 2024/11/20 04:08:28 by timatias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timatias <timatias@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 04:07:36 by timatias          #+#    #+#              #
#    Updated: 2024/11/20 04:08:28 by timatias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror -I include
LDFLAGS = -lreadline -L/opt/homebrew/opt/readline/lib -I/opt/homebrew/opt/readline/include

LIBFT = libft/libft.a
FT_PRINTF = libft/ft_printf/libftprintf.a

INCLUDE = include
SRC_DIR = src
BUILTINS = $(SRC_DIR)/builtins
ENV = $(SRC_DIR)/env
EXEC = $(SRC_DIR)/exec
MAIN = $(SRC_DIR)/main
PARSING = $(SRC_DIR)/parsing
TOOLS = $(SRC_DIR)/tools

SRCS = $(wildcard $(BUILTINS)/*.c) $(wildcard $(ENV)/*.c) \
       $(wildcard $(EXEC)/*.c) $(wildcard $(MAIN)/*.c) \
       $(wildcard $(PARSING)/*.c) $(wildcard $(TOOLS)/*.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(FT_PRINTF) $(LDFLAGS)

$(LIBFT):
	@make -C libft

$(FT_PRINTF):
	@make -C libft/ft_printf

clean:
	rm -f $(OBJS)
	@make clean -C libft
	@make clean -C libft/ft_printf

fclean: clean
	rm -f $(NAME)
	@make fclean -C libft
	@make fclean -C libft/ft_printf

re: fclean all
