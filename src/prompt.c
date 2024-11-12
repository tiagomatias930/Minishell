/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:21:01 by timatias          #+#    #+#             */
/*   Updated: 2024/11/12 12:25:56 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void prompt(t_shell shell, t_data sct)
{
    sct.input = readline("timatias:~$ ");
    //sct.input = malloc(sizeof(t_data));
    if (!sct.input)
    {
        printf("exit\n");
        exit(shell.last_exit_status);
    }
    sct.division = ft_split(sct.input);
    sct.size_arg = 0;
    while (sct.division[sct.size_arg] != NULL)
    {
        sct.size_arg += 1;
    }
    if (sct.size_arg == 0)
    {
        sct.cmd = " ";
    }
    sct.cmd = sct.division[0];
    if (sct.size_arg > 0)
    {
        sct.arg = sct.division[1];
        sct.data = sct.division[2];
    }
    else
    {
        sct.arg = " ";
        sct.data = " ";
    }
    if (sct.input != NULL)
        add_history(sct.input);
    parse_and_execute(sct, shell);
    free(sct.input);
    free(sct.division);
}
