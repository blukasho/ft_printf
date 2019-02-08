/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 18:20:26 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/08 16:12:17 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

//debug function
void		print_s_data(void)
{
	int		c;

	c = 0;
	ft_putendl("\n<<<<<<<<<s_data>>>>>>>>>");
	while (c < 5)
		ft_putchar(s_data.flags[c++]);
	ft_putstr("\nwidth ");
	ft_putnbr(s_data.width);
	ft_putstr("\nprecision ");
	ft_putnbr(s_data.precision);
	ft_putstr("\nlength ");
	ft_putnbr(s_data.length);
	ft_putstr("\nspecifier ");
	ft_putchar(s_data.specifier);
	ft_putendl("\n<<<<<<<<<s_data>>>>>>>>>");
}

static int	check_format_symbol(char c)
{
	return ((c == '#' || c == '0' || c == ' ' || c == '+' || c == '-' ? 1 : 0));
}

void		parse_flags(const char **format)
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
