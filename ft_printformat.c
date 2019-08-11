/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printformat.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/11 12:22:55 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/08/11 12:22:59 by dsaripap      ########   odam.nl         */
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
	pad_len = t_flags.minfw - chars_printed - no_digits;
	// printf("\n flag chars printed %d, no_digits = %d, padlen = %d \n", t_flags.chars_printed, no_digits, pad_len);
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
	if ((t_flags.flags & FLAG_SPACE) > 0)
	{
		ft_putchar(' ');
		t_flags.chars_printed++;
	}
}

void			print_modifier(long long *arg, t_flagstruct t_flags)
{
	if (t_flags.modifier == H)
		*arg = (short)(*arg);
	if (t_flags.modifier == HH)
		*arg = (signed char)(*arg);
	if (t_flags.modifier == L)
		*arg = (long)(*arg);
	if (t_flags.modifier == LL)
		*arg = (long long)(*arg);
}
