/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_neg_exp_of_digit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:26:33 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/19 08:37:52 by blukasho         ###   ########.fr       */
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
	return (s);
}

t_neg_exp_of_digit			*ft_neg_exp_of_digit(int dig, int base)
{
	t_neg_exp_of_digit		*neg;
	t_pos_exp_of_digit		*pos;

	base = -base;
	pos = ft_pos_exp_of_digit(dig, base);
	neg = init(dig, base, pos->r_len);
	while (neg->sw)
	{
		while (ft_int_arr_comparing(neg->div, pos->r, neg->div_len, pos->r_len) == -1)
		{

		}
		neg->sw = 0;
	}
	return (neg);
}
