/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:12:42 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/27 18:48:54 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			print_width_octal(char c)
{
	while (s_data.width-- > 0)
		ft_printf_put_char(c);
}

void			print_precision_octal(int l)
{
	if (s_data.precision > l)
		s_data.width -= s_data.precision;
	else
		s_data.width -= l;
	while (s_data.precision-- > l)
		ft_printf_put_char('0');
}
