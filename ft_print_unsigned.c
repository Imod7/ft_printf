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

void					print_order(t_format *t_flags, int len)
{
	print_padding(t_flags, len);
	print_sign(t_flags);
}

void					print_inverse(t_format *t_flags, int len)
{
	print_sign(t_flags);
	print_padding(t_flags, len);
}

void					check_ht(t_format *t_flags)
{
	char				c;

	if (((*t_flags).flags & FLAG_HT) > 0)
	{
		c = '0';
		write((*t_flags).fd, &c, 1);
		(*t_flags).special_chars_printed++;
		(*t_flags).total_chars_printed++;
	}
}

void					print_octal(va_list argptr, t_format *t_flags)
{
	unsigned long long	arg;
	int					len;

	arg = va_arg(argptr, unsigned long long);
	check_modif_un(&arg, t_flags);
	len = number_of_digits_un(arg, *t_flags);
	(*t_flags).total_chars_printed = (*t_flags).total_chars_printed + len;
	if ((*t_flags).minfw < (*t_flags).precision)
		(*t_flags).minfw = (*t_flags).precision;
	if (((*t_flags).flags & FLAG_MINUS) > 0)
	{
		(*t_flags).flags &= ~FLAG_ZERO;
		check_ht(t_flags);
		print_inverse(t_flags, len);
		ft_putnbr_octal(arg, (*t_flags).fd);
	}
	else if (((*t_flags).flags & FLAG_ZERO) > 0)
	{
		// print_hex_ch(&arg, t_flags);
		print_inverse(t_flags, len);
		ft_putnbr_octal(arg, (*t_flags).fd);
	}
	else if ((((*t_flags).flags & FLAG_MINUS) == 0) && \
	(((*t_flags).flags & FLAG_ZERO) == 0))
	{
		print_order(t_flags, len);
		// print_hex_ch(&arg, t_flags);
		ft_putnbr_octal(arg, (*t_flags).fd);
	}
}

/*
** In function print_hex_ch we increase only the member total_chars_printed
** but not the member special_chars_printed
** Then we print the argument in hexadecimal form
** The member special_chars_printed we need to increase it for the padding
*/

void					print_hex_ch(unsigned long long *arg, t_format *t_flags)
{
	if ((((*t_flags).flags & FLAG_HT) > 0) && (*arg != 0))
	{
		if (((*t_flags).argtype == 'x') || ((*t_flags).argtype == 'p'))
			write((*t_flags).fd, "0x", 2);
		else
			write((*t_flags).fd, "0X", 2);
		(*t_flags).total_chars_printed = (*t_flags).total_chars_printed + 2;
		// (*t_flags).special_chars_printed = (*t_flags).special_chars_printed + 2;
	}
	// if ((*t_flags).argtype == 'p')
	// {
	// 	write((*t_flags).fd, "0x", 2);
	// 	(*t_flags).total_chars_printed = (*t_flags).total_chars_printed + 2;
	// }
	// if ((*t_flags).argtype == 'X')
	// 	ft_putnbr_hex_capit(*arg, (*t_flags).fd);
	// else
	// 	ft_putnbr_hex(*arg, (*t_flags).fd);
}

void					print_hex_nbr(unsigned long long *arg, t_format *t_flags)
{
	if ((*t_flags).argtype == 'X')
		ft_putnbr_hex_capit(*arg, (*t_flags).fd);
	else
		ft_putnbr_hex(*arg, (*t_flags).fd);
}

void					print_hex(va_list argptr, t_format *t_flags)
{
	// in hex should i extract unsigned long long? or long long?
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
	(*t_flags).flags &= ~FLAG_PLUS;
	// if (arg < 0)
	// {
	// 	arg = (arg * (-1));
		// printf(ANSI_COLOR_YELLOW"\nargument extracted = %lld"ANSI_COLOR_RESET, arg);
	// 	print_binary(arg);
	// 	arg = invert_allbits(arg);
	// 	arg = binary_addone(arg);
	// 	print_binary(arg);
	// }
	len = number_of_digits_un(arg, *t_flags);
	(*t_flags).total_chars_printed = (*t_flags).total_chars_printed + len;
	if (((*t_flags).flags & FLAG_MINUS) > 0)
	{
		(*t_flags).flags &= ~FLAG_ZERO;
		print_hex_ch(&arg, t_flags);
		print_hex_nbr(&arg, t_flags);
		print_inverse(t_flags, len);
	}
	else if (((*t_flags).flags & FLAG_ZERO) > 0)
	{
		print_hex_ch(&arg, t_flags);
		print_inverse(t_flags, len);
		print_hex_nbr(&arg, t_flags);
	}
	else if ((((*t_flags).flags & FLAG_MINUS) == 0) && \
	(((*t_flags).flags & FLAG_ZERO) == 0))
	{
		print_order(t_flags, len);
		print_hex_ch(&arg, t_flags);
		print_hex_nbr(&arg, t_flags);
	}
}
