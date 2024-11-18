/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 06:03:27 by timatias          #+#    #+#             */
/*   Updated: 2024/11/18 06:03:57 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void  ft_ls(t_data sct)
{
    char    *env_ = getenv(sct.arg);
    char *path = "/bin/ls"; // Caminho completo do executável
    char *args[] = {path, sct.arg, sct.data, NULL}; // Argumentos para o executável
    char *env[] = {env_}; // Ambiente, pode ser NULL se não precisar de variáveis de ambiente
    
    // Usar execve para substituir o processo atual pelo novo
    pid_t fd = fork();
    if (fd == 0)
    {
        if (ft_strcmp(sct.arg, "-n") == 0)
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
        waitpid(fd, &sct.status, 0);
    
}