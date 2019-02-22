/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:25:32 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/22 14:26:22 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void				reverse_double(char *s)
{
	int				start;
	int				end;
	char			tmp;

	end = 0;
	while (s[end] != '.' && !(start = 0))
		++end;
	if (s_data.precision <= 0)
		s[end] = '\0';
	while (start < end && (tmp = s[start]))
	{
		s[start++] = s[--end];
		s[end] = tmp;
	}
}
