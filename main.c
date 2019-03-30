/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 10:23:32 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/30 19:22:31 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int					main(void)
{
	int				my;
	int				sy;
	double			ld;
	char			*s;

	ld = 6.5;

	s = "|%.100F|\n";

	my = ft_printf(s, ld);
    sy = printf(s, ld);
	printf("my = %d, sy = %d\n", my, sy);
	return (0);
}
