/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:38:58 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/21 15:01:12 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int						main(void)
{
	int					my;
	int					sy;
	long double			d;

	d = 579.64566;
	ft_printf("<<<<<<ft_printf>>>>>>\n");
	my = ft_printf("%-.20o\n", 2500);
	ft_printf("<<<<<<printf>>>>>>\n");
	sy = printf("%-.20o\n", 2500);
	printf("my = %d sy = %d\n", my, sy);
	return (0);
}
