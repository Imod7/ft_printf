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

void		check_asterisks(va_list argptr, t_format *t_flags)
{
	int		aster_arg;

	if (((*t_flags).flags & FLAG_ASTER) && ((*t_flags).flags & FLAG_ASTER_2))
	{
		aster_arg = va_arg(argptr, int);
		if (aster_arg < 0)
		{
			aster_arg = aster_arg * (-1);
			(*t_flags).flags |= FLAG_MINUS;
		}
		(*t_flags).minfw = aster_arg;
		aster_arg = va_arg(argptr, int);
		(*t_flags).precision = aster_arg;
	}
	else if (((*t_flags).flags & FLAG_ASTER) && \
	(!((*t_flags).flags & FLAG_ASTER_2)))
	{
		aster_arg = va_arg(argptr, int);
		if (aster_arg < 0)
		{
			aster_arg = aster_arg * (-1);
			(*t_flags).flags |= FLAG_MINUS;
		}
		if (((*t_flags).flags & FLAG_PRECIS) &&
		((*t_flags).precision == 0))
			(*t_flags).precision = aster_arg;
		else if (aster_arg > (*t_flags).precision)
			(*t_flags).minfw = aster_arg;
	}
}

/*
** If there is an asterisk then we have to retrieve the minimum width/precision
** from the argument list with va_arg
*/

void		print_arg(va_list argptr, t_format *t_flags, t_print *t_prnt)
{
	check_asterisks(argptr, t_flags);
	if (((*t_flags).argtype == 'd') || ((*t_flags).argtype == 'i'))
		print_integer(argptr, t_flags, t_prnt);
	else if ((*t_flags).argtype == 's')
		print_string(argptr, t_flags, t_prnt);
	else if ((*t_flags).argtype == 'c')
		print_char(argptr, t_flags, t_prnt);
	else if (((*t_flags).argtype == 'x') || ((*t_flags).argtype == 'X') || \
	((*t_flags).argtype == 'p') || ((*t_flags).argtype == 'o'))
		print_hexoctal(argptr, t_flags, t_prnt);
	else if ((*t_flags).argtype == 'u')
		print_int_un(argptr, t_flags, t_prnt);
	else if ((*t_flags).argtype == 'f')
		print_float(argptr, t_flags, t_prnt);
	else
		print_other((*t_flags).argtype, t_flags, t_prnt);
}
