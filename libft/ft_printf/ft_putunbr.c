/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:04:41 by timatias          #+#    #+#             */
/*   Updated: 2024/11/20 09:08:03 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putunbr(unsigned int u)
{
	int	len;

	len = 0;
	if (u <= 9)
	{
		ft_putstr_char(u + '0');
		len++;
	}
	if (u >= 10)
	{
		len += ft_putnbr(u / 10);
		len += ft_putnbr(u % 10);
	}
	return (len);
}
