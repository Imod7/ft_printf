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
	// printf("\n >>> digits = %lld <<< \n", num);
	// printf("\n signed ll = %lld \n ", num);
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
	// printf("\n num = '%llx' \n", num);
	if (t_flags.argtype == 'o')
		base = 8;
	if ((t_flags.argtype == 'x') || (t_flags.argtype == 'X') || \
	(t_flags.argtype == 'p'))
		base = 16;
	while (num > 0)
	{
		// printf("\n num = '%llx' \n", num);
		num = num / base;
		digits++;
	}
	// printf("\n num = %zu \n", digits);
	return (digits);
}

long long		return_decimal_part_as_int(double num)
{
	size_t		base;
	long long 	leftpart;
	double		rightpart;
	double 		initialnumber;
	double		check_if_decimals_retrieved;

	check_if_decimals_retrieved = 1;
	base = 10;
	initialnumber = num;
	rightpart = 1;
	// printf(ANSI_COLOR_CYAN"\ninside number_of_digits_float : initial number  = %.11f \n", num);
	while (check_if_decimals_retrieved > (float)0)
	{
		leftpart = (long long)(initialnumber * base);
		rightpart = ((initialnumber * base) - leftpart);
		// printf("initialnumber = %.11f , leftpart = %lld, rightpart = %.11f , check = %f\n", initialnumber, leftpart, rightpart, check_if_decimals_retrieved);
		check_if_decimals_retrieved = ((int)(rightpart * 100 + .5) / 100.0);
		base = base * 10;
	}
	return (leftpart);
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
		// printf("\n Setting minfw = %d \n", (*t_flags).minfw);
	}
	// printf("\n decpart_len = %d \n", (*t_flags).float_decpart_len);
	pad_len = (*t_flags).minfw - (*t_flags).special_chars_printed - number_of_digits;
	// printf(ANSI_COLOR_CYAN" ====== PADDING ======= \n argtype = %c \n ", (*t_flags).argtype);
	// printf("minfw = %d \n special_chars = %d \n digits = %d\n",(*t_flags).minfw, (*t_flags).special_chars_printed, number_of_digits);
	// printf("\npad_len = %d\n", pad_len);
	// printf("precision = %d\n", (*t_flags).precision);
	while (i < pad_len)
	{
		if (((*t_flags).flags & FLAG_ZERO) || ((*t_flags).argtype == 'f'))
			c = '0';
		else
			c = ' ';
		// printf("\n i = %d, pad_len = %d - precision = %d - number_of_digits = %d \n", i, pad_len, (*t_flags).precision, number_of_digits);
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
