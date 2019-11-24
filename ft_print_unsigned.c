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

#include "includes/ft_printf.h"

unsigned long long		check_pointer(va_list arg, t_format *t_flags)
{
	unsigned long long	argum;

	if (t_flags->argtype == 'p')
	{
		t_flags->flags |= FLAG_HT;
		argum = va_arg(arg, unsigned long);
		t_flags->special_chars_printed = t_flags->special_chars_printed + 2;
	}
	else
	{
		argum = va_arg(arg, unsigned long long);
		check_modif_un(&argum, t_flags);
	}
	return (argum);
}

void					print_hexoctal(va_list arg, t_format *t_flags, \
										t_print *t_prnt)
{
	unsigned long long	argum;
	int					len;

	argum = check_pointer(arg, t_flags);
	len = number_of_digits_un(argum, *t_flags);
	minfw_vs_precision(t_flags, t_prnt, len);
	if (argum == 0)
		check_arg_zero(t_flags, &len, t_prnt);
	check_plusflag(t_flags);
	t_flags->flags &= ~FLAG_PLUS;
	t_flags->flags &= ~FLAG_SPACE;
	if ((t_flags->flags & FLAG_MINUS) > 0)
	{
		t_flags->flags &= ~FLAG_ZERO;
		unsigned_hashtag(argum, t_flags, t_prnt, len);
		unsigned_minus(argum, t_flags, t_prnt, len);
	}
	else if ((t_flags->flags & FLAG_ZERO) ||
	(t_flags->precision > t_flags->minfw))
	{
		unsigned_hashtag(argum, t_flags, t_prnt, len);
		print_inverse(t_flags, t_prnt, len);
		print_number(argum, t_flags, t_prnt, len);
	}
	else if (((t_flags->flags & FLAG_MINUS) == 0) && \
	((t_flags->flags & FLAG_ZERO) == 0))
	{
		print_order(t_flags, t_prnt, len);
		unsigned_hashtag(argum, t_flags, t_prnt, len);
		print_number(argum, t_flags, t_prnt, len);
	}
}

void					print_int_un(va_list argp, t_format *t_flags, \
									t_print *t_prnt)
{
	unsigned long long	arg;
	int					len;

	arg = va_arg(argp, unsigned long long);
	check_modif_un(&arg, t_flags);
	if (t_flags->argtype == 'B')
		len = binary_length_unsigned_int(arg);
	else
		len = number_of_digits_un(arg, *t_flags);
	minfw_vs_precision(t_flags, t_prnt, len);
	check_plusflag(t_flags);
	if (arg == 0)
		check_arg_zero(t_flags, &len, t_prnt);
	if (((t_flags->flags & FLAG_MINUS) > 0) && \
	(t_flags->minfw > t_flags->precision))
	{
		t_flags->flags &= ~FLAG_ZERO;
		print_number(arg, t_flags, t_prnt, len);
		print_inverse(t_flags, t_prnt, len);
	}
	else
	{
		if (((t_flags->flags & FLAG_ZERO) > 0) || \
		((t_flags->flags & FLAG_PRECIS) > 0))
			print_inverse(t_flags, t_prnt, len);
		else
			print_order(t_flags, t_prnt, len);
		print_number(arg, t_flags, t_prnt, len);
	}
	if (t_flags->argtype == 'B')
		binary_number_unsigned_int(arg, t_prnt);
}
