/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 10:23:32 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/30 23:36:27 by blukasho         ###   ########.fr       */
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

	ld = 0.5;

	s = "|%.F|\n";

	my = ft_printf(s, ld);
    sy = printf(s, ld);
	printf("my = %d, sy = %d\n", my, sy);
	return (0);
}
