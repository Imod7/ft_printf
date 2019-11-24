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

#include "includes/ft_printf.h"

void		checks_before_padding(t_format *t_flags, t_print *t_prnt, \
								int arg_digits_len)
{
	if ((t_prnt->sign_printed == 0) &&
	((t_flags->flags & (FLAG_PLUS)) ||
	(t_flags->flags & (FLAG_MINUS)) ||
	(t_flags->flags & (FLAG_NEGAT))))
		t_flags->special_chars_printed += 1;
	if (!(t_prnt->pad_len))
	{
		t_prnt->pad_len = t_flags->minfw - \
		t_flags->special_chars_printed - arg_digits_len;
	}
	if (!(t_prnt->diff))
		t_prnt->diff = (t_prnt->pad_len - t_flags->precision) + \
		arg_digits_len + t_flags->special_chars_printed;
	if ((t_prnt->diff) && (t_prnt->sign_printed == 1) && \
	(t_flags->precision >= t_flags->minfw))
		t_prnt->diff -= 1;
}

/*
** If FLAG_PLUS or FLAG_NEGAT is set AND FLAG_ZERO is not set
** then we need to increase the special_chars_printed
*/

void		print_padding(t_format *t_flags, t_print *t_prnt, \
						int arg_digits_len)
{
	int		i;
	int		c;

	checks_before_padding(t_flags, t_prnt, arg_digits_len);
	i = 0;
	while (i < t_prnt->pad_len)
	{
		if (t_flags->flags & FLAG_ZERO)
			c = '0';
		else
			c = ' ';
		if ((t_flags->flags & FLAG_PRECIS) && (t_flags->argtype != 's') &&
		(t_flags->argtype != 'c') && (i >= t_prnt->diff) &&
		(t_prnt->diff >= 0))
			c = '0';
		t_prnt->writer(&c, 1, t_prnt);
		// t_flags->total_chars_printed++;
		i++;
	}
}

void		print_sign(t_format *t_flags, t_print *t_prnt)
{
	if ((t_flags->flags & FLAG_NEGAT) > 0)
	{
		t_flags->flags &= ~FLAG_SPACE;
		t_flags->flags &= ~FLAG_PLUS;
		t_prnt->writer(&"-", 1, t_prnt);
		// t_flags->total_chars_printed++;
		t_flags->special_chars_printed++;
	}
	if ((t_flags->flags & FLAG_PLUS) > 0)
	{
		t_prnt->writer(&"+", 1, t_prnt);
		t_flags->special_chars_printed++;
		// t_flags->total_chars_printed++;
	}
	if ((t_flags->flags & FLAG_SPACE) && ((!(t_prnt->diff)) ||
	(t_prnt->pad_len <= 0)))
	{
		t_prnt->writer(&" ", 1, t_prnt);
		t_flags->special_chars_printed++;
		// t_flags->total_chars_printed++;
	}
	t_prnt->sign_printed = 1;
}

void		check_modifier(long long *arg, t_format *t_flags)
{
	if (t_flags->modifier == N)
		*arg = (int)(*arg);
	else if (t_flags->modifier == h)
		*arg = (short)(*arg);
	else if (t_flags->modifier == hh)
		*arg = (signed char)(*arg);
	else if (t_flags->modifier == l)
		*arg = (long)(*arg);
	else if (t_flags->modifier == ll)
		*arg = (long long)(*arg);
}

void		check_modif_un(unsigned long long *arg, t_format *t_flags)
{
	if (t_flags->modifier == h)
		*arg = (unsigned short)(*arg);
	else if (t_flags->modifier == hh)
		*arg = (unsigned char)(*arg);
	else if (t_flags->modifier == l)
		*arg = (unsigned long)(*arg);
	else if (t_flags->modifier == ll)
		*arg = (unsigned long long)(*arg);
	else
		*arg = (unsigned int)(*arg);
}
