/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_preparation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 14:12:17 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/11 09:12:52 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			result_preparation(va_list ap)
{
	if (s_data.specifier == 'c')
		print_char(va_arg(ap, int));
	else if (s_data.specifier == 's')
		print_string(va_arg(ap, char *));
}
