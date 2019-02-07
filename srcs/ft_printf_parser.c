/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 18:20:26 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/07 11:55:04 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

//delete function
static void	print_flags(void)
{
	int		c;

	c = 0;
	while (c < 5)
		ft_putchar(s_data.flags[c++]);
}

static int	check_format_symbol(char c)
{
	return ((c == '#' || c == '0' || c == ' ' || c == '+' || c == '-' ? 1 : 0));
}

static void	parse_flags(const char **format)
{
	while (**format == '%')
		++(*(format));
	while (check_format_symbol(**format))
		if (**format == '#' && (s_data.flags[0] = '#'))
			++(*format);
		else if (**format == '0' && (s_data.flags[1] = '0'))
			++(*format);
		else if (**format == ' ' && (s_data.flags[2] = ' '))
			++(*format);
		else if (**format == '+' && (s_data.flags[3] = '+'))
			++(*format);
		else if (**format == '-' && (s_data.flags[4] = '-'))
			++(*format);
}

void		parse_format_specifiers(const char **format)
{
	parse_flags(format);
	print_flags();
}
