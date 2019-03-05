/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:38:58 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/05 13:49:59 by blukasho         ###   ########.fr       */
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

	s = "|%.70F|\n";

	ft_printf("<<<<<<ft_printf>>>>>>\n");
	my = ft_printf(s, 0.0);
	ft_printf("<<<<<<printf>>>>>>\n");
	sy = printf(s, 0.0);
	printf("my = %d sy = %d\n", my, sy);
	return (0);
}
