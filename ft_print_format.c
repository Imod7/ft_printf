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

/*
** If FLAG_PLUS or FLAG_NEGAT is set AND FLAG_ZERO is not set
** then we need to increase the special_chars_printed
*/

void		print_padding(t_format *t_flags, t_print *t_pr, int arg_digits_len)
{
	int		i;
	int		c;

	// printf("START diff = %d\n", (*t_pr).diff);
	if (((*t_pr).sign_printed == 0) &&
	(((*t_flags).flags & (FLAG_PLUS)) ||
	((*t_flags).flags & (FLAG_MINUS)) ||
	((*t_flags).flags & (FLAG_NEGAT))))
		(*t_flags).special_chars_printed += 1;
	if (!((*t_pr).pad_len))
	{
		(*t_pr).pad_len = (*t_flags).minfw - \
		(*t_flags).special_chars_printed - arg_digits_len;
	}
	if (!((*t_pr).diff))
		(*t_pr).diff = ((*t_pr).pad_len - (*t_flags).precision) + \
		arg_digits_len + (*t_flags).special_chars_printed;
	// printf("MIDDLE diff = %d\n", (*t_pr).diff);
	if (((*t_pr).diff) && ((*t_pr).sign_printed == 1) && \
	((*t_flags).precision >= (*t_flags).minfw))
		(*t_pr).diff -= 1;
	// printf("END diff = %d\n", (*t_pr).diff);
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
		((*t_flags).argtype != 'c') && (i >= (*t_pr).diff) &&
		((*t_pr).diff >= 0))
			c = '0';
		// write((*t_flags).fd, &c, 1);
		buffer_writer(&c, 1, t_flags, t_pr);
		(*t_flags).total_chars_printed++;
		i++;
	}
}

void		print_sign(t_format *t_flags, t_print *t_prnt)
{
	// printf("\n diff = %d", (*t_prnt).diff);
	// printf("\n pad = %d", (*t_prnt).pad_len);
	if (((*t_flags).flags & FLAG_NEGAT) > 0)
	{
		(*t_flags).flags &= ~FLAG_SPACE;
		(*t_flags).flags &= ~FLAG_PLUS;
		// write((*t_flags).fd, &"-", 1);
		buffer_writer(&"-", 1, t_flags, t_prnt);
		(*t_flags).total_chars_printed++;
		(*t_flags).special_chars_printed++;
	}
	if (((*t_flags).flags & FLAG_PLUS) > 0)
	{
		// write((*t_flags).fd, &"+", 1);
		buffer_writer(&"+", 1, t_flags, t_prnt);
		(*t_flags).special_chars_printed++;
		(*t_flags).total_chars_printed++;
	}
	if (((*t_flags).flags & FLAG_SPACE) && ((!((*t_prnt).diff)) ||
	((*t_prnt).pad_len <= 0)))
	{
		// write((*t_flags).fd, &" ", 1);
		buffer_writer(&" ", 1, t_flags, t_prnt);
		(*t_flags).special_chars_printed++;
		(*t_flags).total_chars_printed++;
	}
	(*t_prnt).sign_printed = 1;
}

void		check_negative_num(long long *arg, t_format *t_flags, \
t_print *t_prnt, int l)
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
	else if ((*t_flags).modifier == h)
		*arg = (short)(*arg);
	else if ((*t_flags).modifier == hh)
		*arg = (signed char)(*arg);
	else if ((*t_flags).modifier == l)
		*arg = (long)(*arg);
	else if ((*t_flags).modifier == ll)
		*arg = (long long)(*arg);
}

void		check_modif_un(unsigned long long *arg, t_format *t_flags)
{
	if ((*t_flags).modifier == h)
		*arg = (unsigned short)(*arg);
	else if ((*t_flags).modifier == hh)
		*arg = (unsigned char)(*arg);
	else if ((*t_flags).modifier == l)
		*arg = (unsigned long)(*arg);
	else if ((*t_flags).modifier == ll)
		*arg = (unsigned long long)(*arg);
	else
		*arg = (unsigned int)(*arg);
}
