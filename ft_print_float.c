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

#include "includes/ft_printf.h"

int				length_adjust(short *product, t_format *t_flags)
{
	int			len;

	if ((product[4999] == '0') && (product[5000] == '0'))
		len = 1;
	else
		len = length_product(product);
	if (((*t_flags).flags & FLAG_NEGAT) &&
	(!((*t_flags).flags & FLAG_MINUS)) &&
	(!((*t_flags).flags & FLAG_ZERO)))
		(*t_flags).special_chars_printed++;
	return (len);
}

void				print_float(va_list argptr, t_format *t_flags)
{
	t_float			float_num;
	short			product[10000];
	int				len;
	int				result;

	result = ft_ftoa(argptr, t_flags, &float_num, product);
	check_precision(product, t_flags);
	len = length_adjust(product, t_flags);
	if (result == -1)
		len = 4;
	else if ((result == 1) || (result == 2))
		len = 3;
	if ((*t_flags).flags & FLAG_MINUS)
	{
		print_sign(t_flags);
		print_final_float(product, t_flags);
		print_padding(t_flags, len);
	}
	else if (((*t_flags).flags & FLAG_NEGAT) &&
	(!((*t_flags).flags & FLAG_ZERO)))
	{
		print_padding(t_flags, len);
		print_sign(t_flags);
		print_final_float(product, t_flags);
	}
	else
	{
		print_sign(t_flags);
		print_padding(t_flags, len);
		print_final_float(product, t_flags);
	}
	(*t_flags).total_chars_printed = (*t_flags).total_chars_printed + len;
	clear_forfloat(&float_num);
}
