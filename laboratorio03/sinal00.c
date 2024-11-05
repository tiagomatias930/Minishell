/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sinal00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 05:21:32 by timatias          #+#    #+#             */
/*   Updated: 2024/11/04 08:14:33 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>

void   sms(int signal)
{
    printf ("Mensagem de bom dia\n");
    exit (1);
}
int    main()
{
    pid_t pid = fork();

    if (pid  == 0)
    {
        int son_pid = getpid ();
        printf ("Processo filho meu pid %d\n", pid);
        printf ("O pid do Papa é %d\n", (son_pid - 1));
    }
    else if (pid > 0)
    {
        printf ("Processo pai meu pid %d\n", (pid -1));
    }
    kill(pid, 9);
    return (0);
}