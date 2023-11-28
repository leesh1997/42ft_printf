/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghun <seunghun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:27:25 by seunghun          #+#    #+#             */
/*   Updated: 2023/11/28 16:37:46 by seunghun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	er_code(void)
{
	return (-1);
}

static int	end_f(int cnt, va_list ap)
{
	if (cnt == -1)
	{
		va_end(ap);
		return (-1);
	}
	return (1);
}

static int	type_chk(char format, va_list ap)
{
	int	cnt;

	cnt = 0;
	if (format == 'c')
		cnt += printf_chr(va_arg(ap, int));
	else if (format == 's')
		cnt += printf_str(va_arg(ap, char *));
	else if (format == 'p')
		cnt += printf_pt(va_arg(ap, unsigned long long));
	else if (format == 'd' || format == 'i')
		cnt += printf_int(va_arg(ap, int));
	else if (format == 'u')
		cnt += printf_u(va_arg(ap, unsigned int));
	else if (format == 'x' || format == 'X')
		cnt += printf_x(format, va_arg(ap, unsigned int));
	else if (format == '%')
		cnt += printf_chr('%');
	else
		cnt += er_code();
	return (cnt);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		cnt;

	cnt = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (ft_strchr("cspdiuxX%%", *format))
				cnt += type_chk(*format, ap);
			if ((end_f(cnt, ap)) == -1)
				return (-1);
		}
		else
		{
			cnt += printf_chr(*format);
			if (end_f(cnt, ap) == -1)
				return (-1);
		}
		format++;
	}
	va_end(ap);
	return (cnt);
}
