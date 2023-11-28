/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghun <seunghun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:25:15 by seunghun          #+#    #+#             */
/*   Updated: 2023/11/28 16:24:34 by seunghun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putnbr_lower(unsigned long long nbr)
{
	if (nbr >= 16)
	{
		putnbr_lower(nbr / 16);
		putnbr_lower(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
		{
			if (ft_putchar_fd((nbr + '0'), 1) == -1)
				return (-1);
		}
		else
		{
			if (ft_putchar_fd((nbr - 10 + 'a'), 1) == -1)
				return (-1);
		}
	}
	return (1);
}

static int	putnbr_upper(unsigned long long nbr)
{
	if (nbr >= 16)
	{
		putnbr_upper(nbr / 16);
		putnbr_upper(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
		{
			if ((ft_putchar_fd((nbr + '0'), 1)) == -1)
				return (-1);
		}
		else
		{
			if ((ft_putchar_fd((nbr - 10 + 'A'), 1)) == -1)
				return (-1);
		}
	}
	return (0);
}

int	printf_x(char format, unsigned int n)
{
	int				cnt;
	unsigned int	nbr;

	cnt = 0;
	nbr = n;
	if (nbr == 0)
		cnt++;
	if (format == 'x')
	{
		if ((putnbr_lower(n)) == -1)
			return (-1);
	}
	else if (format == 'X')
	{
		if ((putnbr_upper(n)) == -1)
			return (-1);
	}
	while (nbr != 0)
	{
		cnt++;
		nbr /= 16;
	}
	return (cnt);
}
