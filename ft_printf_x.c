/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghun <seunghun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:25:15 by seunghun          #+#    #+#             */
/*   Updated: 2023/11/27 19:36:50 by seunghun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putnbr_lower(unsigned long long nbr)
{
	if (nbr >= 16)
	{
		putnbr_lower(nbr / 16);
		putnbr_lower(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar_fd((nbr + '0'), 1);
		else
			ft_putchar_fd((nbr - 10 + 'a'), 1);
	}
}

static void	putnbr_upper(unsigned long long nbr)
{
	if (nbr >= 16)
	{
		putnbr_upper(nbr / 16);
		putnbr_upper(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar_fd((nbr + '0'), 1);
		else
			ft_putchar_fd((nbr - 10 + 'A'), 1);
	}
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
		putnbr_lower(n);
	}
	else if (format == 'X')
	{
		putnbr_upper(n);
	}
	while (nbr != 0)
	{
		cnt++;
		nbr /= 16;
	}
	return (cnt);
}
