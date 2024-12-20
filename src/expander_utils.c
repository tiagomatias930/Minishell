/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:57:32 by timatias          #+#    #+#             */
/*   Updated: 2024/12/09 05:01:34 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof (char));
	if (!str)
		return (0);
	i = -1;
	j = 0;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	s2 = free_ptr(s2);
	s1 = free_ptr(s1);
	return (str);
}

static char	*number_to_string(int n)
{
	char	*errnum;
	int		i;
	int		temp;

	temp = n;
	if (!temp)
		return (ft_strdup("0"));
	i = 0;
	while (temp)
	{
		temp = temp / 10;
		i++;
	}
	errnum = ft_calloc(i + 1, sizeof(char));
	while (n)
	{
		errnum[i - 1] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	return (errnum);
}

static char	*exit_status(t_main *ms, char *f, char *cmd)
{
	char	*ret;

	ret = NULL;
	if (!*cmd)
	{
		f = free_ptr(f);
		return (ft_strdup("$"));
	}
	if (cmd && cmd[0])
		ret = ft_strdup(++cmd);
	f = free_ptr(f);
	return (ft_strjoin_gnl(number_to_string(ms->error), ret));
}

int	find_equalsing(char *var)
{
	int	i;

	i = 0;
	if (!var)
		return (0);
	while (var[i] && var[i] != '=')
		i++;
	return (i);
}

char	*get_envp(t_main *ms, char *cmd, char **envp)
{
	char	*ret;
	int		len;
	int		var_len;

	ret = cmd;
	cmd++;
	if (*cmd == '{')
		len = ft_strlen(++cmd);
	else
		len = ft_strlen(cmd);
	if (*cmd == '?' || len == 0)
		return (exit_status(ms, ret, cmd));
	while (*envp)
	{
		var_len = find_equalsing(*envp);
		if (!ft_strncmp(cmd, *envp, var_len) && \
			!ft_strncmp(cmd, *envp, var_len))
		{
			ret = free_ptr(ret);
			return (ft_strdup(*envp + len + 1));
		}
		envp++;
	}
	ret = free_ptr(ret);
	return (ft_strdup(""));
}
