/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:24:34 by timatias          #+#    #+#             */
/*   Updated: 2024/11/06 16:40:20 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int     mini_pwd(void)
{
    char cwd[PATH_MAX];

    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        return (0);
    }
    perror ("minishell: pwd");
    return (1);
}

void    ft_pwd()
{
    int         teste_value;
    char    *pwd;

    teste_value = mini_pwd();
    pwd = getcwd(NULL, 0);
    if (teste_value == 0)
    {
        printf ("%s\n", pwd);
    }
}
