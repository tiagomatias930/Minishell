/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:59:07 by timatias          #+#    #+#             */
/*   Updated: 2024/11/05 09:59:13 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main() {
    char *path = getenv("PATH");
    if (path != NULL) {
        printf("PATH: %s\n", path);
    } else {
        printf("Variável PATH não encontrada.\n");
    }
    return 0;
}
