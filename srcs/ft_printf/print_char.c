/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 14:18:12 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/21 11:44:49 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		print_char(va_list ap)
{
	print_c(va_arg(ap, int));
}

void		print_c(int c)
{
	if (s_data.width > 1 && ft_strchr(s_data.flags, '-'))
	{
		ft_printf_put_char(c);
		while (s_data.width-- > 1)
			ft_printf_put_char(' ');
	}
	else
	{
		if (!ft_strchr(s_data.flags, '0'))
			while (s_data.width-- > 1)
				ft_printf_put_char(' ');
		else
			while (s_data.width-- > 1)
				ft_printf_put_char('0');
		ft_printf_put_char(c);
	}
}
