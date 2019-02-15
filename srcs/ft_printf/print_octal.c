/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 09:53:49 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/15 13:59:19 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			print_hesh(void)
{
	if (s_data.specifier == 'o')
		ft_printf_put_char('0');
	else if (s_data.specifier == 'x' && (g_print_symbols += 2))
		ft_putstr("0x");
	else if (s_data.specifier == 'X' && (g_print_symbols += 2))
		ft_putstr("0X");
}

static __int128	int_to_octal(__int128 d, int base)
{
	__int128	res;

	res = 0;
	while (d > 0)
	{
		res *= 10;
		res = res + (d % base);
		d /= base;
	}
	d = 0;
	while (res > 0)
	{
		d *= 10;
		d = d + (res % 10);
		res /= 10;
	}
	return (d);
}	

void			print_octal(__int128 o)
{
	print_digits(int_to_octal(o, 8));
}

void			print_hexdecimal(__int128 h)
{
	char		s[50];
	int			i;

	i = 0;
	while (h > 0)
	{

	}
}
