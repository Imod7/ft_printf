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

void					check_ht(t_format *t_flags, unsigned long long arg)
{
	if (((*t_flags).flags & FLAG_HT) > 0)
	{
		ft_putchar('0');
		(*t_flags).special_chars_printed++;
		(*t_flags).total_chars_printed++;
	}
	ft_putnbr_octal(arg);
}

void					print_octal(va_list argptr, t_format *t_flags)
{
	unsigned long long	arg;
	int					len;

	// printf("\n OCTALS \n");
	arg = va_arg(argptr, long long);
	check_modif_un(&arg, t_flags);
	len = number_of_digits_un(arg, *t_flags);
	(*t_flags).total_chars_printed = (*t_flags).total_chars_printed + len;
	if (((*t_flags).flags & FLAG_MINUS) > 0)
	{
		check_ht(t_flags, arg);
		print_sign(t_flags);
		print_padding(t_flags, len);
	}
	else
	{
		if (((*t_flags).flags & FLAG_ZERO) > 0)
		{
			print_sign(t_flags);
			print_padding(t_flags, len);
		}
		else
		{
			print_padding(t_flags, len);
			print_sign(t_flags);
		}
		check_ht(t_flags, arg);
	}
}

/*
** In function print_hex_ch we increase only the member total_chars_printed
** but not the member special_chars_printed
** Then we print the argument in hexadecimal form
** The member special_chars_printed we need to increase it for the padding
**
*/

void					print_hex_ch(unsigned long long *arg, t_format *t_flags)
{
	if (((*t_flags).flags & FLAG_HT) > 0)
	{
		write(1, "0x", 2);
		(*t_flags).total_chars_printed = (*t_flags).total_chars_printed + 2;
		(*t_flags).special_chars_printed = (*t_flags).special_chars_printed + 2;
	}
	if ((*t_flags).argtype == 'p')
	{
		write(1, "0x", 2);
		(*t_flags).total_chars_printed = (*t_flags).total_chars_printed + 2;
	}
	if ((*t_flags).argtype == 'X')
		ft_putnbr_hex_capit(*arg);
	else
		ft_putnbr_hex(*arg);
}

void					print_flagzero_on(t_format *t_flags, int len)
{
	print_sign(t_flags);
	print_padding(t_flags, len);
}

void					print_hex(va_list argptr, t_format *t_flags)
{
	unsigned long long	arg;
	int					len;

	arg = va_arg(argptr, long long);
	// printf("\n number  = %lld \n", arg);
	(*t_flags).flags &= ~FLAG_PLUS;
	check_modif_un(&arg, t_flags);
	len = number_of_digits_un(arg, *t_flags);
	if ((*t_flags).argtype == 'p')
		(*t_flags).special_chars_printed = (*t_flags).special_chars_printed + 2;
	// printf("\n number of digits = %d \n", len);
	(*t_flags).total_chars_printed = (*t_flags).total_chars_printed + len;
	if (((*t_flags).flags & FLAG_MINUS) > 0)
	{
		print_hex_ch(&arg, t_flags);
		print_sign(t_flags);
		print_padding(t_flags, len);
	}
	else
	{
		if (((*t_flags).flags & FLAG_ZERO) > 0)
			print_flagzero_on(t_flags, len);
		else
		{
			print_padding(t_flags, len);
			print_sign(t_flags);
		}
		print_hex_ch(&arg, t_flags);
	}
}
