/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 14:18:12 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/11 10:19:09 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		print_char(int c)
{
	if (s_data.width > 1 && ft_strchr(s_data.flags, '-'))
	{
		ft_putchar(c);
		while (s_data.width-- > 1)
		{
			++g_print_symbols;
			ft_putchar(' ');
		}
		++g_print_symbols;
	}
	else
	{
		while (s_data.width-- > 1)
		{
			++g_print_symbols;
			ft_putchar(' ');
		}
		ft_putchar(c);
		++g_print_symbols;
	}
}

void		print_string(char *s)
{
	int		len;

	len = ft_strlen(s);
	if (s_data.width > len)
	{
		if (ft_strchr(s_data.flags, '-'))
		{
			while (*s && ++g_print_symbols)
				ft_putchar(*(s++));
			while (s_data.width-- > len)
			{
				ft_putchar(' ');
				++g_print_symbols;
			}
		}
		else
		{
			while (s_data.width-- > len)
			{
				ft_putchar(' ');
				++g_print_symbols;
			}
			while (*s && ++g_print_symbols)
				ft_putchar(*(s++));
		}
	}
	else
		while (*s && ++g_print_symbols)
			ft_putchar(*(s++));
}
