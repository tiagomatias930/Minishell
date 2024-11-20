/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 07:34:35 by timatias          #+#    #+#             */
/*   Updated: 2024/11/20 16:43:11 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void  ft_echo(char *cmd)
{
    char    *env_ = getenv(cmd);
    char    *path = "/bin/echo"; // Caminho completo do executável
    char    *args[] = {path, cmd, NULL, NULL}; // Argumentos para o executável
    char    *env[] = {env_}; // Ambiente, pode ser NULL se não precisar de variáveis de ambiente
    int        fd;
    int        status; 

    fd = fork();
    if (fd == 0)
    {
        if (ft_strcmp(cmd, "-n") == 0)
        {
            if (execve(path, args, env) == -1)
            {
                perror("Erro ao executar o execve");
            }
            write(STDOUT_FILENO, "\n", 1);
            rl_set_prompt("timatias:~$ ");
            rl_on_new_line();
            rl_replace_line("", 1);
            rl_redisplay();
        }
        else
        {
            if (execve(path, args, env) == -1)
                perror("Erro ao executar o execve");
            
        }
    }
    else
        waitpid(fd, &status, 0);
    
}