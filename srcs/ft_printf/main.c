/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:03:03 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/11 17:39:49 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	main_function(const char **format, va_list ap)
{
	parse_format_specifiers(format);
	result_preparation(ap);
}

int				main(void)
{               
	int			my;
	int			sy;
	char		*s = "TEST";
	long long	d = 11919919191919191999;
    ft_printf("<<<<<<ft_printf>>>>>>\n");
	my = ft_printf("%#+-+ 010.10%\n", d);
	ft_printf("<<<<<<printf>>>>>>\n");
	sy = printf("%#+-+ 010.10%\n", d);
	printf("my = %d sy = %d\n", my, sy);
	return (0);
}
