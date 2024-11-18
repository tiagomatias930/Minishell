/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:22:27 by timatias          #+#    #+#             */
/*   Updated: 2024/11/18 12:11:07 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void    execute_command(char **args, t_shell *shell)
{
    (void)args;
    (void)shell;
}
void update_prompt(char *prompt_buffer, size_t size)
{
    char cwd[1024];

    // Obter o diretório atual
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        snprintf(prompt_buffer, size, "minishell:%s$ ", cwd);
    }
    else
    {
        perror("Erro ao obter o diretório atual");
        snprintf(prompt_buffer, size, "minishell:erro$ ");
    }
}
