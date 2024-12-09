/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:04:27 by timatias          #+#    #+#             */
/*   Updated: 2024/12/09 05:03:02 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	init_fd(int	*fd)
{
	fd[0] = -1;
	fd[1] = -1;
}

char	**redirect(t_main *ms, char **cmd, int *out, int *in)
{
	int		fd[2];
	char	**ret;
	int		i;

	init_fd(fd);
	i = 0;
	while (cmd[i])
		i++;
	ret = ft_calloc(i + 1, sizeof(char *));
	set_redirect(ms, cmd, fd, ret);
	if (fd[0] == -5 || fd[1] == -5)
		return (free_mat(ret));
	if (fd[0] != -1)
	{
		dup2(fd[0], 0);
		close(fd[0]);
		*in = 1;
	}
	if (fd[1] != -1)
	{
		dup2(fd[1], 1);
		close(fd[1]);
		*out = 1;
	}
	return (ret);
}
