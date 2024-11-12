/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:21:34 by timatias          #+#    #+#             */
/*   Updated: 2024/11/12 07:10:14 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void parse_and_execute(t_data sct, t_shell shell)
{
    //char    *args[3];
    
    /*args[0] = input;
    args[1] = NULL;*/
    if (ft_strcmp(sct.cmd, "exit") == 0)
    {
        finish();
    }
    else if (ft_strcmp(sct.cmd, "echo") == 0)
        ft_echo(sct);
    else if (ft_strcmp(sct.cmd, "pwd") == 0)
        ft_pwd();
    else if (ft_strcmp(sct.cmd, "\n") != 0)
        prompt(shell, sct);
    else
        printf ("Comando não encontrado: %s\n", sct.input);
    free (sct.cmd);
}
