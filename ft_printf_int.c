/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghun <seunghun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:03:57 by seunghun          #+#    #+#             */
/*   Updated: 2023/11/23 10:17:26 by seunghun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int printf_int(int n)
{
    int cnt;
    int num;
    
    cnt = 0;
    num = n;
    if (n < 0 && n > -2147483648)
    {
        num = -n;
        cnt++;
    }
    while (num)
    {
        num / 10; 
        cnt++;
    }
    if (n == -2147483648)
        cnt = 11;
    ft_putnbr_fd(n, 1);
    return (cnt);
}