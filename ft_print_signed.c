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

void					int_with_zero(long long arg, t_format *t_flags, int len)
{
	if ((((*t_flags).flags & FLAG_ZERO) > 0) || \
	(((*t_flags).flags & FLAG_PRECIS) > 0))
	{
		print_sign(t_flags);
		print_padding(t_flags, len);
	}
	else
	{
		print_padding(t_flags, len);
		print_sign(t_flags);
	}
	ft_putnbr_int(arg);
}

void					int_with_minus(long long arg, t_format *t_flags, int len)
{
	if ((((*t_flags).flags & FLAG_NEGAT) == 0) && \
	(((*t_flags).flags & FLAG_SPACE) == 0))
	{
		ft_putnbr_int(arg);
		print_sign(t_flags);
		print_padding(t_flags, len);
	}
	else if ((((*t_flags).flags & FLAG_NEGAT) > 0) && \
	(((*t_flags).flags & FLAG_SPACE) > 0))
	{
		(*t_flags).flags &= ~FLAG_SPACE;
		print_sign(t_flags);
		ft_putnbr_int(arg);
		print_padding(t_flags, len);
	}
	else
	{
		print_sign(t_flags);
		ft_putnbr_int(arg);
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
	//check_modifier(argptr, &arg, t_flags);
	check_modifier(&arg, t_flags);
	len = number_of_digits(arg);
	(*t_flags).total_chars_printed = (*t_flags).total_chars_printed + len;
	if (((*t_flags).flags & FLAG_MINUS) > 0)
		int_with_minus(arg, t_flags, len);
	else
		int_with_zero(arg, t_flags, len);
}

void					print_float(va_list argptr, t_format *t_flags)
{
	long long			intpart;
	double				decpart;
	double				wholenumber;
	int					len;
	int					hundrends;
	int					i;

	wholenumber = va_arg(argptr, double);
	intpart = (long long)wholenumber;
	check_modifier(&intpart, t_flags);
	printf("\n --- whole number = %f , intpart = %lld \n", wholenumber, intpart);
	len = number_of_digits(intpart);
	(*t_flags).total_chars_printed = (*t_flags).total_chars_printed + len;
	if (((*t_flags).flags & FLAG_MINUS) > 0)
		int_with_minus(intpart, t_flags, len);
	else
		int_with_zero(intpart, t_flags, len);
	// printf("\n BEFORE CALC : whole number = %f , intpart = %lld , decpart = \n", wholenumber, intpart);
	decpart = wholenumber - intpart;
	len = number_of_digits(decpart);
	i = 0;
	hundrends = 0;
	printf("\n len = %d \n ", len);
	while (i < len - 2)
	{
		hundrends = 10 * 10;
		i++;
	}
	decpart = decpart * hundrends;
	printf("\n AFTER CALC : whole number = %f , intpart = %lld , decpart = %f , hundrends = %d\n", wholenumber, intpart, decpart, hundrends);
	// check_modifier(argptr, &decpart, t_flags);
	// len = number_of_digits(decpart);
	// decpart = (decpart - 2) * 100 * len;
	// (*t_flags).total_chars_printed = (*t_flags).total_chars_printed + len;
	// if (((*t_flags).flags & FLAG_MINUS) > 0)
	// 	int_with_minus(decpart, t_flags, len);
	// else
	// 	int_with_zero(intpart, t_flags, len);
}

void					print_int_unsigned(va_list argptr, t_format *t_flags)
{
	unsigned long long	arg;
	int					len;

	// printf(" \n \n >> %lld <<\n \n ", va_arg(argptr, long long));
	arg = va_arg(argptr, unsigned long long);
	check_modif_un(&arg, t_flags);
	len = number_of_digits_un(arg, *t_flags);
	(*t_flags).total_chars_printed = (*t_flags).total_chars_printed + len;
	if (((*t_flags).flags & FLAG_MINUS) > 0)
	{
		ft_putnbr(arg);
		print_sign(t_flags);
		print_padding(t_flags, len);
	}
	else
	{
		if ((((*t_flags).flags & FLAG_ZERO) > 0) || \
		(((*t_flags).flags & FLAG_PRECIS) > 0))
		{
			print_sign(t_flags);
			print_padding(t_flags, len);
		}
		else
		{
			print_padding(t_flags, len);
			print_sign(t_flags);
		}
		ft_putnbr(arg);
	}
}

/*
** If there is an asterisk then we have to retrieve the minimum width
** from the argument list so we call va_arg
*/

void					print_arg(va_list argptr, t_format *t_flags)
{
	// printf(" \n the arg is %c !\n", (*t_flags).argtype);
	if (((*t_flags).flags & FLAG_ASTER) > 0)
		(*t_flags).minfw = va_arg(argptr, int);
	if (((*t_flags).argtype == 'd') || ((*t_flags).argtype == 'i'))
		print_integer(argptr, t_flags);
	else if ((*t_flags).argtype == 's')
		print_string(argptr, t_flags);
	else if ((*t_flags).argtype == 'c')
		print_character(argptr, t_flags);
	else if ((*t_flags).argtype == 'o')
	{
		// printf(" \n print octal is called !\n");
		print_octal(argptr, t_flags);
	}
	else if (((*t_flags).argtype == 'x') || ((*t_flags).argtype == 'X') || \
	((*t_flags).argtype == 'p'))
		print_hex(argptr, t_flags);
	else if ((*t_flags).argtype == 'u')
		print_int_unsigned(argptr, t_flags);
	else if ((*t_flags).argtype == 'f')
		print_float(argptr, t_flags);
	else
		print_other((*t_flags).argtype, t_flags);
}
