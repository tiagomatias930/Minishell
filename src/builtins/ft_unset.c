/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:51:56 by timatias          #+#    #+#             */
/*   Updated: 2024/12/09 05:06:26 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	remove_var(char *var, char ***envp)
{
	size_t	i;
	char	*temp_var;

	i = 0;
	if (!var || !envp)
		return ;
	temp_var = ft_strjoin (var, "=");
	while (envp[0][i] && ft_strncmp(envp[0][i], temp_var, ft_strlen(temp_var)))
		i++;
	if (*envp && envp[0][i])
	{
		envp[0][i] = free_ptr (envp[0][i]);
		envp[0][i] = envp[0][i + 1];
		i++;
		while (envp[0][i])
		{
			envp[0][i] = envp[0][i + 1];
			i++;
		}
		envp[0][i] = NULL;
	}
	temp_var = free_ptr (temp_var);
}

void	ft_unset(t_main *ms, char **cmd, char ***envp)
{
	while (*(++cmd))
		remove_var (*cmd, envp);
	ms -> error = 0;
}
