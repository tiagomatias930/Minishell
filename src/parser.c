/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:21:34 by timatias          #+#    #+#             */
/*   Updated: 2024/11/05 18:22:01 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void parse_and_execute(char *input, t_shell *shell)
{
    char    *args[3];
    args[0] = input;
    args[1] = NULL;

    if (strcmp(input, "exit") == 0)
    {
        printf ("exit\n");
        exit (shell->last_exit_status);
    }
    else if (strcmp(input, "echo") == 0)
        mini_echo(args);
    else
        printf("Comando não encontrado: %s\n", input);
}