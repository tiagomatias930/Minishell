/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 05:41:53 by timatias          #+#    #+#             */
/*   Updated: 2024/11/03 07:19:46 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>

int ft_strlen (char *str)
{
    int len = 0;

    while (str[len] != '\0')
        len++;
    return (len);
}

void    ft_putstr(int fd, char *str)
{
    write(fd, str, ft_strlen(str));
}

int     main()
{
    int pipefd[2];
    char buffer;
    
    if (pipefd == -1)
    {
        perror("Erro na criação do processo filho");
        return (1);
    }
    else if (pipefd == 0) // Processo filho
    {
        close(pipefd[1]); // Fechar o lado de escrita do pipe no filho
        ft_putstr(1, "Filho em ação\n");
        while (read(pipefd[0], &buffer, 1) > 0)
        {
            write(1, &buffer, 1);
        }
        ft_putstr(1, "\nEu sou o processo filho\n");
        close(pipefd[0]); // Fechar o lado de leitura do pipe no filho
    }
    else // Processo pai
   {
        close(pipefd[0]); // Fechar o lado de leitura do pipe no pai
        ft_putstr(1, "Processo pai\n");
        ft_putstr(pipefd[1], "\033[0;33mPai mesmo é Pai\n\033[0m");
        close(pipefd[1]); // Fechar o lado de escrita do pipe no pai
        wait(NULL); // Esperar o processo filho terminar
        ft_putstr(1, "Txauu\n");
    }
    return (0);
}
