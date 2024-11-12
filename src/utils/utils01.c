/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:19:00 by timatias          #+#    #+#             */
/*   Updated: 2024/11/12 11:51:48 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_print(char *str)
{
    int     index;

    index = 0;
    while (str[index] != '\0')
    {
        write (STDOUT_FILENO, &str[index], 1);
        index++;
    }
}
void ctrl_c(int signal)
{
    write(STDOUT_FILENO, "\n", 1);
    rl_set_prompt("timatias:~$ ");

    // Indica à readline que uma nova linha será desenhada
    rl_on_new_line();

    // Limpa o buffer de entrada atual
    rl_replace_line("", 0);

    // Redesenha o prompt atualizado
    rl_redisplay();

    (void)signal;  // Evita warning sobre o parâmetro não usado
}
int     finish(void)
{
    printf ("exit\n");
    exit(1);
}

void    ctrl_q(int signal)
{
    (void) signal;
    
    write(STDOUT_FILENO, "\n", 1);
    rl_set_prompt("timatias:~$ ");
    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
}
