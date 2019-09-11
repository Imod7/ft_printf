/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_float.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/10 14:03:44 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/09/10 16:03:08 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long			decimal_precision(long long decpart_int, t_format *t_flags)
{
	long long		decpart_temp;
	int				dec_len;
	int				len;
	int				i;
	int				round_factor;

	len = 0;
	round_factor = 0;
	decpart_temp = decpart_int;
	while (decpart_temp != 0)
	{
		decpart_temp = decpart_temp / 10;
		len++;
	}
	if ((*t_flags).precision < len)
	{
		i = 0;
		dec_len = len - (*t_flags).precision;
		(*t_flags).total_chars_printed = (*t_flags).total_chars_printed + (*t_flags).precision;
		while (i < dec_len)
		{
			round_factor = decpart_int;
			decpart_int = decpart_int / 10;
			i++;
		}
		round_factor = round_factor % 10;
		if (round_factor > 4)
			decpart_int = decpart_int + 1;
	}
	return (decpart_int);
}

long long			intpart_round(long long decpart_int, long long intpart)
{
	long long		decpart_temp;

	decpart_temp = decpart_int;
	while (decpart_temp > 9)
	{
		decpart_temp = decpart_temp / 10;
	}
	if (decpart_temp > 4)
		intpart = intpart + 1;
	return (intpart);
}

long long		return_decimal_part_as_int(double num)
{
	size_t		base;
	long long 	leftpart;
	double		rightpart;
	double 		initialnumber;
	double		check_if_decimals_retrieved;
	char		*num_str;

	check_if_decimals_retrieved = 1;
	base = 10;
	initialnumber = num;
	rightpart = 1;
	num_str = ft_itoa_float(num);
	printf("\nnum = %s\n", num_str);
	while (check_if_decimals_retrieved > (float)0)
	{
		leftpart = (long long)(initialnumber * base);
		rightpart = ((initialnumber * base) - leftpart);
		check_if_decimals_retrieved = ((int)(rightpart * 100 + .5) / 100.0);
		base = base * 10;
	}
	return (leftpart);
}

void				print_float(va_list argptr, t_format *t_flags)
{
	long long		intpart;
	double			decpart;
	long long		decpart_int;
	double			wholenumber;
	int				len;
	size_t			i;

	wholenumber = va_arg(argptr, double);
	intpart = (long long)wholenumber;
	check_modifier(&intpart, t_flags);
	if (((*t_flags).flags & FLAG_PRECIS) == 0)
		(*t_flags).precision = 6;
	len = number_of_digits(intpart);
	(*t_flags).total_chars_printed = (*t_flags).total_chars_printed + len;
	// printf("total_chars_printed = %d\n", (*t_flags).total_chars_printed);
	printf("\nprecision = %d", (*t_flags).precision);
	// if (((*t_flags).flags & FLAG_MINUS) > 0)
	// 	intwithminus(intpart, t_flags, len);
	// else
	// 	int_otherflag(intpart, t_flags, len);
	decpart = wholenumber - intpart;
	decpart_int = return_decimal_part_as_int(decpart);
	if ((*t_flags).precision != 0)
	{
		ft_putnbr_int(intpart, (*t_flags).fd);
		write((*t_flags).fd, ".", 1);
		(*t_flags).total_chars_printed++;
	}
	clear_forfloat(t_flags);
	(*t_flags).float_decpart_len = number_of_digits(decpart_int);
	if (((*t_flags).precision != 0) && (decpart == 0))
	{
		i = 0;
		while (i < 6)
		{
			ft_putnbr_int(decpart_int, (*t_flags).fd);
			i++;
		}
	}
	else if ((*t_flags).precision != 0 && (decpart != 0))
    {
        decpart_int = decimal_precision(decpart_int,t_flags);
    	ft_putnbr_int(decpart_int, (*t_flags).fd);
    }
	if ((*t_flags).precision == 0)
	{
		intpart = intpart_round(decpart_int, intpart);
		ft_putnbr_int(intpart, (*t_flags).fd);
	}
}
