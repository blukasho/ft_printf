/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 21:44:36 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/15 14:46:18 by blukasho         ###   ########.fr       */
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
 * Array a must be bigger than b
 * Resul write in a
 */

void			sum_two_digits(int *a, int *b, int  a_len, int b_len)
{
	int			i;

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

/*
 * Subtract a from b
 * result write in a;
 * a must be less than b
 */

#include <stdlib.h>
#include "../includes/libft.h"

typedef struct			s_int_arr_subtract
{                       
	int					flag;
	int					find;
	int					count;
}						t_int_arr_subtract;

int						int_arr_subtract(int *a, int *b, int a_len, int b_len)
{
	t_int_arr_subtract	*s;

	s = (t_int_arr_subtract*)malloc(sizeof(t_int_arr_subtract));
	ft_bzero(s, sizeof(t_int_arr_subtract));
	while (a[--a_len] == 0)
		;
	while (b[--b_len] == 0)
		;
	while (s->count <= b_len)
	{
		if (a[s->count] >= b[s->count])
			a[s->count] = a[s->count] - b[s->count];
		else
		{
			s->find = s->count + 1;
			while (a[s->find] == 0)
				a[s->find++] = 9;
			--(a[s->find]);
			a[s->count] = (a[s->count] + 10) - b[s->count];
		}
		++(s->count);
	}
	free(s);
	return (0);
}


//typedef struct					s_int_arr_mult
//{
//	int							*r;
//	int							a_tmp;
//	int							b_tmp;
//	int							r_len;
//}								t_int_arr_mult;
//
//t_int_arr_mult		*int_arr_mult(int *a, int *b, int a_len, int b_len)
//{
//	t_int_arr_mult	*s;
//
//	s = (t_int_arr_mult *)malloc(sizeof(t_int_arr_mult));
//	ft_bzero(s, sizeof(t_int_arr_mult));
//	while (a[--a_len] == 0)
//		;
//	while (b[--b_len] == 0)
//		;
//	s->r_len = a_len + b_len + 2;
//	s->r = (int *)malloc(s->r_len * sizeof(int));
//	ft_bzero(s->r, sizeof(s->r));
//	while (s->a_tmp <= a_len)
//	{
//		s->b_tmp = -1;
//		while (++(s->b_tmp) <= b_len )
//			s->r[s->a_tmp + s->b_tmp] += a[s->a_tmp] * b[s->b_tmp];
//		++(s->a_tmp);
//	}
//	a_len = -1;
//	while (++a_len < s->r_len)
//	{
//		s->r[a_len + 1] += s->r[a_len] / 10;
//		s->r[a_len] %= 10;
//	}
//	return (s);
//}

int 			main(void)
{
	int			li;
	int			exp = 33;
	int			digit = 51;
	int			exp2 = 52;
	int			digit2 = 47;
	int			len_arr = len_of_digit(digit) * exp;
	int			len_arr2 = len_of_digit(digit2) * exp2;

	int			tmp = len_arr;
	int			tmp2 = len_arr2;

	printf("exp %d\ndigit %d\ncreate len_arr -------->>>>>>>>>>>>> %d\n", exp, digit, len_arr);
	printf("exp2 %d\ndigit2 %d\ncreate len_arr2 -------->>>>>>>>>>>>> %d\n", exp2, digit2, len_arr2);
	if (len_arr < 2097152 && len_arr2 < 2097152)
	{
		int			*arr = (int *)malloc(len_arr * sizeof(int));
		int			*arr2 = (int *)malloc(len_arr2 * sizeof(int));
		ft_bzero(arr, len_arr * sizeof(int));
		ft_bzero(arr2, len_arr2 * sizeof(int));

		pos_exp_of_digit(digit, exp, len_arr, arr);
		pos_exp_of_digit(digit2, exp2, len_arr2, arr2);
		while (arr[--len_arr] == 0 && len_arr)
			;
		while (arr2[--len_arr2] == 0 && len_arr2)
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
		printf("\n         ");

		t_int_arr_mult	*s;
	
		s = ft_int_arr_mult(arr, arr2, tmp, tmp2);
		s->a_tmp = s->r_len;
		while (--(s->a_tmp) >= 0)
			printf("%d", s->r[s->a_tmp]);
		printf("\n");

//		printf("result equals a");
//		li = int_arr_comparing(arr, arr2, tmp, tmp2);
//		if (li == 1)
//			printf(" > b\n");
//		else if (li == -1)
//			printf(" < b\n");
//		else
//			printf(" = b\n");
//
//		int_arr_subtract(arr, arr2, tmp, tmp2);
//		len_arr = tmp;
//		while (arr[--len_arr] == 0)
//			;
//		printf("a - b =                         ");
//		while (len_arr >= 0)
//			printf("%d", arr[len_arr--]);
//		printf("\n");

//		if (tmp > tmp2)
//		{
//			sum_two_digits(arr, arr2, tmp, tmp2);
//			printf("real size arr ----->>>>>>>> %d\nresul sum = ", tmp + 1);
//			while (arr[--tmp] == 0)
//				;
//			while (tmp >= 0)
//				printf("%d", arr[tmp--]);
//			printf("\n");
//		}
//		else
//		{
//			sum_two_digits(arr2, arr, tmp2, tmp);
//			printf("real size arr ----->>>>>>>> %d\nresul sum = ", tmp2 + 1);
//			while (arr2[--tmp2] == 0)
//				;
//			while (tmp2 >= 0)
//				printf("%d", arr2[tmp2--]);
//			printf("\n");
//		}
	ft_memdel((void **)&s->r);
	ft_memdel((void **)&s);
	ft_memdel((void **)&arr);
	ft_memdel((void **)&arr2);
//	system("leaks a.out");
	}
}

/*
 *
 * 11111111111111111000000000000000000000000000000000000000000000000000000000000000 -Inf
 * 01111111111111111000000000000000000000000000000000000000000000000000000000000000 +Inf
 * 01111111111111111100000000000000000000000000000000000000000000000000000000000000 NaN
 */
