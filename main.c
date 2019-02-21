/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:38:58 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/21 22:08:54 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int						main(void)
{
	int					my;
	int					sy;
	float				d;

	d = 0.5;
	ft_printf("<<<<<<ft_printf>>>>>>\n");
	my = ft_printf("%.f\n", d);
	ft_printf("<<<<<<printf>>>>>>\n");
	sy = printf("%.f\n", d);
	printf("my = %d sy = %d\n", my, sy);
	return (0);
}
