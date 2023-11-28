/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghun <seunghun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:03:12 by seunghun          #+#    #+#             */
/*   Updated: 2023/11/28 16:44:50 by seunghun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_u(unsigned int n)
{
	unsigned int	cnt;
	unsigned int	nb;

	nb = n;
	if (nb >= 10)
	{
		printf_u(nb / 10);
		printf_u(nb % 10);
	}
	if (nb < 10)
	{
		if ((ft_putchar_fd(nb + '0', 1)) == -1)
			return (-1);
	}
	cnt = 1;
	while (n >= 10)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}
