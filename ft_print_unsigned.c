/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_unsigned.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 17:43:33 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/08/19 17:43:37 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					minus_flag(unsigned long long ar, t_format *t_fl, int l)
{
	if ((((*t_fl).argtype == 'o') > 0) && \
	(((*t_fl).flags & FLAG_HT) > 0))
	{
		(*t_fl).special_chars_printed++;
	}
	if (((*t_fl).flags & FLAG_PRECIS) > 0)
	{
		print_number(ar, t_fl, l);
		print_inverse(t_fl, l);
	}
	else if ((((*t_fl).flags & FLAG_NEGAT) == 0) && \
	(((*t_fl).flags & FLAG_SPACE) == 0) && \
	(((*t_fl).flags & FLAG_PRECIS) == 0))
	{
		print_number(ar, t_fl, l);
		print_inverse(t_fl, l);
	}
	else if ((((*t_fl).flags & FLAG_NEGAT) > 0) && \
	(((*t_fl).flags & FLAG_SPACE) > 0))
	{
		(*t_fl).flags &= ~FLAG_SPACE;
		print_sign(t_fl);
		print_number(ar, t_fl, l);
		print_padding(t_fl, l);
	}
	else
	{
		print_inverse(t_fl, l);
		print_number(ar, t_fl, l);
	}
}

void					check_ht(unsigned long long arg, t_format *t_flags)
{
	char				c;

	if ((((*t_flags).argtype == 'o') > 0) && \
	((arg != 0) && (((*t_flags).flags & FLAG_HT) > 0)))
	{
		c = '0';
		write((*t_flags).fd, &c, 1);
		(*t_flags).total_chars_printed++;
	}
	else if ((((*t_flags).flags & FLAG_HT) > 0) && (arg != 0) && \
	((*t_flags).argtype != 'o'))
	{
		if (((*t_flags).argtype == 'x') || ((*t_flags).argtype == 'p'))
			write((*t_flags).fd, "0x", 2);
		else
			write((*t_flags).fd, "0X", 2);
		(*t_flags).total_chars_printed = (*t_flags).total_chars_printed + 2;
	}
}

void					print_hex_octal(va_list argptr, t_format *t_flags)
{
	unsigned long long	arg;
	int					len;

	if ((*t_flags).argtype == 'p')
	{
		(*t_flags).flags |= FLAG_HT;
		arg = va_arg(argptr, unsigned long);
		(*t_flags).special_chars_printed = (*t_flags).special_chars_printed + 2;
	}
	else
	{
		arg = va_arg(argptr, unsigned long long);
		check_modif_un(&arg, t_flags);
	}
	len = number_of_digits_un(arg, *t_flags);
	if (arg == 0)
		check_arg_zero(t_flags, &len);
	minfw_vs_precision(t_flags);
	if (len < (*t_flags).precision)
		length_precision_diff(t_flags, len);
	check_plusflag(t_flags);
	(*t_flags).flags &= ~FLAG_PLUS;
	(*t_flags).flags &= ~FLAG_SPACE;
	if ((*t_flags).minfw < (*t_flags).precision)
		(*t_flags).minfw = (*t_flags).precision;
	if (((*t_flags).flags & FLAG_MINUS) > 0)
	{
		(*t_flags).flags &= ~FLAG_ZERO;
		check_ht(arg, t_flags);
		minus_flag(arg, t_flags, len);
	}
	else if (((*t_flags).flags & FLAG_ZERO) > 0)
	{
		check_ht(arg, t_flags);
		print_inverse(t_flags, len);
		print_number(arg, t_flags, len);
	}
	else if ((((*t_flags).flags & FLAG_MINUS) == 0) && \
	(((*t_flags).flags & FLAG_ZERO) == 0))
	{
		print_order(t_flags, len);
		check_ht(arg, t_flags);
		print_number(arg, t_flags, len);
	}
}

void					print_int_unsigned(va_list argptr, t_format *t_flags)
{
	unsigned long long	arg;
	int					len;

	arg = va_arg(argptr, unsigned long long);
	minfw_vs_precision(t_flags);
	check_modif_un(&arg, t_flags);
	len = number_of_digits_un(arg, *t_flags);
	check_plusflag(t_flags);
	if ((*t_flags).minfw < (*t_flags).precision)
		(*t_flags).minfw = (*t_flags).precision;
	if (((*t_flags).flags & FLAG_MINUS) > 0)
	{
		print_number(arg, t_flags, len);
		print_inverse(t_flags, len);
	}
	else
	{
		if ((((*t_flags).flags & FLAG_ZERO) > 0) || \
		(((*t_flags).flags & FLAG_PRECIS) > 0))
			print_inverse(t_flags, len);
		else
		{
			print_padding(t_flags, len);
			print_sign(t_flags);
		}
		print_number(arg, t_flags, len);
	}
}
