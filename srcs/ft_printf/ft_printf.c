/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:11:35 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/13 15:52:11 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	g_print_symbols = 0;
	while (*format)
		if (*format == '%')
			main_function(&format, ap);
		else
			ft_printf_put_char(*(format++));
	va_end(ap);
	return (g_print_symbols);
}

void		ft_printf_put_char(char c)
{
	write(1, &c, 1);
	++g_print_symbols;
}
