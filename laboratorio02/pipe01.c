/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 06:38:17 by timatias          #+#    #+#             */
/*   Updated: 2024/11/04 08:09:59 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>

int	ft_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}

void    ft_write(int fd, char *str)
{
    write (fd, str, ft_strlen(str));
}

int	main()
{
    pid_t pid;
    int pipefd[2];
    char bar;
    int status = 0;

    pipe(pipefd);
    pid = fork ();
    if (pid < 0)
    {
        printf ("Erro\n");
    }
    else if (pid == 0)
    {
        close (pipefd[1]);
        while (read (pipefd[0], &bar, 1) > 0)
        {
            write (1, &bar, 1);
        }
        ft_write(1, "O Filho esta dormindo\n");
        close(pipefd[0]);
    }
    else
    {
        close(pipefd[0]);
        ft_write(pipefd[1], "O pai acordou\n");
        wait(NULL);
        close(pipefd[1]);
    }
    return (0);
}
