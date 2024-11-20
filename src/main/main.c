/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 03:40:20 by timatias          #+#    #+#             */
/*   Updated: 2024/11/20 16:45:13 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


/*
 * Função principal do Minishell.
 * - Loop principal: lê, faz parsing e executa comandos.
 */
int main(int argc, char **argv, char **env)
{
    char *input;
    char **args;

    (void)argc;
    (void)argv;

    while (1)
    {
        input = readline("minishell> ");
        if (!input)
        {
            printf("\nSaindo do Minishell...\n");
            break;
        }

        // Adiciona ao histórico, se não vazio
        if (*input)
            add_history(input);

        // Parsing: transforma a entrada em argumentos
        args = parse_command(input);
        free(input);

        if (args && args[0]) // Verifica se há comandos
        {
            if (ft_strcmp(args[0], "exit") == 0) // Comando "exit"
            {
                free(args);
                break;
            }
            else if (ft_strcmp(args[0], "echo") == 0)
            {
                ft_echo(args[0]);
            }
            else if (ft_strcmp(args[0], "env") == 0) // Comando "env"
            {
                display_env(env);
            }
            else if (ft_strcmp(args[0], "cd") == 0) // Comando "cd"
            {
                ft_cd(args[1]);
            }
            else if (ft_strcmp(args[0], "pwd") == 0)
            {
                ft_pwd();
            }
            else // Outros comandos: tenta executar binário
            {
                execute_binary(args[0], args, env);
            }
        }

        free(args);
    }

    return (0);
}
