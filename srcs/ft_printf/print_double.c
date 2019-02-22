/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:30:57 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/22 11:16:29 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void				reverse_double(char *s)
{
	int				start;
	int				end;
	char			tmp;

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

static void			print_2(char *s, int m)
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
	ft_printf_put_str(s);
}

static void			print_1(char *s, int m)
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

static void			print(long double d)
{
	char			s[500];
	int				m;

	if (d < 0 && (m = 1))
		d = -d;
	else
		m = 0;
	if (s_data.precision == -1)
		s_data.precision = 6;
	if (s_data.flags[0] == '#' && s_data.precision == 0)
		--s_data.width;
	if (s_data.flags[3] == '+' || m)
		--s_data.width;
	d = round_double(d);
	double_to_string(d, s);
	s_data.width = s_data.width - ft_strlen(s);
	if (s_data.flags[2] == ' ' && s_data.flags[3] != '+')
	{
		--s_data.width;
		ft_printf_put_char(' ');
	}
	if (s_data.flags[4] == '-')
		print_1(s, m);
	else
		print_2(s, m);
}

void				print_double(va_list ap)
{
	if (s_data.length == 3)
		print(va_arg(ap, long double));
	else
		print(va_arg(ap, double));
}
