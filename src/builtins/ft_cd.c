/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:24:05 by timatias          #+#    #+#             */
/*   Updated: 2024/11/19 04:19:30 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int    ft_cd(char **args)
{
    char cwd[1024];
    // Obter o diretório atual para feedback
    
    if (args[1] != 0)
    {
        perror("Erro na identificação\n");
        return (1);
    }
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        printf("Diretório atual: %s\n", cwd);
    }
    else
    {
        perror("Erro ao obter o diretório atual");
        return 1;
    }

    return 0;
}
