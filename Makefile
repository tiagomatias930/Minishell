# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timatias <timatias@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 18:18:29 by timatias          #+#    #+#              #
#    Updated: 2024/11/23 14:55:39 by timatias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= minishell
LIBFT_DIR	= libft/
LIBFT		= ${LIBFT_DIR}libft.a
SRC			= main.c utils.c free.c \
			  lexer.c \
			  parser.c parser_utils.c \
			  syntax_checker.c \
			  expander.c expander_utils.c\
			  executor.c executor_utils.c\
			  child.c \
			  path.c \
			  redirect.c redirect_utils.c \
			  builtins.c ft_echo.c ft_cd.c ft_pwd.c ft_export.c ft_unset.c ft_env.c ft_exit.c
OBJ_DIR		= objects/
OBJ			= ${addprefix ${OBJ_DIR}, ${SRC:%.c=%.o}}
VPATH		= src src/builtins
INCLUDES	= include/ ${LIBFT_DIR}
INCLUDES	:= ${addprefix -I, ${INCLUDES}}
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
RLFLAGS		= -lreadline
RM			= rm -rf

all: ${NAME}

$(NAME): ${LIBFT} ${OBJ_DIR} ${OBJ}
	${CC} ${CFLAGS} ${OBJ} ${INCLUDES} ${LIBFT} ${RLFLAGS} -o ${NAME}

clean:
	make clean -C ${LIBFT_DIR}
	${RM} ${OBJ_DIR}

fclean: clean
	make fclean -C ${LIBFT_DIR}
	${RM} ${NAME}

re: fclean all

${LIBFT}:
	make -C ${LIBFT_DIR}

${OBJ_DIR}:
	mkdir -p ${OBJ_DIR}

${OBJ_DIR}%.o: %.c
	${CC} -c ${CFLAGS} ${INCLUDES} $< -o $@

.PHONY: all clean fclean re
