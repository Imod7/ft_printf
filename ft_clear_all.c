/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_clear_all.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 09:51:29 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/10/30 09:51:31 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

/*
** The only thing we do not initialize in the function clear_formatstruct
** is the member total_chars_printed because we need to continue counting
** for more than one arguments
*/

void				clear_formatstruct(t_format *t_flags, t_print *t_prnt)
{
	(*t_flags).flags = 0;
	(*t_flags).minfw = 0;
	(*t_flags).precision = 0;
	(*t_flags).argtype = 0;
	(*t_flags).special_chars_printed = 0;
	(*t_flags).modifier = N;
	(*t_prnt).pad_len = 0;
	(*t_prnt).diff = 0;
	(*t_prnt).sign_printed = 0;
}

void				clear_forfloat(t_float *fl_num)
{
	int				index;

	(*fl_num).f_num = 0;
	(*fl_num).mantissa = 0;
	index = 0;
	while (index < 5)
	{
		(*fl_num).exponent[index] = 0;
		index++;
	}
}
