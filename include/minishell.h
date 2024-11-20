/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 07:19:45 by timatias          #+#    #+#             */
/*   Updated: 2024/11/20 17:07:32 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"

# define PROMPT "minishell> "
# define RESET "\033[0m"
# define GREEN "\033[32m"
# define CYAN "\033[36m"
# define YELLOW "\033[33m"


typedef struct s_data
{
    char    *arg;
    char    *cmd;
    char    *data;
    int         status;
    char    *input;
}   t_data;

void    ft_echo(char *cmd);
void    ft_cd(char *path);
void    ft_pwd(void);
void    display_env(char **env);
void    ft_pwd(void);
void    execute_binary(char *cmd, char **args, char **env);
char        **parse_command(char *input);
char        *ft_strcpy(char *dest, char *src);
char        *ft_strtok(char *str, const char *delim);
int             ft_strcmp(const char *s1, const char *s2);
int		ft_printf(const char *format, ...);

#endif
