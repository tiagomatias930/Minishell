/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:06:29 by timatias          #+#    #+#             */
/*   Updated: 2024/11/20 09:07:54 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putnbr(int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (write(1, "0", 1));
	if (nbr == INT_MIN)
		return (write(1, "-2147483648", 11));
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
		len++;
	}
	if (nbr >= 10)
		len += ft_putnbr(nbr / 10);
	write(1, &"0123456789"[nbr % 10], 1);
	len++;
	return (len);
}
