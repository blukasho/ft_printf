/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:03:03 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/09 19:35:09 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	main_function(const char **format, va_list *ap)
{
	parse_format_specifiers(format);
}

int		main(void)
{
//	ft_putnbr(ft_printf("Hello,%#-+ 0123456.10llcWorld!!!\n", 7));
//	ft_putendl("");
	printf("Hello, %-10.5d World!!!\n", 733);
	return (0);
}
