/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 07:34:35 by timatias          #+#    #+#             */
/*   Updated: 2024/11/11 11:50:40 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_strnlen(char *str, int last)
{
    int len = 0;
    
    while (str[len] != '\0')
    {
        if (len != last)
        {
            len++;
        }
        break;
    }
    return (len);
}

void  ft_echo(t_data sct)
{
    if (ft_strcmp(sct.arg, "-n") == 0)
    {
        ft_print (sct.data);
    }
    else
    {
        ft_print (sct.data);
    }
    write(STDOUT_FILENO, "\n", 1);
    rl_set_prompt("timatias:~$ ");
    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
}
