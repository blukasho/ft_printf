/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 21:44:36 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/12 19:48:46 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 

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

int				len_of_digit(int d)
{
	int			l;

	l = 0;
	while (d > 0 && ++l)
		d /= 10;
	return (l);
}



void			pos_exp_of_digit(int dig, int base, int len, int *res)
{
	int			i;

	i = len;
	while (--i >= 0)
		res[i] = 0;
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
 *Only for 2
 */

void		neg_exp_of_digit_two(int dig, int base, int len, int *res)
{
	base = -base;
	pos_exp_of_digit(5, base, len, res);
}

/*
 * Array a must be bigger than b
 * Resul write in a
 *
 */

void			sum_two_digits(int *a, int *b, int  a_len, int b_len)
{
	int			i;
	int			m;

	i = 0;
	if (a_len > b_len)
	{
		while (i < b_len)
		{
			a[i] = a[i] + b[i];
			if (a[i] > 9)
			{
				a[i + 1] = a[i + 1] + (a[i] / 10);
				a[i] = a[i] % 10;
			}
			++i;
			while (a[i] > 10)
			{
				a[i + 1] = a[i + 1] + (a[i] / 10);
				a[i] = a[i] % 10;
			}

		}
	}
}

int 			main(void)
{
	__int128	li;
	int			exp = -5;
	int			digit = 2;
	int			exp2 = -4;
	int			digit2 = 2;
	int			len_arr = -exp;
	int			len_arr2 = -exp2;
	int			tmp = len_arr;
	int			tmp2 = len_arr2;
	int			arr[len_arr];
	int			arr2[len_arr2];

	printf("exp %d\ndigit %d\ncreate len_arr -------->>>>>>>>>>>>> %d\n", exp, digit, len_arr);
	printf("exp2 %d\ndigit2 %d\ncreate len_arr2 -------->>>>>>>>>>>>> %d\n", exp2, digit2, len_arr2);
	if (len_arr < 2097152 && len_arr2 < 2097152)
	{
//		pos_exp_of_digit(digit, exp, len_arr, arr);
//		pos_exp_of_digit(digit2, exp2, len_arr2, arr2);
		neg_exp_of_digit_two(digit, exp, len_arr, arr);
		neg_exp_of_digit_two(digit2, exp2, len_arr2, arr2);
		li = 0;
		while (li < len_arr)
			printf("%d", arr[li++]);
		printf("\n");
		li = 0;
		while (li < len_arr2)
			printf("%d", arr2[li++]);
		printf("\n");
		printf("real len_arr -------->>>>>>>>>>>>> %d\n", len_arr + 1);
		printf("real len_arr2 -------->>>>>>>>>>>>> %d\n", len_arr2 + 1);
		printf("digit one -------->>>>>>>>>>>>> ");
//		while (len_arr >= 0)
//			printf("%d", arr[len_arr--]);
//		printf("\n");
//		printf("digit two -------->>>>>>>>>>>>> ");
//		while (len_arr2 >= 0)
//			printf("%d", arr2[len_arr2--]);
//		printf("\n");
		if (tmp > tmp2)
		{
			sum_two_digits(arr, arr2, tmp, tmp2);
			printf("real size arr ----->>>>>>>> %d\nresul sum = ", tmp + 1);
			while (--tmp >= 0)
				printf("%d", arr[tmp]);
			printf("\n");
		}
		else
		{
			sum_two_digits(arr2, arr, tmp2, tmp);
			printf("real size arr ----->>>>>>>> %d\nresul sum = ", tmp2 + 1);
			while (--tmp2 >= 0)
				printf("%d", arr2[tmp2]);
			printf("\n");
		}
	}
}

/*
 *
 * 11111111111111111000000000000000000000000000000000000000000000000000000000000000 -Inf
 * 01111111111111111000000000000000000000000000000000000000000000000000000000000000 +Inf
 * 01111111111111111100000000000000000000000000000000000000000000000000000000000000 NaN
 */