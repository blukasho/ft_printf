/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:03:03 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/16 19:41:18 by blukasho         ###   ########.fr       */
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
	char				*s = "Hell!";
	unsigned long long	d = 28;
    ft_printf("<<<<<<ft_printf>>>>>>\n");
	my = ft_printf("%060p\n", s);
	ft_printf("<<<<<<printf>>>>>>\n");
	sy = printf("%#x\n", d);
	printf("my = %d sy = %d\n", my, sy);
	return (0);
}
