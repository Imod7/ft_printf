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

void			print_padding(t_flagstruct t_flags, int no_digits)
{
	int			i;
	int			pad_len;
	int			c;
	int			chars_printed;

	i = 0;
	chars_printed = 0;
	if ((t_flags.flags & FLAG_PLUS) > 0)
		chars_printed++;
	//printf("\n flag chars printed %d -- %d \n", t_flags.chars_printed, no_digits);
	pad_len = t_flags.minfw - chars_printed - no_digits;
	while (i < pad_len)
	{
		if (t_flags.flags & FLAG_ZERO)
			c = '0';
		else
			c = ' ';
		ft_putchar(c);
		i++;
	}
}

void			print_format(t_flagstruct t_flags)
{
	if ((t_flags.flags & FLAG_PLUS) > 0)
	{
		ft_putchar('+');
		t_flags.chars_printed++;
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

void			print_integer(va_list argptr, t_flagstruct t_flags)
{
	int			arg;
	int			len;

	arg = va_arg(argptr, int);
	len = number_of_digits(arg);
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
			// printf("why this? flags = %d", t_flags.flags);
			// print_binary(t_flags.flags);
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

void			print_string(va_list argptr)
{
	ft_putstr(va_arg(argptr, char *));
}

void			print_character(va_list argptr)
{
	ft_putchar((char)va_arg(argptr, int));
}

void			print_arg(va_list argptr, char c, t_flagstruct t_flags)
{
	if (c == 'd')
		print_integer(argptr, t_flags);
	if (c == 's')
		print_string(argptr);
	if (c == 'c')
		print_character(argptr);
}
