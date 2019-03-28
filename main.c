/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:38:58 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/28 22:34:59 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int						main(void)
{
	int					my;
	int					sy;
	char				*s;
	float				b;
	float				a;

	a = 0;
	b = 0.0;


	s = "|%.70f|\n";

	ft_printf("<<<<<<ft_printf>>>>>>\n");
	my = ft_printf(s, 2.0/0.0);
	ft_printf("<<<<<<printf>>>>>>\n");
	sy = printf(s, 0.0);
	printf("my = %d sy = %d\n", my, sy);
	return (0);
}

/*
 *
 */
