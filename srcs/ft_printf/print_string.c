/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 09:52:13 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/20 10:15:19 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	print(char *s, int len, int prs)
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
		if (!ft_strchr(s_data.flags, '0'))
		{
			while (s_data.width-- > len)
				ft_printf_put_char(' ');
			while (*s && prs--)
				ft_printf_put_char(*(s++));
		}
		else
		{
			while (s_data.width-- > len)
				ft_printf_put_char(' ');
			while (*s && prs--)
				ft_printf_put_char(*(s++));
		}
	}
}

//print with 0
static void		preparation(char *s)
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
		print(s, len, prs);
	else
		while (*s && prs--)
			ft_printf_put_char(*(s++));
}

void			print_string(va_list ap)
{
	preparation(va_arg(ap, char *));
}
