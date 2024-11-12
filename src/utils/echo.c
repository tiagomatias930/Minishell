/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 07:34:35 by timatias          #+#    #+#             */
/*   Updated: 2024/11/12 07:19:53 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void  ft_echo(t_data sct)
{
    char *path = "/bin/echo"; // Caminho completo do executável
    char *args[] = {path, sct.arg, sct.data, NULL}; // Argumentos para o executável
    char *env[] = {NULL}; // Ambiente, pode ser NULL se não precisar de variáveis de ambiente

    // Usar execve para substituir o processo atual pelo novo
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
