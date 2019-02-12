/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:45:00 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/12 13:17:58 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_put_long_nbr(__int128 d)
{
	if (d < 0)
	{
		d = -d;
		ft_putchar('-');
		++g_print_symbols;
	}
	if (d > 9)
	{
		ft_put_long_nbr(d / 10);
		ft_putchar((d % 10) + 48);
		++g_print_symbols;
	}
	else
	{
		ft_putchar((d % 10) + 48);
		++g_print_symbols;
	}
}

static int		len_nbr(__int128 d)
{
	int			len;

	len = 0;
	if (d < 0)
		d = -d;
	while (d > 0)
	{
		++len;
		d = d / 10;
	}
	return (len);
}

void			print_digits(__int128 d)
{
	int			l;

	l = len_nbr(d);
	while ((s_data.width > l) && (s_data.width > s_data.precision)
			&& (s_data.width--))
		ft_printf_put_char(' ');
	if ((s_data.precision > l) && (s_data.width <= s_data.precision))
		while (s_data.precision-- > l)
			ft_printf_put_char('0');
	ft_put_long_nbr(d);
}
