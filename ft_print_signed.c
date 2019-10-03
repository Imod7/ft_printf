/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_signed.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 17:48:41 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/08/19 17:48:45 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					int_otherflag(long long arg, t_format *t_flags, int len)
{
	if (((((*t_flags).flags & FLAG_ZERO) > 0) || \
	(((*t_flags).flags & FLAG_PRECIS) > 0)) && \
	(((*t_flags).flags & FLAG_PLUS) == 0))
	{
		// printf("\n1. zero + prec + not plus");
		print_sign(t_flags);
		print_padding(t_flags, len);
		print_number_int(arg, t_flags, len);
	}
	else if ((((*t_flags).flags & FLAG_PLUS) > 0) &&
	(((*t_flags).flags & FLAG_ZERO) > 0))
	{
		// printf("\n3. plus + zero\n");
		print_sign(t_flags);
		print_padding(t_flags, len);
		print_number_int(arg, t_flags, len);
	}
	else
	{
		// printf("\n4. other\n");
		print_padding(t_flags, len);
		print_sign(t_flags);
		if (len < (*t_flags).precision)
			length_precision_diff(t_flags, len);
		print_number_int(arg, t_flags, len);
	}
}

void					intwithminus(long long arg, t_format *t_flags, int len)
{
	if ((((*t_flags).flags & FLAG_PRECIS) > 0) && \
	(((*t_flags).precision) < len) && \
	(((*t_flags).flags & FLAG_NEGAT) == 0))
	{
		print_sign(t_flags);
		print_padding(t_flags, len);
		print_number_int(arg, t_flags, len);
	}
	else if ((((*t_flags).flags & FLAG_PRECIS) > 0) && \
	(((*t_flags).precision) > len) && \
	(((*t_flags).flags & FLAG_NEGAT) == 0))
	{
		print_sign(t_flags);
		if (len < (*t_flags).precision)
			length_precision_diff(t_flags, len);
		print_number_int(arg, t_flags, len);
		print_padding(t_flags, len);
	}
	else
	{
		print_sign(t_flags);
		print_number_int(arg, t_flags, len);
		print_padding(t_flags, len);
	}
}

/*
** function print_integer
** If the flag zero is SET then print first the format (plus sign)
** and then the zeros
** If flag zero is NOT SET and MINUS flag is NOT SET
** then first print the spaces and then the format
** Check Test 1, 2
*/

void					print_integer(va_list argptr, t_format *t_flags)
{
	long long			arg;
	int					len;

	arg = va_arg(argptr, long long);
	minfw_vs_precision(t_flags);
	check_plusflag(t_flags);
	check_modifier(&arg, t_flags);
	check_negative_num(&arg, t_flags);
	len = number_of_digits(arg);
	if (arg == 0)
		check_arg_zero(t_flags, &len);
	if ((*t_flags).minfw < (*t_flags).precision)
		(*t_flags).minfw = (*t_flags).precision;
	if (((*t_flags).flags & FLAG_MINUS) > 0)
	{
		(*t_flags).flags &= ~FLAG_ZERO;
		intwithminus(arg, t_flags, len);
	}
	else
		int_otherflag(arg, t_flags, len);
}

/*
** If there is an asterisk then we have to retrieve the minimum width
** from the argument list so we call va_arg
*/

void					print_arg(va_list argptr, t_format *t_flags)
{
	int					aster_arg;

	if (((*t_flags).flags & FLAG_ASTER) > 0)
	{
		aster_arg = va_arg(argptr, int);
		if (aster_arg > (*t_flags).precision)
			(*t_flags).minfw = aster_arg;
	}
	if (((*t_flags).argtype == 'd') || ((*t_flags).argtype == 'i'))
		print_integer(argptr, t_flags);
	else if ((*t_flags).argtype == 's')
		print_string(argptr, t_flags);
	else if ((*t_flags).argtype == 'c')
		print_character(argptr, t_flags);
	else if (((*t_flags).argtype == 'x') || ((*t_flags).argtype == 'X') || \
	((*t_flags).argtype == 'p') || ((*t_flags).argtype == 'o'))
		print_hex_octal(argptr, t_flags);
	else if ((*t_flags).argtype == 'u')
		print_int_unsigned(argptr, t_flags);
	else if ((*t_flags).argtype == 'f')
		print_float(argptr, t_flags);
	else
		print_other((*t_flags).argtype, t_flags);
}
