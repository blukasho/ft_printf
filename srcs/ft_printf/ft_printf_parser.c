/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 09:46:35 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/04 09:55:04 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void			clear_s_data(void)
{
	int			c;

	c = -1;
	while (++c < 5)
		s_data.flags[c] = -1;
	s_data.width = -1;
	s_data.precision = -1;
	s_data.length = 0;
	s_data.specifier = -1;
}

static void		skip_digits(const char **format)
{
	while (ft_isdigit(**format))
		++(*(format));
}

static void		get_length(const char **format)
{
	if (!ft_strncmp(*format, "ll", 2) && (s_data.length = 2))
		*format += 2;
	else if (!ft_strncmp(*format, "hh", 2) && (s_data.length = 5))
		*format += 2;
	else if (!ft_strncmp(*format, "l", 1) && (s_data.length = 1))
		++(*(format));
	else if (!ft_strncmp(*format, "h", 1) && (s_data.length = 4))
		++(*(format));
	else if (!ft_strncmp(*format, "L", 1) && (s_data.length = 3))
		++(*(format));
}

static void		get_specifier(const char **format)
{
	if ((**format == 'd' || **format == 'i' || **format == 'o'
		|| **format == 'u' || **format == 'x' || **format == 'x'
		|| **format == 'X' || **format == 'f' || **format == '%'
		|| **format == 'c' || **format == 's' || **format == 'p'
		|| **format == 'F')
		&& (s_data.specifier = **format))
		++(*(format));
}

void			parse_format_specifiers(const char **format)
{
	clear_s_data();
	parse_flags(format);
	s_data.width = ft_atoi(*format);
	if (s_data.width > -1)
		skip_digits(format);
	if (**format == '.')
	{
		s_data.precision = ft_atoi(++(*(format)));
		skip_digits(format);
	}
	get_length(format);
	get_specifier(format);
}
