/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 14:18:12 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/10 18:06:29 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		print_char(int c)
{
	if (s_data.width > 1 && ft_strchr(s_data.flags, '-'))
	{
		ft_putchar(c);
		while (s_data.width-- > 1)
			ft_putchar(' ');
	}
	else
	{
		while (s_data.width-- > 1)
			ft_putchar(' ');
		ft_putchar(c);
	}
}

void		print_string(char *s)
{
	ft_putstr(s);
}
