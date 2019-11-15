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

int				length_adjust(short *product)
{
	int			len;
	// int			index;

	// index = 5000;
	// len = 0;
	// while ((product[index] != 0) && (index >= 0))
	// {
	// 	index--;
	// 	len++;
	// }
	len = 0;
	if ((product[4999] == 0) && (product[5000] == '0'))
	{
		len = 1;
		return (len);
	}
	// printf("\n FOUND LENGTH ADJUST len = %d", len);
	// if (((*t_flags).precision == 0) && (product[5000] == '0'))
	// {
	// 	product[5001] = 0;
	// 	len = 1;
	// }
	else
	{
		len = length_product(product);
		// printf("\n ppppppp len = %d, pr = %c%c%c%c%c%c%c%c%c%c", len, product[0], product[1], product[2], product[3], product[4998], product[4999], product[5000], product[5001], product[5002], product[5003]);
		// printf("\n ppppppp len = %d, pr = %c%c%c%c%c%c", len, product[4998], product[4999], product[5000], product[5001], product[5002], product[5003]);
	}
	return (len);
}

void			float_checkflags(t_format *t_flags, t_print *tpr, \
				short *product, int len)
{
	if ((*t_flags).flags & FLAG_MINUS)
	{
		print_sign(t_flags, tpr);
		print_final_float(product, t_flags, tpr);
		print_padding(t_flags, tpr, len);
	}
	else if (((*t_flags).flags & FLAG_NEGAT) &&
	(!((*t_flags).flags & FLAG_ZERO)))
	{
		print_padding(t_flags, tpr, len);
		print_sign(t_flags, tpr);
		print_final_float(product, t_flags, tpr);
	}
	else
	{
		print_sign(t_flags, tpr);
		print_padding(t_flags, tpr, len);
		print_final_float(product, t_flags, tpr);
	}
}

void			print_float(va_list argptr, t_format *t_flags, t_print *tpr)
{
	t_float		float_num;
	short		product[10000];
	int			len;
	int			result;

	check_modifier_float(argptr, &float_num, t_flags);
	result = ft_ftoa(t_flags, tpr, &float_num, product);
	check_precision(product, t_flags);
	len = length_adjust(product);
	if (result == -1)
		len = 4;
	// else if ((result == 1) || (result == 2))
	else if (result == 2)
		len = 3;
	// printf("\n ??? ADJUST len = %d", len);
	float_checkflags(t_flags, tpr, product, len);
	clear_forfloat(&float_num);
}
