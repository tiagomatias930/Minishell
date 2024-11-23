/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:50:32 by timatias          #+#    #+#             */
/*   Updated: 2024/11/23 14:59:49 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_mini *ms, char **cmd, char ***envp)
{
	size_t	i;

	if (cmd[1])
	{
		ft_putstr_fd ("-" PROMPT_MSG ": env: " INVALID_USAGE "\n", 2);
		ms -> error = 42;
	}
	else
	{
		i = 0;
		while (envp && *envp && envp[0][i])
		{
			printf ("%s\n", envp[0][i]);
			i++;
		}
		ms -> error = 0;
	}
}