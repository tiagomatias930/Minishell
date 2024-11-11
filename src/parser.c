/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:21:34 by timatias          #+#    #+#             */
/*   Updated: 2024/11/11 08:18:53 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void parse_and_execute(t_data sct, t_shell shell)
{
    //char    *args[3];
    
    /*args[0] = input;
    args[1] = NULL;*/
    if (ft_strcmp(sct.input, "exit") == 0)
    {
        finish();
    }
    else if (ft_strcmp(sct.input, "echo") == 0)
        ft_echo(sct);
    else if (ft_strcmp(sct.input, "pwd") == 0)
        ft_pwd();
    else if (ft_strcmp(sct.input, "\n") != 0)
        prompt(shell, sct);
    else
        printf ("Comando não encontrado: %s\n", sct.input);
}
