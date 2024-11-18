/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:46:39 by timatias          #+#    #+#             */
/*   Updated: 2024/11/18 14:32:26 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <signal.h>
# include <fcntl.h>
# include <stddef.h>
# include <limits.h>

typedef struct s_shell
{
    char    **env; // Variáveis de ambiente
    char    *prompt;
    int         last_exit_status; // Último status de saída
} t_shell;


typedef struct  s_data
{
    char    *cmd;
    char    *arg;
    char    *data;
    char    *input;
    char    **division;
    int             size_arg;
    int             status;
    
} t_data;

void   prompt(t_shell shell, t_data sct);
void   ft_pwd(void);
void   ctrl_c(int signal);
void   ctrl_q(int signal);
void   ft_ls(t_data sct);
void   parse_and_execute(t_data sct);
void   ft_echo(t_data sct);
void   ft_print(char *str);
void   update_prompt(char *prompt_buffer, size_t size);
int         ft_cd(char **args);
char    **split_input(char *input);
char    *ft_strcpy(char *dest, char *src);
int         mini_pwd(void);
int         finish(void);
int         ft_strcmp(const char *s1, const char *s2);

#endif
