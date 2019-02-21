/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 09:53:49 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/21 21:52:43 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		print_width(int p)
{
	char		c;

	if (s_data.flags[0] == '#' && p == -1)
		--s_data.width;
	if (s_data.flags[1] == '0' && s_data.precision == -1)
		c = '0';
	else
		c = ' ';
	while (s_data.width-- > 0)
		ft_printf_put_char(c);
}

static void		print(char *s, int l)
{
	int			p;

	p = s_data.precision;
	if (s_data.flags[0] == '#')
		--s_data.precision;
	if (s_data.flags[4] == '-')
	{
		if (s_data.flags[0] == '#')
			print_hesh();
		while (s_data.precision-- > l)
			ft_printf_put_char('0');
		ft_printf_put_str(s);
		print_width(p);
	}
	else
	{
		print_width(p);
		if (s_data.flags[0] == '#')
			print_hesh();
		while (s_data.precision-- > l)
			ft_printf_put_char('0');
		ft_printf_put_str(s);
	}
}

static void		preparate(__int128 d, char *res)
{
	char		tmp;
	int			i;

	i = 0;
	if (!d && s_data.precision == -1 && (s_data.flags[0] = -1))
		res[i++] = '0';
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
	i = ft_strlen(res);
	if (s_data.precision > i)
		s_data.width -= s_data.precision;
	else
		s_data.width -= i;
	print(res, i);
}

void			print_octal(va_list ap)
{
	char		res[50];

	if (s_data.specifier == 'o' && !s_data.length)
		preparate(va_arg(ap, unsigned int), res);
	else if (s_data.specifier == 'o' && s_data.length == 1
			&& srcrpl(s_data.flags, '+', -1))
		preparate(va_arg(ap, unsigned long), res);
	else if (s_data.specifier == 'o' && s_data.length == 2
			&& srcrpl(s_data.flags, '+', -1))
		preparate(va_arg(ap, unsigned long long), res);
	else if (s_data.specifier == 'o' && s_data.length == 4
			&& srcrpl(s_data.flags, '+', -1))
		preparate((unsigned short)va_arg(ap, unsigned int), res);
	else if (s_data.specifier == 'o' && s_data.length == 5
			&& srcrpl(s_data.flags, '+', -1))
		preparate((unsigned char)va_arg(ap, unsigned int), res);
}
