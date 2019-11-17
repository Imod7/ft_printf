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

void			check_argzero(short *product, t_format *t_flags, t_print *tprnt)
{
	if (length_product_intpart(product) == 2 && \
	(product[FLOAT_MIDDLE - 2] == '0') && \
	((*t_flags).precision == 0))
	{
		buffer_writer(&"0", 1, t_flags, tprnt);
		(*t_flags).total_chars_printed++;
	}
	else
		print_final_float(product, t_flags, tprnt);
}

void			float_checkflags(t_format *t_flags, t_print *tprnt, \
								short *product, int len)
{
	if ((*t_flags).flags & FLAG_MINUS)
	{
		print_sign(t_flags, tprnt);
		check_argzero(product, t_flags, tprnt);
		print_padding(t_flags, tprnt, len);
	}
	else if (((*t_flags).flags & FLAG_NEGAT) &&
	(!((*t_flags).flags & FLAG_ZERO)))
	{
		print_padding(t_flags, tprnt, len);
		print_sign(t_flags, tprnt);
		check_argzero(product, t_flags, tprnt);
	}
	else
	{
		print_sign(t_flags, tprnt);
		print_padding(t_flags, tprnt, len);
		check_argzero(product, t_flags, tprnt);
	}
}

void			print_float(va_list argptr, t_format *t_flags, t_print *tpr)
{
	t_float		float_num;
	short		product[FLOAT_TOTAL_LEN];
	int			len;
	int			result;

	check_modifier_float(argptr, &float_num, t_flags);
	result = ft_ftoa(t_flags, tpr, &float_num, product);
	check_precision(product, t_flags);
	len = length_product(product);
	if (result == -1)
		len = 4;
	float_checkflags(t_flags, tpr, product, len);
	clear_forfloat(&float_num);
}
