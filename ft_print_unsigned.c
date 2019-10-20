/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_unsigned.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 17:43:33 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/08/19 17:43:37 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

unsigned long long		check_pointer(va_list arg, t_format *tfl)
{
	unsigned long long	argum;

	if ((*tfl).argtype == 'p')
	{
		(*tfl).flags |= FLAG_HT;
		argum = va_arg(arg, unsigned long);
		(*tfl).special_chars_printed = (*tfl).special_chars_printed + 2;
	}
	else
	{
		argum = va_arg(arg, unsigned long long);
		check_modif_un(&argum, tfl);
	}
	return (argum);
}



void					print_hexoctal(va_list arg, t_format *tfl, t_print *tpr)
{
	unsigned long long	argum;
	int					len;

	argum = check_pointer(arg, tfl);
	len = number_of_digits_un(argum, *tfl);
	minfw_vs_precision(tfl, tpr, len);
	if (argum == 0)
		check_arg_zero(tfl, &len, tpr);
	check_plusflag(tfl);
	(*tfl).flags &= ~FLAG_PLUS;
	(*tfl).flags &= ~FLAG_SPACE;
	if (((*tfl).flags & FLAG_MINUS) > 0)
	{
		(*tfl).flags &= ~FLAG_ZERO;
		unsign_checkht(argum, tfl, len);
		unsig_minus(argum, tfl, tpr, len);
	}
	else if (((*tfl).flags & FLAG_ZERO) ||
	((*tfl).precision > (*tfl).minfw))
	{
		// printf(ANSI_COLOR_YELLOW"\n zero and prec > min\n");
		unsign_checkht(argum, tfl, len);
		print_inverse(tfl, tpr, len);
		print_number(argum, tfl, tpr, len);
	}
	else if ((((*tfl).flags & FLAG_MINUS) == 0) && \
	(((*tfl).flags & FLAG_ZERO) == 0))
	{
		// printf(ANSI_COLOR_YELLOW"\n not zero \n");
		print_order(tfl, tpr, len);
		unsign_checkht(argum, tfl, len);
		print_number(argum, tfl, tpr, len);
	}
}

void					print_int_un(va_list argp, t_format *tfl, t_print *tpr)
{
	unsigned long long	arg;
	int					len;

	arg = va_arg(argp, unsigned long long);
	check_modif_un(&arg, tfl);
	len = number_of_digits_un(arg, *tfl);
	minfw_vs_precision(tfl, tpr, len);
	check_plusflag(tfl);
	if (arg == 0)
		check_arg_zero(tfl, &len, tpr);
	if (((*tfl).flags & FLAG_MINUS) > 0)
	{
		(*tfl).flags &= ~FLAG_ZERO;
		print_number(arg, tfl, tpr, len);
		print_inverse(tfl, tpr, len);
	}
	else
	{
		if ((((*tfl).flags & FLAG_ZERO) > 0) || \
		(((*tfl).flags & FLAG_PRECIS) > 0))
			print_inverse(tfl, tpr, len);
		else
		{
			print_padding(tfl, tpr, len);
			print_sign(tfl, tpr);
		}
		print_number(arg, tfl, tpr, len);
	}
}
