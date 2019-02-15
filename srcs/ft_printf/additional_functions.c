/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:10:16 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/15 17:13:07 by blukasho         ###   ########.fr       */
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

void		ft_printf_put_char(char c)
{
	write(1, &c, 1);
	++g_print_symbols;
}

void			print_hesh(void)
{
	if (s_data.specifier == 'o')
		ft_printf_put_char('0');
	else if (s_data.specifier == 'x' && (g_print_symbols += 2))
		ft_putstr("0x");
	else if (s_data.specifier == 'X' && (g_print_symbols += 2))
		ft_putstr("0X");
}

