/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:20:23 by timatias          #+#    #+#             */
/*   Updated: 2024/11/12 12:16:06 by timatias         ###   ########.fr       */
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
    signal(SIGQUIT, SIG_IGN);
    //raise(SIGQUIT);
    while (1)
    {
        prompt(shell, sct);
    }
    return (0);
}
