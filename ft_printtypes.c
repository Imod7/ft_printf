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

void			print_integer(va_list argptr, t_flagstruct t_flags)
{
	long long	arg;
	int			len;

	arg = va_arg(argptr, long long);
	print_modifier(&arg, t_flags);
	len = number_of_digits(arg, t_flags);
	if ((t_flags.flags & FLAG_MINUS) > 0)
	{
		ft_putnbr(arg);
		print_format(t_flags);
		print_padding(t_flags, len);
	}
	else
	{
		if ((t_flags.flags & FLAG_ZERO) > 0)
		{
			print_format(t_flags);
			print_padding(t_flags, len);
		}
		else
		{
			print_padding(t_flags, len);
			print_format(t_flags);
		}
		ft_putnbr(arg);
	}
}

void			print_octal(va_list argptr, t_flagstruct t_flags)
{
	long long	arg;
	int			len;

	arg = va_arg(argptr, long long);
	print_modifier(&arg, t_flags);
	len = number_of_digits(arg, t_flags);
	if ((t_flags.flags & FLAG_MINUS) > 0)
	{
		ft_putnbr_octal(arg);
		print_format(t_flags);
		print_padding(t_flags, len);
	}
	else
	{
		if ((t_flags.flags & FLAG_ZERO) > 0)
		{
			print_format(t_flags);
			print_padding(t_flags, len);
		}
		else
		{
			print_padding(t_flags, len);
			print_format(t_flags);
		}
		ft_putnbr_octal(arg);
	}
}

void			print_string(va_list argptr)
{
	ft_putstr(va_arg(argptr, char *));
}

void			print_character(va_list argptr, t_flagstruct t_flags)
{
	char		arg;
	int			len;

	arg = (char)va_arg(argptr, int);
	len = 1;
	if ((t_flags.flags & FLAG_MINUS) > 0)
	{
		ft_putchar(arg);
		print_format(t_flags);
		print_padding(t_flags, len);
	}
	else
	{
		print_format(t_flags);
		print_padding(t_flags, len);
		ft_putchar(arg);
	}
}

void			print_arg(va_list argptr, char c, t_flagstruct t_flags)
{
	if (c == 'd')
		print_integer(argptr, t_flags);
	if (c == 's')
		print_string(argptr);
	if (c == 'c')
		print_character(argptr, t_flags);
	if (c == 'o')
		print_octal(argptr, t_flags);
}
