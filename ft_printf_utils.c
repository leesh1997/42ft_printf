/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghun <seunghun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:54:01 by seunghun          #+#    #+#             */
/*   Updated: 2023/11/25 16:54:36 by seunghun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *str, int c)
{
	char	chg_c;
	int		i;

	i = 0;
	chg_c = (unsigned char)c;
	while (str[i])
	{
		if (str[i] == chg_c)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == chg_c)
		return ((char *)&str[i]);
	return (0);
}

void	ft_putchar_fd(char c, int fd)
{
	if (!(write(fd, &c, 1)))
		return ;
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		if (!(write(fd, s++, 1)))
			return ;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	result;

	if (n == -2147483648)
	{
		if (!(write(fd, "-2147483648", 11)))
			return ;
		return ;
	}
	else if (n < 0)
	{
		n *= -1;
		if (!(write(fd, "-", 1)))
			return ;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	if (n < 10)
	{
		result = n + '0';
		if (!(write(fd, &result, 1)))
			return ;
	}
}
