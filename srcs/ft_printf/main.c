/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:03:03 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/10 18:39:41 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	main_function(const char **format, va_list ap)
{
	parse_format_specifiers(format);
	result_preparation(format, ap);
}

int		main(void)
{
	ft_printf("<<<<<<ft_printf>>>>>>\n");
	ft_printf("%#-+-+-+10.20c\n%#-+-+-+10.20c\n%#-+-+-+10.20c\n""", 'D', 'C', 'P');
	ft_printf("<<<<<<printf>>>>>>\n");
	printf("%#-+-+-+10.20c\n", "sd");
	return (0);
}
