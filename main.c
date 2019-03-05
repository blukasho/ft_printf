/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:38:58 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/05 21:33:46 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int						main(void)
{
	int					my;
	int					sy;
	char				*s;
	double				b;

	b = 3.45;


	s = "|%F|\n";

	ft_printf("<<<<<<ft_printf>>>>>>\n");
	my = ft_printf(s, 0.0);
	ft_printf("<<<<<<printf>>>>>>\n");
	sy = printf(s, 0.0);
	printf("my = %d sy = %d\n", my, sy);
	return (0);
}
