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

void			print_final_float(short *pr, t_format *t_flags)
{
	int			index;

	index = 0;
	if ((pr[4999] == '0') && (pr[5000] == '0'))
		write((*t_flags).fd, &"0", 1);
	else
	{
		// while (pr[index] == 0)
		while ((pr[index] == 0) && (index <= 10000))
		{
			index++;
		}
		// while (pr[index] != 0)
		while ((pr[index] != 0) && (index <= 10000))
		{
			// printf("\n >>> pr[%d] = %d, len =  , pr = %c%c%c", index, pr[index], pr[5000], pr[5001], pr[5002]);
			write((*t_flags).fd, &pr[index], 1);
			index++;
		}
	}
	if (((*t_flags).flags & FLAG_HT) && ((*t_flags).precision == 0))
	{
		write((*t_flags).fd, &".", 1);
		(*t_flags).total_chars_printed++;
	}
}
