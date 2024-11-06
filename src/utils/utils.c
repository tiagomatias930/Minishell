/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:11:26 by timatias          #+#    #+#             */
/*   Updated: 2024/11/05 21:07:33 by timatias         ###   ########.fr       */
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
    (void)signal;
    sleep(1);
    wait(NULL);
    exit (1);
}