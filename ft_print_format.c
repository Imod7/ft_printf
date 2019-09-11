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

int			number_of_digits(long long num)
{
	size_t	digits;
	size_t	base;

	digits = 0;
	base = 10;
	// if (t_flags.argtype == 'o')
	// 	base = 8;
	// if ((t_flags.argtype == 'x') || (t_flags.argtype == 'X'))
	// 	base = 16;
	if (num < 0)
	{
		num = num * (-1);
		// digits--;
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
	if ((t_flags.argtype == 'x') || (t_flags.argtype == 'X') || \
	(t_flags.argtype == 'p'))
		base = 16;
	while (num > 0)
	{
		num = num / base;
		digits++;
	}
	return (digits);
}

/*
** If FLAG_PLUS or FLAG_NEGAT is set AND FLAG_ZERO is not set
** then we need to increase the special_chars_printed
*/

void		print_padding(t_format *t_flags, int number_of_digits)
{
	int		i;
	int		pad_len;
	int		c;

	i = 0;
	if ((((*t_flags).flags & (FLAG_PLUS)) > 0) && 
	(((*t_flags).flags & FLAG_ZERO) == 0))
	{
		// printf("\nFlag plus AND NO flag zero\n");
		(*t_flags).special_chars_printed++;
	}
	if ((((*t_flags).flags & (FLAG_NEGAT)) > 0) && 
	(((*t_flags).flags & FLAG_ZERO) == 0))
	{
		// printf("\nFlag negative AND NO flag zero\n");
		(*t_flags).special_chars_printed++;
	}
	if ((((*t_flags).flags & FLAG_HT) > 0) && (((*t_flags).argtype == 'x') || \
	((*t_flags).argtype == 'X')))
	{
		// printf("\nFlag ht AND hexad \n");
		(*t_flags).special_chars_printed = (*t_flags).special_chars_printed + 2;
	}
	if ((((*t_flags).flags & FLAG_HT) > 0) && ((*t_flags).argtype == 'o'))
	{
		// printf("\nFlag ht AND octal \n");
		(*t_flags).special_chars_printed++;
	}
	if (((*t_flags).argtype == 'f') && ((*t_flags).float_decpart_len < 6) && \
	((*t_flags).float_decpart_len != 0))
	{
		(*t_flags).minfw = 6;
		printf("\n Setting minfw = %d \n", (*t_flags).minfw);
	}
	// printf("\n decpart_len = %d \n", (*t_flags).float_decpart_len);
	pad_len = (*t_flags).minfw - (*t_flags).special_chars_printed - number_of_digits;
	// printf(ANSI_COLOR_CYAN" ====== PADDING ======= \n argtype = %c \n ", (*t_flags).argtype);
	// printf("minfw = %d \n special_chars = %d \n digits = %d\n",(*t_flags).minfw, (*t_flags).special_chars_printed, number_of_digits);
	// printf("precision = %d\n", (*t_flags).precision);
	while (i < pad_len)
	{
		if (((*t_flags).flags & FLAG_ZERO) || ((*t_flags).argtype == 'f'))
			c = '0';
		else
			c = ' ';
		// printf("\n precision = %d\n", (*t_flags).precision);
		if (((*t_flags).flags & FLAG_PRECIS) && \
		(i >= (pad_len - (*t_flags).precision) + number_of_digits))
			c = '0';
		write((*t_flags).fd, &c, 1);
		(*t_flags).total_chars_printed++;
		i++;
	}
}

void		print_sign(t_format *t_flags)
{
	char	c;

	// print_binary((*t_flags).flags);
	if (((*t_flags).flags & FLAG_PLUS) > 0)
	{
		c = '+';
		write((*t_flags).fd, &c, 1);
		(*t_flags).special_chars_printed++;
		(*t_flags).total_chars_printed++;
	}
	if (((*t_flags).flags & FLAG_SPACE) > 0)
	{
		c = ' ';
		write((*t_flags).fd, &c, 1);
		(*t_flags).special_chars_printed++;
		(*t_flags).total_chars_printed++;
	}
	if (((*t_flags).flags & FLAG_NEGAT) > 0)
	{
		c = '-';
		write((*t_flags).fd, &c, 1);
		(*t_flags).total_chars_printed++;
	}
}

void		check_modifier(long long *arg, t_format *t_flags)
{
	if ((*t_flags).modifier == N)
		*arg = (int)(*arg);
	if ((*t_flags).modifier == H)
		*arg = (short)(*arg);
	if ((*t_flags).modifier == HH)
		*arg = (signed char)(*arg);
	if ((*t_flags).modifier == L)
		*arg = (long)(*arg);
	if ((*t_flags).modifier == LL)
		*arg = (long long)(*arg);
	if (*arg < 0)
		(*t_flags).flags |= FLAG_NEGAT;
}

void		check_modif_un(unsigned long long *arg, t_format *t_flags)
{
	if ((*t_flags).modifier == H)
		*arg = (unsigned short)(*arg);
	if ((*t_flags).modifier == HH)
		*arg = (unsigned char)(*arg);
	if ((*t_flags).modifier == L)
		*arg = (unsigned long)(*arg);
	if ((*t_flags).modifier == LL)
		*arg = (unsigned long long)(*arg);
}
