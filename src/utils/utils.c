/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:11:26 by timatias          #+#    #+#             */
/*   Updated: 2024/11/07 04:40:27 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int     ft_strcmp(const char *s1, const char *s2)
{
    int     i;

    i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && (s1[i] == s2[i]))
    {
        i++;
    }
    return (s1[i] - s2[i]);
}
void    ctrl_c(int signal)
{
    t_shell shell;
    pid_t pid;
    
    pid = fork();
    if (pid == 0)
    {
        usleep(400);
    }
    if (pid > 0)
    {
        while (1)
        {
            prompt(&shell);
            printf ("\n");
        }
    }
    (void)signal;
}