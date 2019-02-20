/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_preparation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 14:12:17 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/20 10:08:11 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				srcrpl(char *s, char a, char b)
{
	while (*s)
		if (*s++ == a)
			*(s - 1) = b;
	return (1);
}

void			result_preparation(va_list ap)
{
	if (s_data.specifier == 'd' || s_data.specifier == 'i')
		print_digits(ap);
	else if (s_data.specifier == 'u')
		print_unsigned_digits(ap);
	else if (s_data.specifier == 'o')
		print_octal(ap);
	else if(s_data.specifier == '%')
		print_percent(ap);
	else if (s_data.specifier == 'c')
		print_char(ap);
	else if (s_data.specifier == 's')
		print_string(ap);
	else if (s_data.specifier == 'x' || s_data.specifier == 'X')
		print_hexdecimal(ap);
	else if (s_data.specifier == 'p')
		print_pointer(ap);
	else if (s_data.specifier == 'f' || s_data.specifier == 'F')
		print_double(ap);
}
