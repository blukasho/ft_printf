/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:12:42 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/04 19:58:38 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

char			*check_inf(char *s, long double d)
{
	if (d == s_data.pos_inf || d == s_data.neg_inf)
		return ((s_data.specifier == 'f' ? (s = "inf") : (s = "INF")));
	return(s);
}

int				check_nan(char *s, long double d)
{
	if (d == d && d != s_data.pos_inf && d != s_data.neg_inf)
	{
		s_data.width = s_data.width - ft_strlen(s);
		return (0);
	}
	else
	{
		if (s_data.specifier == 'f')
			s = "nan";
		else
			s = "NAN";
	}
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
