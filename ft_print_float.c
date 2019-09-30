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

void				print_float(va_list argptr, t_format *t_flags)
{
	ft_ftoa(argptr, t_flags);
	// wholenumber = va_arg(argptr, double);
	// intpart = (long long)wholenumber;
	// check_modifier(&intpart, t_flags);
	// if (((*t_flags).flags & FLAG_PRECIS) == 0)
	// 	(*t_flags).precision = 6;
	// len = number_of_digits(intpart);
	// (*t_flags).total_chars_printed = (*t_flags).total_chars_printed + len;
	// // printf("total_chars_printed = %d\n", (*t_flags).total_chars_printed);
	// // printf("\nprecision = %d", (*t_flags).precision);
	// // if (((*t_flags).flags & FLAG_MINUS) > 0)
	// // 	intwithminus(intpart, t_flags, len);
	// // else
	// // 	int_otherflag(intpart, t_flags, len);
	// decpart = wholenumber - intpart;
	// decpart_int = return_decimal_part_as_int(decpart, (*t_flags).precision);
	// if ((*t_flags).precision != 0)
	// {
	// 	ft_putnbr_int(intpart, (*t_flags).fd);
	// 	write((*t_flags).fd, ".", 1);
	// 	(*t_flags).total_chars_printed++;
	// }
	// clear_forfloat(t_flags);
	// (*t_flags).float_decpart_len = number_of_digits(decpart_int);
	// if (((*t_flags).precision != 0) && (decpart == 0))
	// {
	// 	i = 0;
	// 	while (i < 6)
	// 	{
	// 		ft_putnbr_int(decpart_int, (*t_flags).fd);
	// 		i++;
	// 	}
	// }
	// else if ((*t_flags).precision != 0 && (decpart != 0))
    // {
    //     decpart_int = decimal_precision(decpart_int,t_flags);
    // 	ft_putnbr_int(decpart_int, (*t_flags).fd);
    // }
	// if ((*t_flags).precision == 0)
	// {
	// 	intpart = intpart_round(decpart_int, intpart);
	// 	ft_putnbr_int(intpart, (*t_flags).fd);
	// }
}
