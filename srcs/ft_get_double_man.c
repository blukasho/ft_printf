/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_double_man.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 08:33:58 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/28 21:36:08 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static t_neg_exp_of_digit	*init(void)
{	
	t_neg_exp_of_digit		*r;

	r = (t_neg_exp_of_digit *)malloc(sizeof(t_neg_exp_of_digit));
	ft_bzero(r, sizeof(t_neg_exp_of_digit));
	r->r_len = 1;
	r->r = (int *)malloc(r->r_len * sizeof(int));
	ft_bzero(r->r, r->r_len * sizeof(int));
	return (r);
}

static void					del(t_neg_exp_of_digit *n)
{
	ft_memdel((void **)&n->r);
	if (n->div)
		ft_memdel((void **)&n->div);
	if (n->per)
		ft_memdel((void **)&n->per);
	ft_memdel((void **)&n);
}

t_neg_exp_of_digit			*ft_get_double_man(t_bits *b)
{
	t_neg_exp_of_digit		*r;
	t_neg_exp_of_digit		*tmp;
	t_neg_exp_of_digit		*tmp2;
	int						bits;
	int						m;

	m = -1;
	r = init();
	bits = b->e - 16383;
	if (bits < 63)
	{
		bits = 63 - bits;
		while (bits >= 0)
		{
			if (b->m[--bits] == '1')
			{
				tmp = r;
				tmp2 = ft_neg_exp_of_digit(2, m);
				r = ft_sum(tmp2, r);
				del(tmp);
				del(tmp2);
			}
			--m;
		}
	}
	return (r);
}
