/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:30:57 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/05 21:08:50 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void			print_3(int m)
{
	while (s_data.width-- > 0)
		ft_printf_put_char(' ');
	if (s_data.flags[3] == '+' || m)
	{
		if (m)
			ft_printf_put_char('-');
		else
			ft_printf_put_char('+');
	}
}

static void			print_2(char *s, int m, long double d)
{
	if (!print_inf(s, d, m) && !print_nan(s, d))
	{
		if (s_data.flags[1] == '0')
		{
			if (s_data.flags[3] == '+' || m)
			{
				if (m)
					ft_printf_put_char('-');
				else
					ft_printf_put_char('+');
			}
			while (s_data.width-- > 0)
				ft_printf_put_char('0');
		}
		else
			print_3(m);
		ft_printf_put_str(s);
		if (s_data.flags[0] == '#' && s_data.precision == 0)
			ft_printf_put_char('.');
	}
}

static void			print_1(char *s, int m, long double d)
{
	if (!print_inf(s, d, m) && !print_nan(s, d))
	{
		if (s_data.flags[3] == '+' || m)
		{
			if (m)
				ft_printf_put_char('-');
			else
				ft_printf_put_char('+');
		}
		ft_printf_put_str(s);
		if (s_data.flags[0] == '#' && s_data.precision == 0)
			ft_printf_put_char('.');
		while (s_data.width-- > 0)
			ft_printf_put_char(' ');
	}
}

static void			print(long double d)
{
	char			s[80000];
	int				m;

	if ((d == -0 || d < 0) && (m = 1))
		d = -d;
	else
		m = 0;
	if (s_data.precision == -1)
		s_data.precision = 6;
	if (s_data.flags[0] == '#' && s_data.precision == 0 && d == d)
		--s_data.width;
	if ((s_data.flags[3] == '+' || m) && d == d)
		--s_data.width;
	d = round_double(d);
	double_to_string(d, s);
	if (s_data.flags[2] == ' ' && s_data.flags[3] != '+' && d == d && !m)
	{
		--s_data.width;
		ft_printf_put_char(' ');
	}
	if (s_data.flags[4] == '-')
		print_1(s, m, d);
	else
		print_2(s, m, d);
}

void				print_double(va_list ap)
{
	if (s_data.length == 3)
		print(va_arg(ap, long double));
	else
		print(va_arg(ap, double));
}
