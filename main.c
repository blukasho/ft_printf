/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:38:58 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/04 19:40:06 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int						main(void)
{
	int					my;
	int					sy;
	int					d;
	char				*s;
	double				a;
	double				b;

	a = -1.0;
	b = 0.0;

	d = 0;

	s = "|%010.2F|\n";

	ft_printf("<<<<<<ft_printf>>>>>>\n");
	my = ft_printf(s, a/b);
	ft_printf("<<<<<<printf>>>>>>\n");
	sy = printf(s, a/b);
	printf("my = %d sy = %d\n", my, sy);
	return (0);
}
