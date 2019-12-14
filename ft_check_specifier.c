/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_specifier.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/13 13:49:53 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/10/13 13:49:55 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		asterisk_precision(va_list argptr, t_format *t_flags)
{
	int		aster_arg;

	aster_arg = va_arg(argptr, int);
	if (aster_arg < 0)
	{
		t_flags->precision = aster_arg;
	}
	else if ((t_flags->flags & FLAG_PRECIS) &&
	(t_flags->precision == 0))
		t_flags->precision = aster_arg;
}

void		check_asterisks(va_list argptr, t_format *t_flags)
{
	int		aster_arg;

	if (t_flags->flags & FLAG_ASTER_MINFW)
	{
		aster_arg = va_arg(argptr, int);
		if (t_flags->minfw == 0)
		{
			if (aster_arg < 0)
			{
				aster_arg = aster_arg * (-1);
				t_flags->flags |= FLAG_MINUS;
			}
			t_flags->minfw = aster_arg;
		}
	}
	if (t_flags->flags & FLAG_ASTER_PREC)
		asterisk_precision(argptr, t_flags);
}

/*
** If there is an asterisk then we have to retrieve the minimum width/precision
** from the argument list with va_arg
*/

void		print_arg(va_list argptr, t_format *t_flags, t_print *t_prnt)
{
	check_asterisks(argptr, t_flags);
	if ((t_flags->argtype == 'd') || (t_flags->argtype == 'i'))
	{
		// printf(ANSI_COLOR_MAGENTA"\nNEXT NUMBER\n"ANSI_COLOR_RESET);
		print_integer(argptr, t_flags, t_prnt);
	}
	else if (t_flags->argtype == 's')
		print_string(argptr, t_flags, t_prnt);
	else if (t_flags->argtype == 'c')
		print_char(argptr, t_flags, t_prnt);
	else if ((t_flags->argtype == 'x') || (t_flags->argtype == 'X') || \
	(t_flags->argtype == 'p') || (t_flags->argtype == 'o'))
	{
		printf(ANSI_COLOR_MAGENTA"\nNEXT NUMBER flags=%d\n"ANSI_COLOR_RESET, t_flags->flags);
		print_hexoctal(argptr, t_flags, t_prnt);
	}
	else if (t_flags->argtype == 'u')
	{
		// printf(ANSI_COLOR_MAGENTA"\nNEXT NUMBER\n"ANSI_COLOR_RESET);
		print_int_unsigned(argptr, t_flags, t_prnt);
	}
	else if (t_flags->argtype == 'f')
	{
		// printf(ANSI_COLOR_MAGENTA"NEXT NUMBER\n"ANSI_COLOR_RESET);
		print_float(argptr, t_flags, t_prnt);
	}
	else if (t_flags->argtype == 'b')
		print_integer(argptr, t_flags, t_prnt);
	else if (t_flags->argtype == 'B')
		print_int_unsigned(argptr, t_flags, t_prnt);
	else if (t_flags->argtype == 'm')
		print_memory(argptr, t_prnt);
	else
		print_other(t_flags->argtype, t_flags, t_prnt);
}
