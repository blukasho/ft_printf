/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:12:42 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/05 19:55:31 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_len_nbr(__int128 d)
{
	int			len;

	len = 0;
	if (d == 0)
		return (1);
	if (d < 0)
		d = -d;
	while (d > 0 && ++len)
		d = d / 10;
	return (len);
}

void			print_width_octal(char c)
{
	while (s_data.width-- > 0)
		ft_printf_put_char(c);
}

void			print_precision_octal(int l)
{
	if (s_data.precision > l)
		s_data.width -= s_data.precision;
	else
		s_data.width -= l;
	while (s_data.precision-- > l)
		ft_printf_put_char('0');
}

int				print_inf(char *s, long double d, int m)
{
	if (_IS_POS_INF(d))
	{
		s_data.specifier == 'f' ? (s = "inf") : (s = "INF");
		if (s_data.flags[4] == '-')
		{
			if (s_data.flags[3] == '+' || m)
				m == 1 ? ft_printf_put_char('-') : ft_printf_put_char('+');
			ft_printf_put_str(s);
			while ((s_data.width--) - 3 > 0)
				ft_printf_put_char(' ');
		}
		else
		{
			while ((s_data.width--) - 3 > 0)
				ft_printf_put_char(' ');
			if (s_data.flags[3] == '+' || m)
				m == 1 ? ft_printf_put_char('-') : ft_printf_put_char('+');
			ft_printf_put_str(s);
		}
		return (1);
	}
	return(0);
}

int				print_nan(char *s, long double d)
{
	if (!_IS_NAN(d))
		return (((s_data.width = s_data.width - ft_strlen(s)) ? 0 : 0));
	else
		s_data.specifier == 'f' ? (s = "nan") : (s = "NAN");
	if (s_data.flags[4] == '-')
	{
		ft_printf_put_str(s);
		while (s_data.width-- > 3)
			ft_printf_put_char(' ');
	}
	else
	{
		while (s_data.width-- > 3)
			ft_printf_put_char(' ');
		ft_printf_put_str(s);
	}
	return (1);
}
