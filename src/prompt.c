/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:21:01 by timatias          #+#    #+#             */
/*   Updated: 2024/11/05 18:35:35 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    prompt(t_shell *shell)
{
    char    *input;

    input = readline("timatias> ");
    if (!input)
    {
        printf ("exit\n");
        exit (shell->last_exit_status);
    }
    if (*input)
        add_history(input);
    parse_and_execute(input, shell);
    free (input);
}
