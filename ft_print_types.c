/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printing_functions.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/24 19:46:10 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/07/24 20:25:51 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_format(t_flagstruct t_flags)
{
	if ((t_flags.flags & FLAG_MINUS) > 0)
		ft_putchar('-');
	if ((t_flags.flags & FLAG_PLUS) > 0)
		ft_putchar('+');
}

void			print_integer(va_list argptr)
{
	ft_putnbr(va_arg(argptr, int));
}

void			print_string(va_list argptr)
{
	ft_putstr(va_arg(argptr, char *));
}

void			print_character(va_list argptr)
{
	ft_putchar((char)va_arg(argptr, int));
}

void			print_arg(va_list argptr, char c)
{
	if (c == 'd')
		print_integer(argptr);
	if (c == 's')
		print_string(argptr);
	if (c == 'c')
		print_character(argptr);
}
