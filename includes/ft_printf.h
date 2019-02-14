/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 11:49:24 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/14 13:50:22 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

int			g_print_symbols;

struct
{
	char	flags[5];
	int		width;
	int		precision;
	char	length;
	char	specifier;
}			s_data;

int			ft_printf(const char *format, ...);
int			ft_len_nbr(int d);

void		print_octal(__int128 o);
void		ft_printf_put_char(char c);
void		print_digits(__int128 d);
void		print_pointer(void *ptr);
void		print_string(char *s);
void		print_char(int c);
void		result_preparation(va_list ap);
void		main_function(const char **format, va_list ap);
void		parse_format_specifiers(const char **format);
void		parse_flags(const char **format);
void		print_s_data(void); //debug function

#endif
