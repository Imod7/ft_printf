/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_other.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 17:48:09 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/08/19 17:48:14 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					print_string(va_list argptr, t_format *t_flags)
{
	char				*arg;
	int					len;

	arg = va_arg(argptr, char *);
	len = ft_strlen(arg);
	(*t_flags).total_chars_printed = (*t_flags).total_chars_printed + len;
	ft_putstr(arg);
}

void					print_character(va_list argptr, t_format *t_flags)
{
	char				arg;
	int					len;

	arg = (char)va_arg(argptr, int);
	len = 1;
	(*t_flags).total_chars_printed++;
	if (((*t_flags).flags & FLAG_MINUS) > 0)
	{
		ft_putchar(arg);
		print_sign(t_flags);
		print_padding(t_flags, len);
	}
	else
	{
		print_sign(t_flags);
		print_padding(t_flags, len);
		ft_putchar(arg);
	}
}

void					print_other(char arg, t_format *t_flags)
{
	int					len;

	len = 1;
	(*t_flags).total_chars_printed++;
	if (((*t_flags).flags & FLAG_MINUS) > 0)
	{
		ft_putchar(arg);
		print_sign(t_flags);
		print_padding(t_flags, len);
	}
	else
	{
		print_sign(t_flags);
		print_padding(t_flags, len);
		ft_putchar(arg);
	}
}
