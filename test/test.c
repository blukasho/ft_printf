/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 21:44:36 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/27 15:28:22 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include <stdlib.h>
#include "../includes/libft.h"

void		print_double_bits(__int128 li)
{
	int		i;
	char	b[81];

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

int 					main(void)
{                   
	int					i;
	t_bits				*bits;
	long double			ld;

	ld = 0.51;
	bits = ft_get_double_bits(ld);

	t_sum_two_digits	*exp_ld = ft_get_double_exp(bits);
	t_neg_exp_of_digit	*man_ld = ft_get_double_man(bits);

	while (exp_ld->r_len && exp_ld->r[--(exp_ld->r_len)] == 0)
		;
	while (exp_ld->r_len >= 0)
		printf("%d", exp_ld->r[exp_ld->r_len--]);
	while (man_ld->r_len && man_ld->r[man_ld->r_len] == 0)
		--(man_ld->r_len);
	i = 1;
	printf(".");
	while (i <= man_ld->r_len)
		printf("%d", man_ld->r[i++]);
	printf("\n\n%.LF\n", ld);

}
/*
 *
 * 11111111111111111000000000000000000000000000000000000000000000000000000000000000 -Inf
 * 01111111111111111000000000000000000000000000000000000000000000000000000000000000 +Inf
 * 01111111111111111100000000000000000000000000000000000000000000000000000000000000 NaN
 */
