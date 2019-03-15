/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 21:44:36 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/15 20:10:51 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include <stdlib.h>
#include "../includes/libft.h"

void		print_double_bits(__int128 li)
{
	char	res[80];
	int		i;	

	i = 0;
	while (i < 80)
	{
		(li & 0x1) == 1 ? (res[i] = '1') : (res[i] = '0');
		li = li >> 1;
		++i;
	}
	res[i] = '\0';
	while (--i >= 0)
		printf("%c", res[i]);
}

//t_pos_exp_of_digit		*pos_exp_of_digit(int dig, int base)
//{
//	t_pos_exp_of_digit	*s;
//
//	s = (t_pos_exp_of_digit *)malloc(sizeof(t_pos_exp_of_digit));
//	ft_bzero(s, sizeof(t_pos_exp_of_digit));
//
//	while (base-- > 0)
//	{
//		i = 0;
//		while (i < len)
//		{
//			res[i] = res[i] * dig;
//			++i;
//		}
//		i = 0;
//		while (i < len)
//		{
//			if (res[i] > 9)
//			{
//				res[i + 1] = res[i + 1] + (res[i] / 10);
//				res[i] = res[i] % 10;
//			}
//			++i;
//		}
//	}
//	return (s);
//}

/*
 * logical comparison of two integers represented in an int array
 * return 1 if a > b
 * return -1 if a < b
 * return  0 if a == b
 */

int				int_arr_comparing(int *a, int *b, int a_len, int b_len)
{
	while (a[--a_len] == 0)
		;
	while (b[--b_len] == 0)
		;
	if (a_len > b_len)
		return (1);
	else if (a_len < b_len)
		return (-1);
	else
	{
		while (a_len >= 0)
		{
			if (a[a_len] > b[a_len])
				return (1);
			else if (a[a_len] < b[a_len])
				return (-1);
			--a_len;
		}
	}
	return (0);
}

int 					main(void)
{                   
	int					exp = 13;
	int					digit = 3;
	int					exp2 = 12;
	int					digit2 = 10;
	t_pos_exp_of_digit	*s;
	t_pos_exp_of_digit	*s2;

	printf("-------->>>>>>> %d ^ %d = ", digit, exp);
	s = ft_pos_exp_of_digit(digit, exp);
	s->i = s->r_len;
	while (s->r[s->r_len] == 0)
		s->r_len--;
	while (s->r_len >= 0)
		printf("%d", s->r[s->r_len--]);
	printf("\n");

	printf("-------->>>>>>> %d ^ %d = ", digit2, exp2);
	s2 = ft_pos_exp_of_digit(digit2, exp2);
	s2->i = s2->r_len;
	while (s2->r[s2->r_len] == 0)
		s2->r_len--;
	while (s2->r_len >= 0)
		printf("%d", s2->r[s2->r_len--]);
	printf("\n");

	t_sum_two_digits	*sum;

	sum = ft_sum_two_digits(s->r, s2->r, s->i, s2->i);
	printf("sum = ");
	while (sum->r[--(sum->r_len)] == 0)
		;
	while (sum->r_len >= 0)
		printf("%d", sum->r[sum->r_len--]);
	printf("\n");
//	printf("result equals a");
//	li = int_arr_comparing(arr, arr2, tmp, tmp2);
//	if (li == 1)
//		printf(" > b\n");
//	else if (li == -1)
//		printf(" < b\n");
//	else
//		printf(" = b\n");

//	ft_memdel((void **)&s->r);
//	ft_memdel((void **)&s);
//	ft_memdel((void **)&s2->r);
//	ft_memdel((void **)&s2);
//	system("leaks a.out");
}

/*
 *
 * 11111111111111111000000000000000000000000000000000000000000000000000000000000000 -Inf
 * 01111111111111111000000000000000000000000000000000000000000000000000000000000000 +Inf
 * 01111111111111111100000000000000000000000000000000000000000000000000000000000000 NaN
 */
