/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 09:53:49 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/15 17:46:38 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static __int128	oct(__int128 d, int base)
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

void			print_octal(va_list ap)
{
	if (s_data.specifier == 'o' && !s_data.length)
		print_all_digits(oct(va_arg(ap, unsigned int), 8));
	else if (s_data.specifier == 'o' && s_data.length == 1
			&& srcrpl(s_data.flags, '+', -1))
		print_all_digits(oct(va_arg(ap, unsigned long), 8));
	else if (s_data.specifier == 'o' && s_data.length == 2
			&& srcrpl(s_data.flags, '+', -1))
		print_all_digits(oct(va_arg(ap, unsigned long long), 8));
	else if (s_data.specifier == 'o' && s_data.length == 4
			&& srcrpl(s_data.flags, '+', -1))
		print_all_digits(oct((unsigned short)va_arg(ap, unsigned int), 8));
	else if (s_data.specifier == 'o' && s_data.length == 5
			&& srcrpl(s_data.flags, '+', -1))
		print_all_digits(oct((unsigned char)va_arg(ap, unsigned int), 8));
}

void			print_hexdecimal(__int128 h)
{
	if (h){}
}
