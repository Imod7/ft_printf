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
		while (pr[index] == 0)
			index++;
		while (pr[index] != 0)
		{
			write((*t_flags).fd, &pr[index], 1);
			index++;
		}
	}
}
