/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 21:44:36 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/26 11:49:25 by blukasho         ###   ########.fr       */
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
	i = 80;
	while (--i >= 0)
		printf("%c", res[i]);
	printf("\n");
}

int 					main(void)
{                   
	int					exp = 63;
	int					digit = 2;
	int					exp2 = 1;
	int					digit2 = 2;
	int					exp3 = -1;
	int					digit3 = 2;
	int					exp4 = -1;
	int					digit4 = 2;
	long double			ld;
	__int128			d;

	ld = 3.125;
	d = *(__int128 *)&ld;
	print_double_bits(d);
	printf("\n%.100LF\n", ld);

	t_pos_exp_of_digit	*s;
	t_pos_exp_of_digit	*s2;
	t_sum_two_digits	*sum;
	t_sum_two_digits	*all;
	t_sum_two_digits	*tmp;
	t_int_arr_subtr		*sub;
	t_int_arr_mult		*mul;
	t_neg_exp_of_digit	*neg;
	t_neg_exp_of_digit	*neg2;
	t_neg_exp_of_digit	*neg_tmp;
	t_neg_exp_of_digit	*neg_tmp2;

	neg_tmp = (t_neg_exp_of_digit *)malloc(sizeof(t_neg_exp_of_digit)); 
	ft_bzero(neg_tmp, sizeof(t_neg_exp_of_digit));
	neg_tmp->r_len = 1;
	neg_tmp->r = (int *)malloc((neg_tmp->r_len + 1) * sizeof(int));
	ft_bzero(neg_tmp->r, neg_tmp->r_len * sizeof(int));

	all = (t_sum_two_digits *)malloc(sizeof(t_sum_two_digits));
	ft_bzero(all, sizeof(t_sum_two_digits));
	all->r_len = 1;
	all->r = (int *)malloc((all->r_len + 1) * sizeof(int));
	ft_bzero(all->r, all->r_len * sizeof(int));
	while (exp2 <= 10)
	{
		printf("-------->>>>>>> %d ^ %d = ", digit, exp);
		s = ft_pos_exp_of_digit(digit, exp);
		s->i = s->r_len;
		while (s->r[--(s->r_len)] == 0)
			;
		while (s->r_len >= 0)
			printf("%d", s->r[s->r_len--]);
		printf("\n");

//		printf("-------->>>>>>> %d ^ %d = ", digit2, exp2);
//		s2 = ft_pos_exp_of_digit(digit2, exp2);
//		s2->i = s2->r_len;
//		while (s2->r[--(s2->r_len)] == 0)
//			;
//		while (s2->r_len >= 0)
//			printf("%d", s2->r[s2->r_len--]);
//		printf("\n");
//    
//		sum = ft_sum_two_digits(s2->r, s->r, s2->i, s->i);
//		printf("sum = ");
//		sum->i = sum->r_len;
//		while (sum->r[--(sum->i)] == 0)
//			;
//		while (sum->i >= 0)
//			printf("%d", sum->r[sum->i--]);
//		printf("\n");
//		
//		tmp = all;
//		all = ft_sum_two_digits(all->r, sum->r, all->r_len, sum->r_len);
//		printf("all = ");
//		all->i = all->r_len;
//		while (all->r[--all->i] == 0 && all->i)
//			;
//		while (all->i >= 0)
//			printf("%d", all->r[all->i--]);
//		printf("\n");
//
//		sub = ft_int_arr_subtr(all->r, sum->r, all->r_len, sum->r_len);
//		sub->count = sub->r_len;
//		printf("sub = ");
//		while (sub->count > 0 && sub->r[--(sub->count)] == 0)
//			;
//		while (sub->count >= 0)
//			printf("%d", sub->r[sub->count--]);
//		printf("\n");
//
//		mul = ft_int_arr_mult(all->r, sum->r, all->r_len, sum->r_len);
//		printf("multiple = ");
//		mul->a_tmp = mul->r_len;
//		while (mul->r[--(mul->a_tmp)] == 0)
//			;
//		while (mul->a_tmp >= 0)
//			printf("%d", mul->r[(mul->a_tmp)--]);
//		printf("\n");

//		printf("-------->>>>>>> %d ^ %d = ", digit3, exp3);
//		neg = ft_neg_exp_of_digit(digit3, exp3);
//		while (neg->r[--(neg->r_len)] == 0)
//			;
//		neg->r_pos = 0;
//		while (neg->r_pos <= neg->r_len)
//		{
//			if (neg->r_pos == 1)
//				printf(".");
//			printf("%d", neg->r[neg->r_pos++]);
//		}
//		printf("\n");

		printf("-------->>>>>>> %d ^ %d = ", digit4, exp4);
		neg2 = ft_neg_exp_of_digit(digit4, exp4);
		while (neg2->r[--(neg2->r_len)] == 0)
			;
		neg2->r_pos = 0;
		while (neg2->r_pos <= neg2->r_len)
		{
			if (neg2->r_pos == 1)
				printf(".");
			printf("%d", neg2->r[neg2->r_pos++]);
		}
		printf("\n");

		printf("->> sum neg_tmp && neg2 = ");
		neg_tmp = ft_sum(neg_tmp, neg2);
		neg_tmp->tmp = neg_tmp->r_len;
		while (neg_tmp->r[--(neg_tmp->tmp)] == 0)
			;
		neg_tmp->sw = 0;
		while (neg_tmp->sw <= neg_tmp->tmp)
		{
			if (neg_tmp->sw == 1)
				printf(".");
			printf("%d", neg_tmp->r[neg_tmp->sw++]);
		}
		printf("\n");

//		ft_memdel((void **)&neg_tmp->r);
//		ft_memdel((void **)&neg_tmp->per);
//		ft_memdel((void **)&neg_tmp->div);
//		ft_memdel((void **)&neg_tmp);
		ft_memdel((void **)&neg2->r);
		ft_memdel((void **)&neg2->per);
		ft_memdel((void **)&neg2->div);
		ft_memdel((void **)&neg2);
//		ft_memdel((void **)&neg->r);
//		ft_memdel((void **)&neg->per);
//		ft_memdel((void **)&neg->div);
//		ft_memdel((void **)&neg);
//		ft_memdel((void **)&s->r);
//		ft_memdel((void **)&s);
//		ft_memdel((void **)&s2->r);
//		ft_memdel((void **)&s2);
//		ft_memdel((void **)&sum->r);
//		ft_memdel((void **)&sum);
//		ft_memdel((void **)&tmp->r);
//		ft_memdel((void **)&tmp);
//		ft_memdel((void **)&sub->r);
//		ft_memdel((void **)&sub); 
//		ft_memdel((void **)&mul->r);
//		ft_memdel((void **)&mul);
		--exp4;
		--exp3;
		++exp;
		++exp2;
	}
	ft_memdel((void **)&all->r);
	ft_memdel((void **)&all);
//	system("leaks a.out");
}
/*
 *
 * 11111111111111111000000000000000000000000000000000000000000000000000000000000000 -Inf
 * 01111111111111111000000000000000000000000000000000000000000000000000000000000000 +Inf
 * 01111111111111111100000000000000000000000000000000000000000000000000000000000000 NaN
 */
