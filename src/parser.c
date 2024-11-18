/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:21:34 by timatias          #+#    #+#             */
/*   Updated: 2024/11/18 14:32:40 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void    parse_and_execute(t_data sct)
{
    char **args;
    int         status;

    args = split_input(sct.input);
    if (!args || !args[0]) // Verifica se o input está vazio
    {
        free(args); // Libera a memória, caso alocada
        return;
    }

    sct.cmd = args[0]; // Primeiro token é o comando

    // Verificar comandos internos
    if (ft_strcmp(sct.cmd, "exit") == 0)
    {
        free(args); // Libera memória antes de encerrar
        finish();
    }
    else if (ft_strcmp(sct.cmd, "echo") == 0)
    {
        ft_echo(sct);
    }
    else if (ft_strcmp(sct.cmd, "cd") == 0)
    {
        if (ft_cd(args) != 0)
        {
            fprintf(stderr, "minishell: erro ao executar cd\n");
        }
    }
    else if (ft_strcmp(sct.cmd, "pwd") == 0)
    {
        ft_pwd();
    }
    else
    {
        // Executar comandos externos
        pid_t pid = fork();
        if (pid == 0)
        {
            // Processo filho executa o comando
            if (execvp(args[0], args) == -1)
            {
                perror("minishell");
                exit(EXIT_FAILURE);
            }
        }
        else if (pid < 0)
        {
            // Erro ao criar o processo filho
            perror("minishell: fork");
        }
        else
            waitpid(pid, &status, 0);
    }

    // Liberar memória alocada
    free(args);
}
