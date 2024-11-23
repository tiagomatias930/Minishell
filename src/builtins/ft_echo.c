/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:50:17 by timatias          #+#    #+#             */
/*   Updated: 2024/11/23 14:59:20 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_mini *ms, char **cmd)
{
	char	new_line;
	int		i;
	int		j;

	new_line = 1;
	i = 1;
	while (cmd && cmd[i] && !ft_strncmp (cmd[i], "-n", 2))
	{
		j = 2;
		while (cmd[i][j] == 'n')
			j++;
		if (cmd[i][j] != '\0')
			break ;
		new_line = 0;
		i++;
	}
	while (cmd && cmd[i])
	{
		printf ("%s", cmd[i]);
		if (cmd[++i])
			ft_putchar_fd (' ', 1);
	}
	if (new_line)
		printf ("\n");
	ms -> error = 0;
}
