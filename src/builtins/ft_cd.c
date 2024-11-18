/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:24:05 by timatias          #+#    #+#             */
/*   Updated: 2024/11/18 11:54:14 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int ft_cd(char **args) {
    char cwd[1024];

    // Verificar se o diretório foi passado
    if (args[1] == NULL) {
        fprintf(stderr, "minishell: cd: argumento necessário\n");
        return 1;
    }

    // Tentar mudar o diretório
    if (chdir(args[1]) != 0) {
        perror("minishell: cd");
        return 1;
    }

    // Obter o diretório atual para feedback
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Diretório atual: %s\n", cwd);
    } else {
        perror("Erro ao obter o diretório atual");
        return 1;
    }

    return 0;
}
