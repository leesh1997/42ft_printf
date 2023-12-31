/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghun <seunghun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:46:08 by seunghun          #+#    #+#             */
/*   Updated: 2023/11/28 15:32:08 by seunghun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int			ft_printf(const char *format, ...);
char		*ft_strchr(const char *str, int c);
int			ft_putchar_fd(char c, int fd);
int			ft_putnbr_fd(int n, int fd);
int			ft_putstr_fd(char *s, int fd);
int			printf_chr(char c);
int			printf_int(int n);
int			printf_str(char *s);
int			printf_u(unsigned int n);
int			printf_pt(unsigned long long n);
int			printf_x(char format, unsigned int n);

#endif