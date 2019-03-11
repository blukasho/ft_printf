/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:38:58 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/11 20:48:14 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int						main(void)
{
	int					my;
	int					sy;
	char				*s;
	double				b;

	b = 3495837459.3450934850984305984;


	s = "|%+F|\n";

	ft_printf("<<<<<<ft_printf>>>>>>\n");
	my = ft_printf(s, b);
	ft_printf("<<<<<<printf>>>>>>\n");
	sy = printf(s, b);
	printf("my = %d sy = %d\n", my, sy);
	return (0);
}

/*
 *
 */
