/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 07:56:32 by timatias          #+#    #+#             */
/*   Updated: 2024/09/03 20:26:47 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len1(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

char	**ft_split(char *str)
{
	int		k;
	int		l;
	int		j;
	int		c;
	char	**matriz;

	j = len1(str);
	c = ft_strlen(str);
	k = 0;
	matriz = malloc(sizeof(char *) * c);
	while (str[j])
	{
		l = 0;
		matriz[k] = malloc(sizeof(char *) * c);
		while (str[j] != ' ' || str[j] != '\t'
			&& str[j] != '\n' && str[j] != '\v' && str[j] != '\f')
			matriz[k][l++] = str[j++];
		matriz[k] = '\0';
		j = len1(str);
		k++;
	}
	matriz[k] = NULL;
	return (matriz);
}
