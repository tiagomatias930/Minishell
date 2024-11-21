/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 03:40:20 by timatias          #+#    #+#             */
/*   Updated: 2024/11/20 17:13:42 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


/*
 * Função principal do Minishell.
 * - Loop principal: lê, faz parsing e executa comandos.
 */

char    *last_ddir(void)
{
    char    *pwd;
    int     veri_pwd;
    char    *last_dir;

    pwd = getcwd(NULL, 0);
    veri_pwd = mini_pwd();
    if (veri_pwd == 0)
    {
        last_dir = ft_strrchr(pwd, '/');
	    if (last_dir != NULL)
	    {
		    last_dir++;
		    return (last_dir);
	    }
	    else
	    {
		     return (pwd);
	    }
    }
    else
    {
        mini_pwd();
    }
    return (NULL);
}

int main(int argc, char **argv, char **env)
{
    char    *input;
    char    **args;
    char    *last_dir;

    last_dir = last_ddir();
    (void)argc;
    (void)argv;
    while (1)
    {
        //ft_printf(GREEN "╭─" RESET CYAN "[bocal@time7]" RESET YELLOW "──►" RESET "\n");
        //input = readline(GREEN "╰─$ " RESET);

        ft_printf(GREEN "╭─" RESET CYAN "[bocal@time7/%s] " RESET YELLOW "──►" RESET "\n", last_dir);
        input = readline(GREEN "╰─$ " RESET);
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
