/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:24:34 by timatias          #+#    #+#             */
/*   Updated: 2024/11/05 20:46:09 by timatias         ###   ########.fr       */
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

void    ft_pwd(void)
{
    char    *pwd;
    int     veri_pwd;

    pwd = getcwd(NULL, 0);
    veri_pwd = mini_pwd();
    if (veri_pwd == 0)
    {
        printf ("%s\n", pwd);
    }
    else
    {
        mini_pwd();
    }
}
