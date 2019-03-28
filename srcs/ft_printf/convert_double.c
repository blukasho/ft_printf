/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 09:58:26 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/28 10:09:11 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_double_res	*init(void)
{
	t_double_res	*r;

	r = (t_double_res *)malloc(sizeof(t_double_res));
	return (r);
}

t_double_res		*convert_double(long double ld)
{
	t_double_res	*r;
	t_bits			*b;
	int				i;

	b = ft_get_double_bits(ld);
	r = init();
	r->e = ft_get_double_exp(b);
	r->m = ft_get_double_man(b);
	i = 0;
	while (i < r->m->r_len - 1)
	{
		r->m->r[i] = r->m->r[i + 1];
		++i;
	}
	return (r);
}
