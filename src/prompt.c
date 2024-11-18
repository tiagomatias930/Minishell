/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:21:01 by timatias          #+#    #+#             */
/*   Updated: 2024/11/18 14:37:37 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void    prompt(t_shell shell, t_data sct)
{
    sct.input = readline("tiago: ~");
    //sct.input = malloc(sizeof(t_data));
    if (!sct.input)
    {
        printf("exit\n");
        exit(shell.last_exit_status);
    }
    sct.division = split_input(sct.input);
    sct.size_arg = 0;
    while (sct.division[sct.size_arg] != NULL)
    {
        sct.size_arg += 1;
    }
    if (sct.input != NULL)
        add_history(sct.input);
    parse_and_execute(sct);
    free(sct.input);
    free(sct.division);
}
