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

int			number_of_digits(long long num)
{
	size_t	digits;
	size_t	base;

	digits = 0;
	base = 10;
	if (num == 0)
		digits++;
	else if (num < 0)
	{
		if (num < -9223372036854775807)
			num = 9223372036854775807;
		else
			num = num * (-1);
	}
	while (num > 0)
	{
		num = num / base;
		digits++;
	}
	return (digits);
}

int			number_of_digits_un(unsigned long long num, t_format t_flags)
{
	size_t	digits;
	size_t	base;

	digits = 0;
	base = 10;
	if (t_flags.argtype == 'o')
		base = 8;
	else if ((t_flags.argtype == 'x') || (t_flags.argtype == 'X') || \
	(t_flags.argtype == 'p'))
		base = 16;
	else
		base = 10;
	if (num == 0)
		digits++;
	else
	{
		while (num > 0)
		{
			num = num / base;
			digits++;
		}
	}
	return (digits);
}

/*
** If FLAG_PLUS or FLAG_NEGAT is set AND FLAG_ZERO is not set
** then we need to increase the special_chars_printed
*/

void		print_padding(t_format *t_flags, t_print *t_pr, int arg_digits_len)
{
	int		i;
	int		c;

	if (((*t_pr).sign_printed == 0) &&
	(((*t_flags).flags & (FLAG_PLUS)) ||
	((*t_flags).flags & (FLAG_MINUS)) ||
	((*t_flags).flags & (FLAG_NEGAT))))
	{
		// printf("\nSign is not printed yet\n");
		(*t_flags).special_chars_printed += 1;
	}
	// if ((((*t_flags).flags & FLAG_HT) > 0) && (((*t_flags).argtype == 'x') || \
	// ((*t_flags).argtype == 'X')))
	// {
	// 	// printf(ANSI_COLOR_CYAN"\nHT=yes + hexad \n");
	// 	(*t_flags).special_chars_printed += 2;
	// }
	if (!((*t_pr).pad_len))
	{
		// printf(ANSI_COLOR_YELLOW" >> pad_len IS NOT SET = %d\n", (*t_pr).pad_len);
		(*t_pr).pad_len = (*t_flags).minfw - \
		(*t_flags).special_chars_printed - arg_digits_len;
	}
	if (!((*t_pr).diff))
		(*t_pr).diff = ((*t_pr).pad_len - (*t_flags).precision) + \
		arg_digits_len + (*t_flags).special_chars_printed;
	if (((*t_pr).diff) && ((*t_pr).sign_printed == 1) && \
	((*t_flags).precision >= (*t_flags).minfw))
		(*t_pr).diff -= 1;
	// printf(ANSI_COLOR_GREEN"\n===PADDING===\nargtype = %c\n", \
	// (*t_flags).argtype);
	// printf("minfw = %d\nspecial_chars = %d\narg_digits_len = %d", \
	// (*t_flags).minfw, (*t_flags).special_chars_printed, arg_digits_len);
	// printf("\nprecision = %d\npad_len = %d\n", (*t_flags).precision, \
	// (*t_pr).pad_len);
	// printf("diff = %d\n", (*t_pr).diff);
	i = 0;
	while (i < (*t_pr).pad_len)
	{
		if ((*t_flags).flags & FLAG_ZERO)
			c = '0';
		else
			c = ' ';
		if (((*t_flags).flags & FLAG_PRECIS) && ((*t_flags).argtype != 's') &&
		((*t_flags).argtype != 'c') && (i >= (*t_pr).diff) && ((*t_pr).diff >= 0))
		// (((*t_flags).flags & FLAG_MINUS) == 0) &&
		// (((*t_flags).flags & FLAG_PLUS) == 0))
			c = '0';
		write((*t_flags).fd, &c, 1);
		(*t_flags).total_chars_printed++;
		i++;
	}
	// printf("\n>>total = %d\n", (*t_flags).total_chars_printed);
}

void		print_sign(t_format *t_flags, t_print *t_prnt)
{
	if (((*t_flags).flags & FLAG_NEGAT) > 0)
	{
		(*t_flags).flags &= ~FLAG_SPACE;
		(*t_flags).flags &= ~FLAG_PLUS;
		write((*t_flags).fd, &"-", 1);
		(*t_flags).total_chars_printed++;
		(*t_flags).special_chars_printed++;
	}
	if (((*t_flags).flags & FLAG_PLUS) > 0)
	{
		write((*t_flags).fd, &"+", 1);
		(*t_flags).special_chars_printed++;
		(*t_flags).total_chars_printed++;
	}
	if (((*t_flags).flags & FLAG_SPACE) && (!(*t_prnt).pad_len))
	{
		write((*t_flags).fd, &" ", 1);
		(*t_flags).special_chars_printed++;
		(*t_flags).total_chars_printed++;
	}
	(*t_prnt).sign_printed = 1;
}

void		check_negative_num(long long *arg, t_format *t_flags, t_print *t_prnt, int l)
{
	if (*arg < 0)
		(*t_flags).flags |= FLAG_NEGAT;
	if ((*arg < 0) && ((*t_flags).minfw == (*t_flags).precision))
		(*t_prnt).pad_len = (*t_flags).minfw - l;
}

void		check_modifier(long long *arg, t_format *t_flags)
{
	if ((*t_flags).modifier == N)
		*arg = (int)(*arg);
	else if ((*t_flags).modifier == H)
		*arg = (short)(*arg);
	else if ((*t_flags).modifier == HH)
		*arg = (signed char)(*arg);
	else if ((*t_flags).modifier == L)
		*arg = (long)(*arg);
	else if ((*t_flags).modifier == LL)
		*arg = (long long)(*arg);
}

void		check_modif_un(unsigned long long *arg, t_format *t_flags)
{
	if ((*t_flags).modifier == H)
		*arg = (unsigned short)(*arg);
	else if ((*t_flags).modifier == HH)
		*arg = (unsigned char)(*arg);
	else if ((*t_flags).modifier == L)
		*arg = (unsigned long)(*arg);
	else if ((*t_flags).modifier == LL)
		*arg = (unsigned long long)(*arg);
	else
		*arg = (unsigned int)(*arg);
}
