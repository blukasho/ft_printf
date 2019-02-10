/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:03:03 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/10 23:38:04 by blukasho         ###   ########.fr       */
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
	int	my;
	int	sy;
    ft_printf("<<<<<<ft_printf>>>>>>\n");
	my = ft_printf("%c%c%cdddddddd\n", 'D', 'C', 'P');
	ft_printf("<<<<<<printf>>>>>>\n");
	sy = printf("%c%c%cdddddddd\n", 'D', 'C', 'P');
	printf("my = %d sy = %d\n", my, sy);
	return (0);
}
