/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 11:49:24 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/18 11:33:50 by blukasho         ###   ########.fr       */
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
int			ft_len_nbr(__int128 d);
int			srcrpl(char *s, char a, char b);

void		print_double(va_list ap);
void		print_hexdecimal(va_list ap);
void		print_hex(__int128 h);
void		print_all_digits(__int128 d);
void		print_unsigned_digits(va_list ap);
void		print_hesh(void);
void		print_octal(va_list ap);
void		ft_printf_put_str(char *s);
void		ft_printf_put_char(char c);
void		print_digits(va_list ap);
void		print_pointer(void *ptr);
void		print_string(char *s);
void		print_char(int c);
void		result_preparation(va_list ap);
void		main_function(const char **format, va_list ap);
void		parse_format_specifiers(const char **format);
void		parse_flags(const char **format);
void		print_s_data(void); //debug function

#endif
