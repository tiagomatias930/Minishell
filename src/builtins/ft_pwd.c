/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:51:42 by timatias          #+#    #+#             */
/*   Updated: 2024/12/09 05:05:29 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_main *ms, char **cmd, char **envp)
{
	size_t	i;

	if (!cmd[1])
	{
		i = 0;
		while (envp && ft_strncmp (envp[i], "PWD=", 4))
			i++;
		if (envp && envp[i])
			printf ("%s\n", envp[i] + 4);
	}
	else
	{
		ft_putstr_fd ("-" PROMPT_MSG ": pwd: " INVALID_USAGE "\n", 2);
		ms -> error = 42;
	}
}
