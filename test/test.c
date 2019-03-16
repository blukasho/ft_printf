/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 21:44:36 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/16 18:48:15 by blukasho         ###   ########.fr       */
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
	int					exp = 10;
	int					digit = 2;
	int					exp2 = 16;
	int					digit2 = 2;
	t_pos_exp_of_digit	*s;
	t_pos_exp_of_digit	*s2;
	t_sum_two_digits	*sum;
	t_sum_two_digits	*all;
	t_sum_two_digits	*tmp;

	all = (t_sum_two_digits *)malloc(sizeof(t_sum_two_digits));
	ft_bzero(all, sizeof(t_sum_two_digits));
	all->r_len = 1;
	all->r = (int *)malloc(all->r_len * sizeof(int));
	ft_bzero(all->r, all->r_len * sizeof(int));
	while (exp2 <= 20)
	{
		printf("-------->>>>>>> %d ^ %d = ", digit, exp);
		s = ft_pos_exp_of_digit(digit, exp);
		s->i = s->r_len;
		while (s->r[--(s->r_len)] == 0)
			;
		while (s->r_len >= 0)
			printf("%d", s->r[s->r_len--]);
		printf("\n");
    
		printf("-------->>>>>>> %d ^ %d = ", digit2, exp2);
		s2 = ft_pos_exp_of_digit(digit2, exp2);
		s2->i = s2->r_len;
		while (s2->r[--(s2->r_len)] == 0)
			;
		while (s2->r_len >= 0)
			printf("%d", s2->r[s2->r_len--]);
		printf("\n");
    
    
		sum = ft_sum_two_digits(s2->r, s->r, s2->i, s->i);
		printf("sum = ");
		sum->i = sum->r_len;
		while (sum->r[--(sum->i)] == 0)
			;
		while (sum->i >= 0)
			printf("%d", sum->r[sum->i--]);
		printf("\n");
		
		tmp = all;
		all = ft_sum_two_digits(all->r, sum->r, all->r_len, sum->r_len);
		printf("all = ");
		all->i = all->r_len;
		while (all->r[--all->i] == 0 && all->i)
			;
		while (all->i >= 0)
			printf("%d", all->r[all->i--]);
		printf("\n");
		ft_memdel((void **)&s->r);
		ft_memdel((void **)&s);
		ft_memdel((void **)&s2->r);
		ft_memdel((void **)&s2);
		ft_memdel((void **)&sum->r);
		ft_memdel((void **)&sum);
		ft_memdel((void **)&tmp->r);
		ft_memdel((void **)&tmp);
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
