/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 21:44:36 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/15 17:50:12 by blukasho         ###   ########.fr       */
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

void			pos_exp_of_digit(int dig, int base, int len, int *res)
{
	int			i;

	i = len;
	ft_bzero(res, len * (sizeof(int)));
	res[0] = 1;
	while (base-- > 0)
	{
		i = 0;
		while (i < len)
		{
			res[i] = res[i] * dig;
			++i;
		}
		i = 0;
		while (i < len)
		{
			if (res[i] > 9)
			{
				res[i + 1] = res[i + 1] + (res[i] / 10);
				res[i] = res[i] % 10;
			}
			++i;
		}
	}
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

int 			main(void)
{
	int			li;
	int			exp = 20;
	int			digit = 20;
	int			exp2 = 20;
	int			digit2 = 2;
	int			len_arr = ft_len_of_digit(digit) * exp;
	int			len_arr2 = ft_len_of_digit(digit2) * exp2;

	int			tmp = len_arr;
	int			tmp2 = len_arr2;

	printf("exp %d\ndigit %d\ncreate len_arr -------->>>>>>>>>>>>> %d\n", exp, digit, len_arr);
	printf("exp2 %d\ndigit2 %d\ncreate len_arr2 -------->>>>>>>>>>>>> %d\n", exp2, digit2, len_arr2);
	int			*arr = (int *)malloc(len_arr * sizeof(int));
	int			*arr2 = (int *)malloc(len_arr2 * sizeof(int));
	ft_bzero(arr, sizeof(arr));
	ft_bzero(arr2, sizeof(arr));

	pos_exp_of_digit(digit, exp, len_arr, arr);
	pos_exp_of_digit(digit2, exp2, len_arr2, arr2);
	while (arr[--len_arr] == 0)
		;
	while (arr2[--len_arr2] == 0)
		;
	printf("real len_arr -------->>>>>>>>>>>>> %d\n", len_arr + 1);
	printf("real len_arr2 -------->>>>>>>>>>>>> %d\n", len_arr2 + 1);
	printf("digit one -------->>>>>>>>>>>>> ");
	while (len_arr >= 0)
		printf("%d", arr[len_arr--]);
	printf("\n");
	printf("digit two -------->>>>>>>>>>>>>	");
	while (len_arr2 >= 0)
		printf("%d", arr2[len_arr2--]);
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
//	ft_memdel((void **)&arr);
//	ft_memdel((void **)&arr2);
//	system("leaks a.out");
}

/*
 *
 * 11111111111111111000000000000000000000000000000000000000000000000000000000000000 -Inf
 * 01111111111111111000000000000000000000000000000000000000000000000000000000000000 +Inf
 * 01111111111111111100000000000000000000000000000000000000000000000000000000000000 NaN
 */
