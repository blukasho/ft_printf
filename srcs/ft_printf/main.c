/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:03:03 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/20 17:22:56 by blukasho         ###   ########.fr       */
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
	long double			d = -5;
    ft_printf("<<<<<<ft_printf>>>>>>\n");
	my = ft_printf("%.160Lf\n", d);
	ft_printf("<<<<<<printf>>>>>>\n");
	sy = printf("%.160Lf\n", d);
	printf("my = %d sy = %d\n", my, sy);
	return (0);
}
