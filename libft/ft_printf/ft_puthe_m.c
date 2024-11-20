/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthe_m.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:07:58 by timatias          #+#    #+#             */
/*   Updated: 2024/11/20 09:07:40 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	convert_hex(unsigned long int p)
{
	int	len;

	len = 0;
	if (p >= 16)
	{
		len += convert_hex(p / 16);
		len += convert_hex(p % 16);
	}
	else
	{
		if (p <= 9)
		{
			ft_putnbr_fd(p, 1);
			len++;
		}
		else
		{
			ft_putchar_fd(p - 10 + 'A', 1);
			len++;
		}
	}
	return (len);
}

int	ft_puthe_m(unsigned int n)
{
	return (convert_hex(n));
}
