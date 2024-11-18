/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:11:26 by timatias          #+#    #+#             */
/*   Updated: 2024/11/18 14:33:39 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int     ft_strlen(char *str)
{
    int    size_string;

    size_string = 0;
    while (str[size_string++] != '\0')
        ;
    return (size_string);
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

char    *ft_strtok(char *str, const char *delim)
{
    static char *input = NULL;
    char *start;

    if (str != NULL)
    {
        input = str;
    }
    if (input == NULL)
    {
        return NULL;
    }
    while (*input && strchr(delim, *input) != NULL)
    {
        input++;
    }
    if (*input == '\0')
    {
        return NULL;
    }
    start = input;
    while (*input && strchr(delim, *input) == NULL)
    {
        input++;
    }
    if (*input != '\0')
    {
        *input = '\0';
        input++;
    }
    return (start);
}

char **split_input(char *input)
{
    int bufsize = 64; // Tamano inicial do buffer
    int i = 0;        // Índice para os tokens
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!tokens)
    {
        fprintf(stderr, "minishell: erro de alocação\n");
        exit(EXIT_FAILURE);
    }

    // Usar strtok para dividir a string
    token = ft_strtok(input, " \t\r\n"); // Separadores: espaço, tabulação, nova linha
    while (token != NULL) {
        tokens[i++] = token;

        // Reajustar o tamanho do buffer, se necessário
        if (i >= bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens) {
                fprintf(stderr, "minishell: erro de realocação\n");
                exit(EXIT_FAILURE);
            }
        }

        token = ft_strtok(NULL, " \t\r\n");
    }

    tokens[i] = NULL; // Finalizar o array com NULL
    return (tokens);
}
