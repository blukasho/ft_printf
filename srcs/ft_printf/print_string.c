/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 09:52:13 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/21 21:12:46 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		print(char *s, int len, int prs)
{
	if (ft_strchr(s_data.flags, '-'))
	{
		while (*s && prs--)
			ft_printf_put_char(*(s++));
		while (s_data.width-- > len)
			ft_printf_put_char(' ');
	}
	else
	{
		if (!ft_strchr(s_data.flags, '0'))
		{
			while (s_data.width-- > len)
				ft_printf_put_char(' ');
			while (*s && prs--)
				ft_printf_put_char(*(s++));
		}
		else
		{
			while (s_data.width-- > len)
				ft_printf_put_char('0');
			while (*s && prs--)
				ft_printf_put_char(*(s++));
		}
	}
}

/*
**print with 0
*/

void			print_s(char *s)
{
	int			len;
	int			prs;

	len = ft_strlen(s);
	prs = len;
	if ((s_data.precision >= 0) && (s_data.precision < len))
	{
		len = s_data.precision;
		prs = len;
	}
	if (s_data.width > len)
		print(s, len, prs);
	else
		while (*s && prs--)
			ft_printf_put_char(*(s++));
}

void			double_to_string(long double d, char *s)
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

void			print_string(va_list ap)
{
	char		*s;

	s = va_arg(ap, char *);
	if (!s)
		print_s("(null)");
	else
		print_s(s);
}
