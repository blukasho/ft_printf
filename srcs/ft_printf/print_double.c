/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:30:57 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/18 18:03:15 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static long double	round_double(long double d)
{
	int 			l;
	long double		ld;

	l = 0;
	ld = 0.5;
	if (s_data.precision > 0)
	{
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
	printf("%Lf\n", d);
	return (d);
}

static int		get_length_double(long double d)
{
	__int128	l;

	l = d;
	d = d - l;
	return (0);
}

static void	print(long double d)
{
	int		l;

	d = round_double(d);
	l = get_length_double(d);
}

void	print_double(va_list ap)
{
	if (s_data.length == 3)
		print(va_arg(ap, long double));
	else
		print(va_arg(ap, double));
}
