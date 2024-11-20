/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:45:30 by timatias          #+#    #+#             */
/*   Updated: 2024/11/20 09:07:59 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putstr_char(char c)
{
	return (write(1, &c, 1));
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (str[len])
		len++;
	return (write(1, str, len));
}
