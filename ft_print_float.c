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

	len = 0;
	// printf("\n\n dom \n\n");
	printf("\noriginal decimal part = %lld", decpart_int);
	decpart_temp = decpart_int;
	while (decpart_temp != 0)
	{
		decpart_temp = decpart_temp / 10;
		len++;
	}
	if ((*t_flags).precision < len)
	{
		i = 0;
		decpart_temp = decpart_int;
		dec_len = len - (*t_flags).precision;
		while (i < dec_len)
		{
			decpart_temp = decpart_temp / 10;
			i++;
		}
		// printf("\nlen = %d , precision = %d\ndecpart before rounding = %lld", len, (*t_flags).precision, decpart_temp);
		decpart_temp = (decpart_temp + 0.5);
	}
	// printf("\nreturn value = %lld", decpart_temp);
	decpart_temp = (int)decpart_temp;
	return (decpart_temp);
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
	// printf("\nWHOLE NUMBER = %.11f , intpart = %lld \n", wholenumber, intpart);
	len = number_of_digits(intpart);
	(*t_flags).total_chars_printed = (*t_flags).total_chars_printed + len;
	if ((*t_flags).precision == 0)
		intpart = (int)(intpart + 1);
	// if (((*t_flags).flags & FLAG_MINUS) > 0)
	// 	intwithminus(intpart, t_flags, len);
	// else
	// 	int_otherflag(intpart, t_flags, len);
	ft_putnbr_int(intpart, (*t_flags).fd);
	decpart = wholenumber - intpart;
	decpart_int = return_decimal_part_as_int(decpart);
	if ((*t_flags).precision != 0)
		write((*t_flags).fd, ".", 1);
	(*t_flags).total_chars_printed++;
	clear_forfloat(t_flags);
	(*t_flags).float_decpart_len = number_of_digits(decpart_int);
	// printf("\nFUNCTION PRINT_FLOAT\n===============\nwhole number = %f\nintpart = %lld\ndecpart_int = %lld\nlen = %d\nprecision=%d\n", wholenumber, intpart, decpart_int, len, (*t_flags).precision);
	(*t_flags).total_chars_printed = (*t_flags).total_chars_printed + (*t_flags).float_decpart_len;
	// printf("total_chars_printed increased by len [%d] = %d\n", len, (*t_flags).total_chars_printed);
	if (decpart_int == 0 && (*t_flags).precision != 0)
	{
		i = 0;
		while (i < 6)
		{
			ft_putnbr_int(decpart_int, (*t_flags).fd);
			i++;
		}
	}
	else if ((*t_flags).precision != 0)
    {
		// printf("\n --- I have to split the decimal part --- \n");
        decpart_int = decimal_precision(decpart_int,t_flags);
        ft_putnbr_int(decpart_int, (*t_flags).fd);
    }
	// if (len == 0)
	// 	len = 5;
	// print_padding(t_flags, len);
}
