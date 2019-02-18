/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_digits.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:25:08 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/18 09:45:18 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_unsigned_digits(va_list ap)
{
	s_data.flags[2] = -1;
	if (s_data.specifier == 'u' && !s_data.length
		&& srcrpl(s_data.flags, '+', -1))
		print_all_digits(va_arg(ap, unsigned int));
	else if (s_data.specifier == 'u' && s_data.length == 1
			&& srcrpl(s_data.flags, '+', -1))
		print_all_digits(va_arg(ap, unsigned long));
	else if (s_data.specifier == 'u' && s_data.length == 2
			&& srcrpl(s_data.flags, '+', -1))
		print_all_digits(va_arg(ap, unsigned long long));
	else if (s_data.specifier == 'u' && s_data.length == 4
			&& srcrpl(s_data.flags, '+', -1))
		print_all_digits((unsigned short)va_arg(ap, unsigned int));
	else if (s_data.specifier == 'u' && s_data.length == 5
			&& srcrpl(s_data.flags, '+', -1))
		print_all_digits((unsigned char)va_arg(ap, unsigned int));
}

