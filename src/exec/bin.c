/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 02:38:11 by timatias          #+#    #+#             */
/*   Updated: 2024/11/20 02:39:04 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    execute_binary(char *cmd, char **args, char **env)
{
    pid_t pid;
    int status;

    pid = fork(); // Cria um novo processo
    if (pid == 0) // Processo filho
    {
        if (execve(cmd, args, env) == -1)
        {
            perror("execve");
            _exit(EXIT_FAILURE);
        }
    }
    else if (pid > 0) // Processo pai
    {
        waitpid(pid, &status, 0); // Aguarda o término do filho
    }
    else
    {
        perror("fork");
    }
}
