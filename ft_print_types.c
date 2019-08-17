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

	// arg = va_arg(argptr, long long);
	// printf("\n >>> %lld <<< \n", arg);
	// printf("\n");
	// print_binary((*t_flags).flags);
	check_modifier(argptr, &arg, t_flags);
	len = number_of_digits(arg);
	(*t_flags).total_chars_printed = (*t_flags).total_chars_printed + len;
	if ((((*t_flags).flags & FLAG_MINUS) > 0) && \
	(((*t_flags).flags & FLAG_NEGAT) == 0))
	{
		ft_putnbr_int(arg);
		print_sign(t_flags);
		print_padding(t_flags, len);
	}
	else if ((((*t_flags).flags & FLAG_MINUS) > 0) && \
	(((*t_flags).flags & FLAG_NEGAT) > 0))
	{
		print_sign(t_flags);
		ft_putnbr_int(arg);
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
		ft_putnbr_int(arg);
	}
}

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

void					print_flagzero_on(t_format *t_flags, int len)
{
	print_sign(t_flags);
	print_padding(t_flags, len);
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

void					print_hex(va_list argptr, t_format *t_flags)
{
	unsigned long long	arg;
	int					len;

	arg = va_arg(argptr, long long);
	// printf("\n number  = %lld \n", arg);
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

void					print_string(va_list argptr, t_format *t_flags)
{
	char				*arg;
	int					len;

	arg = va_arg(argptr, char *);
	len = ft_strlen(arg);
	(*t_flags).total_chars_printed = (*t_flags).total_chars_printed + len;
	ft_putstr(arg);
}

void					print_character(va_list argptr, t_format *t_flags)
{
	char				arg;
	int					len;

	arg = (char)va_arg(argptr, int);
	len = 1;
	(*t_flags).total_chars_printed++;
	if (((*t_flags).flags & FLAG_MINUS) > 0)
	{
		ft_putchar(arg);
		print_sign(t_flags);
		print_padding(t_flags, len);
	}
	else
	{
		print_sign(t_flags);
		print_padding(t_flags, len);
		ft_putchar(arg);
	}
}

/*
** If there is an asterisk then we have to retrieve the minimum width
** from the argument list so we call va_arg
*/

void					print_arg(va_list argptr, t_format *t_flags)
{
	if (((*t_flags).flags & FLAG_ASTER) > 0)
		(*t_flags).minfw = va_arg(argptr, int);
	if (((*t_flags).argtype == 'd') || ((*t_flags).argtype == 'i'))
		print_integer(argptr, t_flags);
	if ((*t_flags).argtype == 's')
		print_string(argptr, t_flags);
	if ((*t_flags).argtype == 'c')
		print_character(argptr, t_flags);
	if ((*t_flags).argtype == 'o')
		print_octal(argptr, t_flags);
	if (((*t_flags).argtype == 'x') || ((*t_flags).argtype == 'X') || \
	((*t_flags).argtype == 'p'))
		print_hex(argptr, t_flags);
	if ((*t_flags).argtype == 'u')
		print_int_unsigned(argptr, t_flags);
}
