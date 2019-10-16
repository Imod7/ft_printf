/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_integer.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/13 13:53:58 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/10/13 13:54:02 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void			int_other(long long arg, t_format *t_fl, t_print *t_pr, int len)
{
	if (((*t_fl).precision) < ((*t_fl).minfw) &&
	(((*t_fl).flags & FLAG_ZERO) == 0))
	{
		print_padding(t_fl, t_pr, len);
		print_sign(t_fl, t_pr);
		print_number_int(arg, t_fl, t_pr, len);
	}
	else
	{
		print_sign(t_fl, t_pr);
		print_padding(t_fl, t_pr, len);
		print_number_int(arg, t_fl, t_pr, len);
	}
}

void			int_minus(long long arg, t_format *t_fl, t_print *t_pr, int len)
{
	if ((((*t_fl).flags & FLAG_PRECIS) > 0) && \
	(((*t_fl).precision) > len) && \
	(((*t_fl).precision) > ((*t_fl).minfw)))
	// (((*t_fl).flags & FLAG_NEGAT) == 0)
	{
		print_sign(t_fl, t_pr);
		print_padding(t_fl, t_pr, len);
		print_number_int(arg, t_fl, t_pr, len);
	}
	else
	{
		// printf("\nMINUS is PRESENT\n");
		print_sign(t_fl, t_pr);
		print_number_int(arg, t_fl, t_pr, len);
		print_padding(t_fl, t_pr, len);
	}
}

/*
** function print_integer
** If the flag zero is SET then print first the format (plus sign)
** and then the zeros
** If flag zero is NOT SET and MINUS flag is NOT SET
** then first print the spaces and then the format
** Check Test 1, 2
*/

void			print_integer(va_list argptr, t_format *tflags, t_print *tprnt)
{
	long long	arg;
	int			len;

	arg = va_arg(argptr, long long);
	check_plusflag(tflags);
	check_modifier(&arg, tflags);
	check_negative_num(&arg, tflags);
	len = number_of_digits(arg);
	minfw_vs_precision(tflags, tprnt, len);
	// printf("\ntotal = %d\n", (*tflags).total_chars_printed);
	if (arg == 0)
		check_arg_zero(tflags, &len, tprnt);
	if (((*tflags).flags & FLAG_MINUS) > 0)
	{
		(*tflags).flags &= ~FLAG_ZERO;
		int_minus(arg, tflags, tprnt, len);
	}
	else
		int_other(arg, tflags, tprnt, len);
}
