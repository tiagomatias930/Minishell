/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:46:20 by timatias          #+#    #+#             */
/*   Updated: 2024/12/03 06:42:57 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_easter_egg(char **prompt, int set)
{
	if (set)
	{
		*prompt = free_ptr (*prompt);
		printf ("\033[1;32mHi, We are Time 7 Bocal :)\033[0m\n");
		*prompt = ft_strdup ("\033[1;32mTiago \033[0m> ");
	}
	else
	{
		*prompt = free_ptr (*prompt);
		*prompt = ft_strdup (GREEN "╭─" RESET CYAN "[bocal@time7/] " RESET
				YELLOW "──►" RESET "\n" GREEN "╰─$ " RESET);
	}
}

int	execbi(t_mini *ms, char **cmd, char ***envp, char *prompt)
{
	if (!cmd || !*cmd || !*envp || !prompt)
		return (-1);
	if (!ft_strncmp (*cmd, "echo", 5))
		ft_echo (ms, cmd);
	else if (!ft_strncmp (*cmd, "cd", 3))
		ft_cd (ms, cmd, envp);
	else if (!ft_strncmp (*cmd, "pwd", 4))
		ft_pwd (ms, cmd, *envp);
	else if (!ft_strncmp (*cmd, "export", 7))
		ft_export (ms, cmd, envp);
	else if (!ft_strncmp (*cmd, "unset", 6))
		ft_unset (ms, cmd, envp);
	else if (!ft_strncmp (*cmd, "env", 4))
		ft_env (ms, cmd, envp);
	else if (!ft_strncmp (*cmd, "hi_frank", 9))
		ft_easter_egg (&prompt, 1);
	else if (!ft_strncmp (*cmd, "bye_frank", 10))
		ft_easter_egg (&prompt, 0);
	else if (!ft_strncmp (*cmd, "exit", 5))
		ft_exit (ms, cmd);
	else
		return (0);
	return (1);
}
