/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:38:58 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/26 21:19:00 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int						main(void)
{
	int					my;
	int					sy;
	long double			d;
	char				*s;

	d = 0;

	s = "|%#5hhx|\n";

	ft_printf("<<<<<<ft_printf>>>>>>\n");
	my = ft_printf(s, 0);
	ft_printf("<<<<<<printf>>>>>>\n");
	sy = printf(s, 0);
	printf("my = %d sy = %d\n", my, sy);
	return (0);
}
