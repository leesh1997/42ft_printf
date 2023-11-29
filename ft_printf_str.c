/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghun <seunghun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:05:52 by seunghun          #+#    #+#             */
/*   Updated: 2023/11/29 16:06:03 by seunghun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_str(char *s)
{
	int	cnt;

	cnt = 0;
	if (!s)
	{
		if ((ft_putstr_fd("(null)", 1)) == -1)
			return (-1);
		return (6);
	}
	else
	{
		if ((ft_putstr_fd(s, 1)) == -1)
			return (-1);
		while (s[cnt])
			cnt++;
		return (cnt);
	}
}
