/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:11:26 by timatias          #+#    #+#             */
/*   Updated: 2024/11/08 07:08:29 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


int     finish(void)
{
    printf ("exit\n");
    exit(1);
}
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
    rl_forced_update_display ();
    rl_on_new_line ();
    (void)signal;
}