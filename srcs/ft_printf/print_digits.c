/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:45:00 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/11 16:54:23 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_put_long_nbr(__int128 d)
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

void		print_digits(__int128 d)
{
	ft_put_long_nbr(d);
}
