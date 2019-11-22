/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_number.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/17 18:17:39 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/10/17 18:17:41 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	print_hex_pointer(unsigned long long arg, t_format *t_flags, \
						t_print *t_prnt)
{
	if ((arg != 0) || \
	((arg == 0) && (t_flags->flags == 0) && t_flags->minfw == 0) ||
	((arg == 0) && ((t_flags->flags & FLAG_HT) > 0) &&
	((t_flags->flags & FLAG_PRECIS) == 0)) ||
	((arg == 0) && ((t_flags->flags & FLAG_HT) > 0) &&
	(t_flags->precision == t_flags->minfw) &&
	(t_flags->precision != 0)) ||
	((arg == 0) && ((t_flags->flags & FLAG_MINUS) > 0) &&
	((t_flags->flags & FLAG_PRECIS) == 0)))
	{
		// t_flags->total_chars_printed += len;
		if (t_flags->argtype == 'X')
			ft_putnbr_hex_capit(arg, t_flags, t_prnt);
		if ((t_flags->argtype == 'x') || \
		(t_flags->argtype == 'p'))
		{
			if (t_flags->argtype != 'B')
				ft_putnbr_hex(arg, t_flags, t_prnt);
		}
	}
}

void	print_number(unsigned long long arg, t_format *t_flags, \
					t_print *t_prnt, int len)
{
	if ((arg != 0) &&
	(t_flags->precision > len) &&
	(t_flags->precision <= t_flags->minfw))
		length_precision_diff(t_flags, t_prnt, len);
	if (t_flags->argtype == 'u')
	{
		if ((arg != 0) || \
		((arg == 0) && (!(t_flags->flags & FLAG_PRECIS)) &&
		(((t_flags->flags & FLAG_MINUS)))) ||
		((arg == 0) && (t_flags->minfw == 0) && (t_flags->flags == 0)))
		{
			// t_flags->total_chars_printed += len;
			if (t_flags->argtype != 'B')
				ft_putnbr_un_int(arg, t_flags, t_prnt);
		}
	}
	else if (t_flags->argtype == 'o')
	{
		if ((arg != 0) || \
		((arg == 0) && (t_flags->flags & FLAG_HT) &&
		(t_flags->precision <= t_flags->minfw)) ||
		((arg == 0) && (!(t_flags->flags & FLAG_PRECIS)) &&
		(((t_flags->flags & FLAG_MINUS)))) ||
		((arg == 0) && (t_flags->minfw == 0) && (t_flags->flags == 0)))
		{
			// t_flags->total_chars_printed += len;
			if (t_flags->argtype != 'B')
				ft_putnbr_octal(arg, t_flags, t_prnt);
		}
	}
	else
		print_hex_pointer(arg, t_flags, t_prnt);
	if (arg == 0)
		length_precision_diff_zeros(t_flags, t_prnt, len);
}

void	print_number_int(long long arg, t_format *t_flags, t_print *tpr, \
						int len)
{
	if ((arg != 0) || \
	((arg == 0) && (!(t_flags->flags & FLAG_PRECIS))) ||
	((arg == 0) && (t_flags->flags == 0)))
	{
		// t_flags->total_chars_printed += len;
		if ((t_flags->precision > len) && (t_flags->precision < t_flags->minfw))
			length_precision_diff(t_flags, tpr, len);
		if (t_flags->argtype != 'b')
			ft_putnbr_int(arg, t_flags, tpr);
	}
	else if ((t_flags->precision > len) && (arg == 0))
		length_precision_diff_zeros(t_flags, tpr, len);
}
