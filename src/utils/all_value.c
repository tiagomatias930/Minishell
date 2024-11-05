/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:59:07 by timatias          #+#    #+#             */
/*   Updated: 2024/11/05 10:54:55 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#define COLUNA 4
#define LINHA 2

int main()
{
    char tableCMD[LINHA][COLUNA];

    tableCMD[0][0] = "ls";
    tableCMD[0][1] = "-al";
    tableCMD[0][2] = NULL;
    tableCMD[1][3] = "grep";
    tableCMD[1][4] = "me";
    return 0;
}
