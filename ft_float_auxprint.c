/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_float_auxprint.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 14:49:46 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/09/26 14:49:48 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void			print_final_float(short *pr, t_format *t_flags, t_print *t_prnt)
{
	int			index;
	int			len;

	index = 0;
	len = 0;
	if (pr[0] == 0)
	{
		index = FLOAT_MIDDLE - 1;
		while ((pr[index] != 0) && (index >= 0))
		{
			index--;
			len++;
		}
		index += 1;
	}
	while ((pr[index] != 0) && (index <= FLOAT_TOTAL_LEN))
	{
		t_prnt->writer(&pr[index], 1, t_prnt);
		index++;
		(*t_flags).total_chars_printed++;
	}
	if (((*t_flags).flags & FLAG_HT) && ((*t_flags).precision == 0))
	{
		t_prnt->writer(&".", 1, t_prnt);
		(*t_flags).total_chars_printed++;
	}
}
