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
	t_float			float_num;
	short			product[10000];

	ft_ftoa(argptr, t_flags, &float_num, product);
	check_precision(product, t_flags);
	print_padding(t_flags, length_product(product));
	print_final_float(product, t_flags);
	(*t_flags).total_chars_printed = (*t_flags).total_chars_printed + \
	length_product(product);
	clear_forfloat(&float_num);
}
