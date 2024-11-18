/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:20:23 by timatias          #+#    #+#             */
/*   Updated: 2024/11/18 12:09:37 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int main(int argc, char **argv, char **envp)
{
    t_shell shell;
    t_data sct;
    char prompt_buffer[1024]; // Buffer para armazenar o prompt atualizado

    (void)argc;
    (void)argv;
    shell.env = envp;
    shell.last_exit_status = 0;

    signal(SIGINT, ctrl_c);
    signal(SIGQUIT, SIG_IGN);

    while (1)
    {
        // Atualizar o prompt antes de exibi-lo
        update_prompt(prompt_buffer, sizeof(prompt_buffer));

        // Passar o prompt atualizado para exibição
        shell.prompt = prompt_buffer; 

        prompt(shell, sct);
    }

    return (0);
}
