/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexdecimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 12:04:08 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/21 10:44:43 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		print_hexdecimal(va_list ap)
{
	if (!s_data.length)
		print_hex(va_arg(ap, unsigned int));
	else if (s_data.length == 1)
		print_hex(va_arg(ap, unsigned long));
	else if (s_data.length == 2)
		print_hex(va_arg(ap, unsigned long long));
	else if (s_data.length == 4)
		print_hex((unsigned short)va_arg(ap, unsigned int));
	else if (s_data.length == 5)
		print_hex((unsigned char)va_arg(ap, unsigned int));
}

static void	strrev(char s[])
{
	int		end;
	int		start;
	char	c;

	start = 0;
	end = ft_strlen(s);
	while (--end > start)
	{
		c = s[start];
		s[start++] = s[end];
		s[end] = c;
	}
}

static void	print2(int l, char *res)
{
	if (s_data.flags[0] == '#')
		s_data.width -= 2;
	if (s_data.flags[1] == '0' && s_data.precision == -1)
	{
		if (s_data.flags[0] == '#')
			print_hesh();
		while (s_data.width-- > l)
			ft_printf_put_char('0');
	}
	else
	{
		while (s_data.width > l && s_data.width-- > s_data.precision)
			ft_printf_put_char(' ');
		if (s_data.flags[0] == '#')
			print_hesh();
	}
	while (s_data.precision-- > l)
		ft_printf_put_char('0');
	ft_printf_put_str(res);
}

static void	print(int l, char *res)
{
	if (s_data.flags[4] == '-')
	{
		if (s_data.flags[0] == '#')
		{
			print_hesh();
			s_data.width -= 2;
		}
		while (s_data.precision-- > l)
		{
			--s_data.width;
			ft_printf_put_char('0');
		}
		ft_printf_put_str(res);
		s_data.width -= l;
		while (s_data.width-- > 0)
			ft_printf_put_char(' ');
	}
	else
		print2(l, res);
}

void		print_hex(__int128 h)
{
	char	res[50];
	int		c;
	int		d;

	c = 0;
	while (h)
	{
		d = (h % 16);
		if (d > 9 && s_data.specifier == 'X')
			res[c++] = d + 'A' - 10;
		else if (d > 9 && s_data.specifier == 'x')
			res[c++] = d + 'a' - 10;
		else
			res[c++] = d + '0';
		h /= 16;
	}
	res[c] = '\0';
	strrev(res);
	print(c, res);
}
