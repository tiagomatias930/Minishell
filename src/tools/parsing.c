/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 02:40:01 by timatias          #+#    #+#             */
/*   Updated: 2024/11/20 02:41:01 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    **parse_command(char *input)
{
    char **tokens = NULL;
    int i = 0;

    tokens = malloc(sizeof(char *) * 64); // Aloca espaço para tokens
    if (!tokens)
        return (NULL);

    char *token = strtok(input, " \t\n");
    while (token)
    {
        tokens[i++] = strdup(token); // Copia o token
        token = strtok(NULL, " \t\n");
    }
    tokens[i] = NULL;
    return (tokens);
}
