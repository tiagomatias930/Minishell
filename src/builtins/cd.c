/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:24:05 by timatias          #+#    #+#             */
/*   Updated: 2024/11/05 19:46:08 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int     mini_cd(char **args)
{
    if (args[1] == NULL || chdir(args[1]) != 0)
    {
        perror("minishell: cd");
        return (1);
    }
    return (0);
}
