/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 14:18:12 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/13 12:39:15 by blukasho         ###   ########.fr       */
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


//add precision and replace put_char
void		print_string(char *s)
{
	int		len;
	int		prs;

	len = ft_strlen(s);
	prs = len;
	if ((s_data.precision >= 0) && (s_data.precision < len))
	{
		len = s_data.precision;
		prs = len;
	}
	if (s_data.width > len)
	{
		if (ft_strchr(s_data.flags, '-'))
		{
			while (*s && prs--) 
				ft_printf_put_char(*(s++));
			while (s_data.width-- > len)
				ft_printf_put_char(' ');
		}
		else
		{
			while (s_data.width-- > len)
				ft_printf_put_char(' ');
			while (*s && prs--)
				ft_printf_put_char(*(s++));
		}
	}
	else
		while (*s && prs--)
			ft_printf_put_char(*(s++));
}
