/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_arr_subtr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:57:27 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/15 17:50:12 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void				get_real_len(int *a, int *b, int *a_len, int *b_len)
{
	while (a[*a_len] == 0)
		--(*a_len);
	while (b[*b_len] == 0)
		--(*b_len);
}

/*
** a_len == b_len
*/

static void				copy_arrays(int *a, int *b, int a_len)
{
	int					i;

	i = -1;
	while (++i < a_len)
		b[i] = a[i];
}

t_int_arr_subtr			*ft_int_arr_subtr(int *a, int *b, int a_len, int b_len)
{
	t_int_arr_subtr		*s;

	s = (t_int_arr_subtr*)malloc(sizeof(t_int_arr_subtr));
	ft_bzero(s, sizeof(t_int_arr_subtr));
	s->r = (int *)malloc(a_len * sizeof(int));
	s->r_len = a_len;
	ft_brezo(s->r, s->r_len * sizeof(int)); 
	get_real_len(a, b, &a_len, &b_len);
	copy_arrays(a, s->r, a_len);
	while (s->count <= b_len)
	{
		if (s->r[s->count] >= b[s->count])
			s->r[s->count] = s->r[s->count] - b[s->count];
		else
		{
			s->find = s->count + 1;
			while (s->r[s->find] == 0)
				s->r[s->find++] = 9;
			--(s->r[s->find]);
			s->r[s->count] = (s->r[s->count] + 10) - b[s->count];
		}
		++(s->count);
	}
	return (s);
}
