/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_neg_exp_of_digit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:26:33 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/20 18:18:08 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static t_neg_exp_of_digit	*init(int dig, int base, int div)
{
	t_neg_exp_of_digit		*s;

	s = (t_neg_exp_of_digit *)malloc(sizeof(t_neg_exp_of_digit));
	ft_bzero(s, sizeof(t_neg_exp_of_digit));
	s->r_len = dig * base;
	s->r = (int *)malloc(s->r_len * sizeof(int));
	ft_bzero(s->r, s->r_len * sizeof(int));
	s->div_len = div;
	s->div = (int *)malloc(s->div_len * sizeof(int));
	ft_bzero(s->div, s->div_len * sizeof(int));
	s->div[0] = 1;
	s->sw = 1;
	s->r_pos = 1;
	s->tmp = 1;
	return (s);
}

static void					move_int_arr(int *a, int a_len)
{
	while (a[--a_len] == 0)
		;
	while (a_len >= 0)
	{
		a[a_len + 1] = a[a_len];
		a[a_len] = 0;
		--a_len;
	}
}

static int					get_result_sum(int a, int b, int a_len, int b_len)
{
	int						c;
	int						i;
	int						r;
	t_sum_two_digits		*sum;
	t_sum_two_digits		*tmp;

	i = 1;
	r = -1;
	c = 0;
	sum = (t_sum_two_digits *)malloc(sizeof(t_sum_two_digits));
	ft_bzero(sum, sizeof(t_sum_two_digits));
	sum->r_len = 1;
	sum->r = (int *)malloc(sum->r_len * sizeof(int));
	ft_bzero(sum->r, sum->r_len * sizeof(int));
	while (ft_int_arr_comparing(a, sum->r, a_len, sum->r_len) >= 0)
	{
		tmp = sum;
		sum = ft_sum_two_digits(tmp->r, b, tmp->r_len, b_len);
		++r;
		c = sum->r_len;
		ft_memdel((void **)&tmp->r);
		ft_memdel((void **)&tmp);
	}
	return (r);
}

static void					get_subt_res(t_neg_exp_of_digit *n, t_pos_exp_of_digit *p)
{
	t_int_arr_subtr			*m;
	int						i;

	while (ft_int_arr_comparing(n->div, p->r, n->div_len, p->r_len) >= 0)
	{
		i = 0;
		m = ft_int_arr_subtr(n->div, p->r, n->div_len, p->r_len);
		while (i < n->div_len)
			n->div[i++] = 0;
		while (m->r_len >= 0 && m->r[--(m->r_len)] == 0)
			;
		while (m->r_len >= 0)
		{
			n->div[m->r_len] = m->r[m->r_len];
			--(m->r_len);
		}
	}
}

static int					get_result(int *a, int a_len)
{
	while (--a_len >= 0)
		if (a[a_len] > 0)
			return (1);
	return (0);
}

t_neg_exp_of_digit			*ft_neg_exp_of_digit(int dig, int base)
{
	t_neg_exp_of_digit		*neg;
	t_pos_exp_of_digit		*pos;
	int						i;

	base = -base;
	pos = ft_pos_exp_of_digit(dig, base);
	neg = init(dig, base, pos->r_len);
	while (get_result(neg->div, neg->div_len))
	{
		while (ft_int_arr_comparing(neg->div, pos->r, neg->div_len, pos->r_len) == -1)
		{
			move_int_arr(neg->div, neg->div_len);
			if (ft_int_arr_comparing(neg->div, pos->r, neg->div_len, pos->r_len) == -1)
				neg->r[neg->r_pos++] = 0;
		}
		neg->r[neg->r_pos++] = get_result_sum(neg->div, pos->r, neg->div_len, pos->r_len);
		get_subt_res(neg, pos);
	}
	return (neg);
}
