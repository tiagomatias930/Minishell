/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:11:26 by timatias          #+#    #+#             */
/*   Updated: 2024/11/11 11:24:55 by timatias         ###   ########.fr       */
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
int 	len1(char *str)
{
    int i;
    
    i = 0;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    return (i);
}

int		word_len(char *str, int j)
{
    int len;
    
    len = 0;
    while (str[j] && str[j] != ' ' && str[j] != '\t' &&
           str[j] != '\n' && str[j] != '\v' && str[j] != '\f')
    {
        len++;
        j++;
    }
    return (len);
}

char 	**ft_split(char *str)
{
    int k = 0;
    int j = len1(str);
    int c = 0;
    char **matriz;

    for (int i = j; str[i]; i++)
        if ((str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\v' && str[i] != '\f') &&
            (i == 0 || str[i - 1] == ' ' || (str[i - 1] >= 9 && str[i - 1] <= 13)))
            c++;

    matriz = malloc(sizeof(char *) * (c + 1));
    if (!matriz)
        return NULL;

    while (str[j])
	{
        while (str[j] == ' ' || (str[j] >= 9 && str[j] <= 13))
            j++;

        if (!str[j])
            break;

        int len = word_len(str, j);
        matriz[k] = malloc(sizeof(char) * (len + 1));
        if (!matriz[k])
            return NULL;

        int l = 0;
        while (str[j] && str[j] != ' ' && str[j] != '\t' &&
               str[j] != '\n' && str[j] != '\v' && str[j] != '\f')
            matriz[k][l++] = str[j++];
        
        matriz[k][l] = '\0';
        k++;
    }
    matriz[k] = NULL;
    return (matriz);
}