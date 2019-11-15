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

void			print_final_float(short *pr, t_format *t_flags, t_print *tprnt)
{
	int			index;
	char		*str;

	index = 0;
	str = 0;
	// (*tprnt).buf_index = 0;
	if ((pr[4999] == 0) && (pr[5000] == '0') && ((*t_flags).precision == 0))
	{
		buffer_writer(&"0", 1, t_flags, tprnt);
		(*t_flags).total_chars_printed++;
	}
	// if (((*t_flags).precision == 0) && (len == 1))
	// 	write((*t_flags).fd, &"0", 1);
	else
	{
		// while (pr[index] == 0)
		while ((pr[index] == 0) && (index <= 10000))
		{
			index++;
		}
		while ((pr[index] != 0) && (index <= 10000))
		{
			// write((*t_flags).fd, &pr[index], 1);
			// printf("\nthis is run pr = %c", pr[index]);
			// printf("\n EDW str = %c", *str);
			buffer_writer(&pr[index], 1, t_flags, tprnt);
			index++;
			(*t_flags).total_chars_printed++;
			// if (((*t_flags).precision == 0) && (len == 1))
			// 	break ;
			// buffer_writer("0", 1, t_flags, tprnt);
		}
	}
	if (((*t_flags).flags & FLAG_HT) && ((*t_flags).precision == 0))
	{
		buffer_writer(&".", 1, t_flags, tprnt);
		// write((*t_flags).fd, &".", 1);
		// buffer_writer(".", t_flags, tprnt);
		(*t_flags).total_chars_printed++;
	}
}
