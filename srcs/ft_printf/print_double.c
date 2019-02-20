/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:30:57 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/20 17:25:22 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static long double	round_double(long double d)
{
	int 			l;
	long double		ld;

	l = 0;
	ld = 0.5;
	if (s_data.precision >= 0)
	{
		while (l++ < s_data.precision)
			ld /= 10;
		if (d > 0)
			d += ld;
		else if (d < 0)
			d -= ld;
	}
	else if (d < 0)
		d -= 0.0000005;
	else if (d > 0)
		d += 0.0000005;
	return (d);
}

static void		reverse_double(char *s)
{
	int			start;
	int			end;
	char		tmp;

	end = 0;
	while (s[end] != '.' && !(start = 0))
		++end;
	if (s_data.precision <= 0)
		s[end] = '\0';
	while (start < end && (tmp = s[start]))
	{
		s[start++] = s[--end];
		s[end] = tmp;
	}
}

static void		double_to_string(long double d, char *s)
{
	char		*st;
	int			i;
	__int128	a;

	st = s;
	a = d;
	d = d - a;
	while (a > 0 && !(i = 0))
	{
		*(s++) = (a % 10) + 48;
		a /= 10;
	}
	*(s++) = '.';
	while (s_data.precision > i++)
	{
		d = d * 10;
		a = d;
		*(s++) = (a % 10) + 48;
		d = d - a;
	}
	*s = '\0';
	reverse_double(st);
}

static void		print(long double d)
{
	char		s[500];
	int			m;

	if (d < 0 && (m = 1))
		d = -d;
	else
		m = 0;
	if (s_data.precision == -1)
		s_data.precision = 6;
	d = round_double(d);
	double_to_string(d, s);
	if (m)
		ft_printf_put_char('-');
	ft_printf_put_str(s);
}

void	print_double(va_list ap)
{
	if (s_data.length == 3)
		print(va_arg(ap, long double));
	else
		print(va_arg(ap, double));
}
