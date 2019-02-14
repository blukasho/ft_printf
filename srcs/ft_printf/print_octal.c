/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 09:53:49 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/14 19:05:39 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static __int128	int_to_octal(__int128 d, int base)
{
	__int128	res;

	res = 0;
	while (d > 0)
	{
		res *= 10;
		res = res + (d % base);
		d /= base;
	}
	d = 0;
	while (res > 0)
	{
		d *= 10;
		d = d + (res % 10);
		res /= 10;
	}
	return (d);
}	

void			print_octal(__int128 o)
{
	print_digits(int_to_octal(o, 8));
}
