/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:10:16 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/21 22:04:33 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long double		round_double(long double d)
{
	int				l;
	long double		ld;

	l = 0;
	ld = 0.5;
	if (s_data.precision >= 0)
	{
	printf("float %f\n", d);
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

void			ft_printf_put_char(char c)
{
	write(1, &c, 1);
	++g_print_symbols;
}

void			ft_printf_put_str(char *s)
{
	while (*s)
		ft_printf_put_char(*(s++));
}

void			print_hesh(void)
{
	if (s_data.specifier == 'o')
		ft_printf_put_char('0');
	else if (s_data.specifier == 'x' || s_data.specifier == 'p')
		ft_printf_put_str("0x");
	else if (s_data.specifier == 'X')
		ft_printf_put_str("0X");
}
