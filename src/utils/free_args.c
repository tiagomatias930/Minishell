/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:32:25 by timatias          #+#    #+#             */
/*   Updated: 2024/11/18 12:32:42 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void free_args(char **args)
{
    int i = 0;

    if (!args)
    {
        return;
    }
    while (args[i] != NULL) {
        free(args[i]);
        i++;
    }

    // Liberar o próprio array
    free(args);
}
