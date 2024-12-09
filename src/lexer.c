/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:58:25 by timatias          #+#    #+#             */
/*   Updated: 2024/12/05 05:15:20 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*filler(char *input, int pos)
{
	char	*string; // Está é a string que será retorna já pronta e devidamente separada para a tokenização
	int		i;
	int		j;

	string = ft_calloc(ft_strlen(input) + 3, sizeof (char));
	if (!string)
		return (NULL);
	i = -1;
	j = -1;
	while (++j < pos)
		string[j] = input[++i];
	i++;
	string[j++] = SEP;
	string[j++] = input[i++];
	if (input[i] == input[i - 1] && input[i] != '|')
		string[j++] = input[i++];
	string[j++] = SEP;
	while (input[i])
		string[j++] = input[i++];
	string[j] = '\0';
	input = free_ptr(input);
	return (string);
}

char	**lexer(char *input)
{
	int		i;
	int		quotes;
	char	*temp;
	char	**string;

	i = -1;
	quotes = 0;
	temp = ft_strdup(input);
	if (temp == NULL)
		return (NULL);
	while (temp && temp[++i])
	{
		if ((temp[i] == '|' || temp[i] == '>' || temp[i] == '<' ) && !quotes)
		{
			temp = filler(temp, i);
			i = i + 2;
		}
		else if (temp[i] == '\"' || temp[i] == '\'')
			quotes = check_quotes(temp[i], quotes);
	}
	if (quotes)
		temp = free_ptr(temp);
	string = ft_split(temp, SEP);
	if (string == NULL)
		return (NULL);
	temp = free_ptr(temp);
	return (string);
}
