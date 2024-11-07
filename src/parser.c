/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:21:34 by timatias          #+#    #+#             */
/*   Updated: 2024/11/07 08:22:16 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void parse_and_execute(char *input, t_shell shell)
{
    char    *args[3];
    
    args[0] = input;
    args[1] = NULL;
    if (ft_strcmp(input, "exit") == 0)
    {
        printf ("exit\n");
        return ;
    }
    else if (ft_strcmp(input, "echo") == 0)
        mini_echo(args);
    else if (ft_strcmp(input, "pwd") == 0)
        ft_pwd();
    else if (ft_strcmp(input, "\n") != 0)
        prompt(shell);
    else
        printf ("Comando não encontrado: %s\n", input);
}
