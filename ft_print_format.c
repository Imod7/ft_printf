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
	if ((((*t_flags).flags & (FLAG_PLUS | FLAG_NEGAT)) > 0) && \
	(((*t_flags).flags & FLAG_ZERO) == 0))
		(*t_flags).special_chars_printed++;
	if ((((*t_flags).flags & FLAG_HT) > 0) && (((*t_flags).argtype == 'x') || \
	((*t_flags).argtype == 'X')))
		(*t_flags).special_chars_printed = (*t_flags).special_chars_printed + 2;
	if ((((*t_flags).flags & FLAG_HT) > 0) && ((*t_flags).argtype == 'o'))
		(*t_flags).special_chars_printed++;
	// if (((*t_flags).argtype == 'f') && ((*t_flags).float_decpart_len < 6))
		// (*t_flags).minfw = 6;
	pad_len = (*t_flags).minfw - (*t_flags).special_chars_printed - number_of_digits;
	// printf("padding = minfw %d - special_chars %d - digits %d", (*t_flags).minfw, (*t_flags).special_chars_printed, number_of_digits);
	// printf("\npad_len = %d\n", pad_len);
	// printf("\nprecision = %d\n", (*t_flags).precision);
	while (i < pad_len)
	{
		if (((*t_flags).flags & FLAG_ZERO)) //|| ((*t_flags).flags & FLAG_PRECIS))
			c = '0';
		else
			c = ' ';
		// printf("\n i = %d, pad_len = %d - precision = %d - number_of_digits = %d \n", i, pad_len, (*t_flags).precision, number_of_digits);
		if (((*t_flags).flags & FLAG_PRECIS) && \
		(i >= (pad_len - (*t_flags).precision) + number_of_digits))
			c = '0';
		ft_putchar(c);
		(*t_flags).total_chars_printed++;
		i++;
	}
}

void		print_sign(t_format *t_flags)
{
	// printf("this is printed");
	// print_binary((*t_flags).flags);
	// printf("\n");
	if (((*t_flags).flags & FLAG_PLUS) > 0)
	{
		ft_putchar('+');
		(*t_flags).special_chars_printed++;
		(*t_flags).total_chars_printed++;
	}
	if (((*t_flags).flags & FLAG_SPACE) > 0)
	{
		ft_putchar(' ');
		(*t_flags).special_chars_printed++;
		(*t_flags).total_chars_printed++;
	}
	if (((*t_flags).flags & FLAG_NEGAT) > 0)
	{
		ft_putchar('-');
		//(*t_flags).special_chars_printed++;
		(*t_flags).total_chars_printed++;
	}
}

//void		check_modifier(va_list argptr, long long *arg, t_format *t_flags)
void		check_modifier(long long *arg, t_format *t_flags)
{
	// if ((*t_flags).modifier == N)
	// {
	// 	printf(ANSI_COLOR_GREEN"\n before typecast : %lld \n", *arg);
	// 	*arg = va_arg(argptr, int);
	// 	printf(ANSI_COLOR_CYAN"\n after typecast = %lld \n", *arg);
	// }
	// if ((*t_flags).modifier == H)
	// 	*arg = (short)va_arg(argptr, int);
	// if ((*t_flags).modifier == HH)
	// 	*arg = (signed char)va_arg(argptr, int);
	// if ((*t_flags).modifier == L)
	// 	*arg = va_arg(argptr, long);
	// if ((*t_flags).modifier == LL)
	// 	*arg = va_arg(argptr, long long);
	// if (*arg < 0)
	// 	(*t_flags).flags |= FLAG_NEGAT;
	if ((*t_flags).modifier == N)
	{
		// printf(ANSI_COLOR_GREEN"\n before typecast : %lld \n", *arg);
		*arg = (int)(*arg);
		// printf(ANSI_COLOR_CYAN"\n after typecast = %lld \n", *arg);
	}
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
