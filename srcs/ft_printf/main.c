/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:03:03 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/13 16:51:53 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	main_function(const char **format, va_list ap)
{
	parse_format_specifiers(format);
	result_preparation(ap);
}

int						main(void)
{
	int					my;
	int					sy;
	unsigned long long	d = 92299999999999999;
    ft_printf("<<<<<<ft_printf>>>>>>\n");
	my = ft_printf("%+30.20d\n", d);
	ft_printf("<<<<<<printf>>>>>>\n");
	sy = printf("%+30.20d\n", d);
	printf("my = %d sy = %d\n", my, sy);
	return (0);
}
