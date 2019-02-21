/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 09:53:49 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/21 14:40:54 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*oct(__int128 d, char *res)
{
	char		tmp;
	int			i;

	i = 0;
	while (d > 0)
	{
		res[i++] = (d % 8) + 48;
		d /= 8;
	}
	res[i] = '\0';
	d = 0;
	while (i > d)
	{
		tmp = res[d];
		res[d++] = res[--i];
		res[i] = tmp;
	}
	return (res);
}

void			print_octal(va_list ap)
{
	char		res[50];

	s_data.precision = -1;
	if (s_data.specifier == 'o' && !s_data.length)
		print_s(oct(va_arg(ap, unsigned int), res));
	else if (s_data.specifier == 'o' && s_data.length == 1
			&& srcrpl(s_data.flags, '+', -1))
		print_s(oct(va_arg(ap, unsigned long), res));
	else if (s_data.specifier == 'o' && s_data.length == 2
			&& srcrpl(s_data.flags, '+', -1))
		print_s(oct(va_arg(ap, unsigned long long), res));
	else if (s_data.specifier == 'o' && s_data.length == 4
			&& srcrpl(s_data.flags, '+', -1))
		print_s(oct((unsigned short)va_arg(ap, unsigned int), res));
	else if (s_data.specifier == 'o' && s_data.length == 5
			&& srcrpl(s_data.flags, '+', -1))
		print_s(oct((unsigned char)va_arg(ap, unsigned int), res));
}
