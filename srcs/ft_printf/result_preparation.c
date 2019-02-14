/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_preparation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 14:12:17 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/14 13:01:33 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		srcrpl(char *s, char a, char b)
{
	while (*s)
		if (*s++ == a)
			*(s - 1) = b;
	return (1);
}

static	void	result_preparation_2(va_list ap)
{
	if (s_data.specifier == 'u' && !s_data.length
		&& srcrpl(s_data.flags, '+', -1))
		print_digits(va_arg(ap, unsigned int));
	else if (s_data.specifier == 'u' && s_data.length == 1
			&& srcrpl(s_data.flags, '+', -1))
		print_digits(va_arg(ap, unsigned long));
	else if (s_data.specifier == 'u' && s_data.length == 2
			&& srcrpl(s_data.flags, '+', -1))
		print_digits(va_arg(ap, unsigned long long));
	else if (s_data.specifier == 'u' && s_data.length == 4
			&& srcrpl(s_data.flags, '+', -1))
		print_digits((unsigned short)va_arg(ap, unsigned int));
	else if (s_data.specifier == 'u' && s_data.length == 5
			&& srcrpl(s_data.flags, '+', -1))
		print_digits((unsigned char)va_arg(ap, unsigned int));
	else if (s_data.specifier == 'o' && !s_data.length)
		print_octal(va_arg(ap, unsigned int));
}

void			result_preparation(va_list ap)
{
	if (s_data.specifier == 'c')
		print_char(va_arg(ap, int));
	else if (s_data.specifier == 's')
		print_string(va_arg(ap, char *));
	else if(s_data.specifier == '%')
		print_char('%');
	else if ((s_data.specifier == 'd' || s_data.specifier == 'i')
			&& !s_data.length)
		print_digits(va_arg(ap, int));
	else if ((s_data.specifier == 'd' || s_data.specifier == 'i')
			&& s_data.length == 1)
		print_digits(va_arg(ap, long));
	else if ((s_data.specifier == 'd' || s_data.specifier == 'i')
			&& s_data.length == 2)
		print_digits(va_arg(ap, long long));
	else if ((s_data.specifier == 'd' || s_data.specifier == 'i')
			&& s_data.length == 4)
		print_digits((short)va_arg(ap, int));
	else if ((s_data.specifier == 'd' || s_data.specifier == 'i')
			&& s_data.length == 5)
		print_digits((char)va_arg(ap, int));
	else
		result_preparation_2(ap);
}
