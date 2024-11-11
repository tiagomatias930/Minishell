/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:20:23 by timatias          #+#    #+#             */
/*   Updated: 2024/11/11 08:17:26 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int main(int argc, char **argv, char **envp)
{
    t_shell shell;
    t_data sct;

    (void)argc;
    (void)argv;
    shell.env = envp;
    shell.last_exit_status = 0;

    signal(SIGINT,  ctrl_c);
    while (1)
    {
        prompt(shell, sct);
    }
    return (0);
}
