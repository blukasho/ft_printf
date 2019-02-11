/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_preparation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 14:12:17 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/11 17:39:49 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			result_preparation(va_list ap)
{
	if (s_data.specifier == 'c')
		print_char(va_arg(ap, int));
	else if (s_data.specifier == 's')
		print_string(va_arg(ap, char *));
	else if(s_data.specifier == 'p')
	{
	}
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
		print_digits(va_arg(ap, char));
}
