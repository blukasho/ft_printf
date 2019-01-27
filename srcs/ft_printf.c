/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:11:35 by blukasho          #+#    #+#             */
/*   Updated: 2019/01/26 12:06:56 by blukasho         ###   ########.fr       */
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
		if (!ft_strncmp(format, "%s", 2))
		{
			if ((s = va_arg(ap, char *)))
				ft_putstr(s);
			format += 2;
		}
		else
			ft_putchar(*(format++));
	}
	va_end(ap);
	return (0);
}
