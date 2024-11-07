/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:46:39 by timatias          #+#    #+#             */
/*   Updated: 2024/11/07 04:59:15 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <limits.h>

typedef struct s_shell
{
    char    **env; // Variáveis de ambiente
    int         last_exit_status; // Último status de saída
} t_shell;

void   prompt(t_shell shell);
void   ft_pwd(void);
void   ctrl_c(int signal);
void   parse_and_execute(char *input, t_shell shell);
int     mini_echo(char **args);
int     mini_cd(char **args);
int     mini_pwd(void);
int     ft_strcmp(const char *s1, const char *s2);

#endif
