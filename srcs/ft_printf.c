/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:11:35 by blukasho          #+#    #+#             */
/*   Updated: 2019/01/25 16:08:23 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*s;

	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
			ft_putchar(*(format++));
		else if (!ft_strncmp("%d", format, 2) && (format += 2))
			ft_putnbr(va_arg(ap, int));
		else if (!ft_strncmp("%s", format, 2) && (format += 2))
			s = va_arg(ap, char *); //Slojno niponyatno
	}
	va_end(ap);
	return (0);
}
