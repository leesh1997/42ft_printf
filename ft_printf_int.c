/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghun <seunghun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:03:57 by seunghun          #+#    #+#             */
/*   Updated: 2023/11/27 19:35:27 by seunghun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_int(int n)
{
	int	cnt;
	int	num;

	cnt = 0;
	num = n;
	ft_putnbr_fd(n, 1);
	if (num == 0)
		cnt++;
	if (num < 0 && num > -2147483648)
	{
		num = -num;
		cnt++;
	}
	while (num)
	{
		num /= 10;
		cnt++;
	}
	if (n == -2147483648)
		cnt = 11;
	return (cnt);
}
