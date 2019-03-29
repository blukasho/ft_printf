/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:38:58 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/29 16:30:44 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void			print_double_bits(long double d)
{               
	int			i;
	char		b[81];
	__int128	li;

	li = *(__int128 *)&d;
	i = 0;
	printf("\n");
	while (i <= 80)
	{
		if ((li & 0x1) == 1)
			b[i] = '1';
		else
			b[i] = '0';
		++i;
		li = li >> 1;
	}
	b[i] = '\0';
	i = 79;
	while (i >= 0)
		printf("%c", b[i--]);
	printf("\n");
}

int						main(void)
{
	int					my;
	int					sy;
	char				*s;
	long double			b;
	float				a;

	a = 0.32378662109375L;
	b = 349999999999999999989588958734.0394857L;

	s = "|%# +-060.Lf|\n";

	ft_printf("<<<<<<ft_printf>>>>>>\n");
	my = ft_printf(s, b);
	ft_printf("<<<<<<printf>>>>>>\n");
	sy = printf(s, b);
	printf("my = %d sy = %d\n", my, sy);
//	system("leaks a.out");
	return (0);
}

/*
 * 0001001001000111000000000000000010000000000000000000000000000000
 */
