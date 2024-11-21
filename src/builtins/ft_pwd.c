/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 04:48:20 by timatias          #+#    #+#             */
/*   Updated: 2024/11/20 09:06:43 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     mini_pwd(void)
{
    char cwd[PATH_MAX];
    
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        return (0);
    }
    perror ("timatias: pwd");
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
        ft_printf ("%s\n", pwd);
    }
    else
    {
        mini_pwd();
    }
}
