/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 09:53:49 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/27 19:08:26 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		print_3(char *s, int l, char c)
{
	while (s_data.width > l && s_data.width-- > s_data.precision)
		ft_printf_put_char(c);
	print_precision_octal(l);
	ft_printf_put_str(s);
}

static void		print_2(char *s, int l)
{
	char 		c;

	if (s_data.precision > -1 || s_data.flags[1] != '0')
		c = ' ';
	else
		c = '0';
	if (s_data.flags[0] == '#')
	{
		if (s_data.precision > l + 1)
		{
			s_data.width -= s_data.precision;
			print_width_octal(c);
		}
		else
			while (s_data.width-- > l + 1)
				ft_printf_put_char(c);
		print_hesh();
		while (s_data.precision-- > l + 1)
			ft_printf_put_char('0');
		ft_printf_put_str(s);
	}
	else
		print_3(s, l, c);
}

static void		print(char *s, int l)
{
	if (s_data.flags[4] == '-')
	{
		if (s_data.flags[0] == '#')
		{
			if (s_data.precision > l + 1)
			{
				s_data.width -= s_data.precision;
				while (s_data.precision-- > l)
					ft_printf_put_char('0');
			}
			else
			{
				print_hesh();
				s_data.width -= l + 1;
			}
		}
		else
			print_precision_octal(l);
		ft_printf_put_str(s);
		print_width_octal(' ');
	}
	else
		print_2(s, l);
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
	print(res, i);
}

void			print_octal(va_list ap)
{
	char		res[40];

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
