/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 06:10:21 by timatias          #+#    #+#             */
/*   Updated: 2024/11/18 06:14:42 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *ft_strcpy(char *dest, char *src)
{
    int    index;

    index = 0;
    while (src[index] != '\0')
        index++;
    dest = malloc (sizeof(char) * (index + 1));
    if (!dest)
        return (NULL);
    index = 0;
    while (src[index] != '\0')
    {
        dest[index] = src[index];
        index++;
    }
    dest[index] = '\0';
    return (dest);
}