/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghun <seunghun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:37:52 by seunghun          #+#    #+#             */
/*   Updated: 2023/11/28 16:35:17 by seunghun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr(unsigned long long nbr)
{
	if (nbr >= 16)
	{
		ft_putnbr(nbr / 16);
		ft_putnbr(nbr % 16);
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
			if ((ft_putchar_fd((nbr - 10 + 'a'), 1)) == -1)
				return (-1);
		}
	}
	return (1);
}

int	printf_pt(unsigned long long n)
{
	int					cnt;
	unsigned long long	nbr;

	cnt = 0;
	nbr = n;
	cnt += printf_str("0x");
	if (cnt == -1)
		return (-1);
	if (nbr == 0)
		cnt++;
	if ((ft_putnbr(n)) == -1)
		return (-1);
	while (nbr != 0)
	{
		cnt++;
		nbr /= 16;
	}
	return (cnt);
}
