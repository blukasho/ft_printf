/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 10:23:32 by blukasho          #+#    #+#             */
/*   Updated: 2019/04/01 13:29:53 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int					main(void)
{
	int				my;
	int				sy;
	float			ld;
	char			*s;

	ld = 2.51;
	s = "|%.0F|\n";
	my = ft_printf(s, ld);
	sy = printf(s, ld);
	printf("my = %d, sy = %d\n", my, sy);
	return (0);
}
