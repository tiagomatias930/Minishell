/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:48:39 by timatias          #+#    #+#             */
/*   Updated: 2024/12/09 05:05:16 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_dir(t_main *ms, char *dir, char ***envp)
{
	char	*temp;
	char	**var;

	temp = NULL;
	var = ft_calloc (3, sizeof (char *));
	var[0] = ft_strdup ("export");
	temp = getcwd (temp, BUFFER_SIZE);
	if (chdir (dir))
	{
		perror (PROMPT_MSG ": cd");
		ms -> error = 42;
	}
	else
	{
		var[1] = ft_strjoin ("OLDPWD=", temp);
		ft_export (ms, var, envp);
		temp = free_ptr (temp);
		var[1] = free_ptr (var[1]);
		temp = getcwd (temp, BUFFER_SIZE);
		var[1] = ft_strjoin ("PWD=", temp);
		ft_export (ms, var, envp);
		ms -> error = 0;
	}
	temp = free_ptr (temp);
	var = free_mat (var);
}

static char	*get_home(char **envp)
{
	char	*home;

	while (envp && ft_strncmp (*envp, "HOME=", 5))
		envp++;
	home = *envp + 5;
	return (home);
}

void	ft_cd(t_main *ms, char **cmd, char ***envp)
{
	if (cmd[1] && !cmd[2])
		set_dir (ms, cmd[1], envp);
	else if (!cmd[1])
		set_dir (ms, get_home (*envp), envp);
	else
	{
		ft_putstr_fd ("-" PROMPT_MSG ": cd: " INVALID_USAGE "\n", 2);
		ms -> error = 42;
	}
}
