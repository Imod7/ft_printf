/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_number.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/17 18:17:39 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/10/17 18:17:41 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	print_hex_pointer(unsigned long long arg, t_format *tfl, \
						t_print *t_prnt, int len)
{
	if ((arg != 0) || \
	((arg == 0) && ((*tfl).flags == 0) && (*tfl).minfw == 0) ||
	((arg == 0) && (((*tfl).flags & FLAG_HT) > 0) &&
	(((*tfl).flags & FLAG_PRECIS) == 0)) ||
	((arg == 0) && (((*tfl).flags & FLAG_MINUS) > 0) &&
	(((*tfl).flags & FLAG_PRECIS) == 0)))
	{
		// printf("edw HEX min = %d\n", (*tfl).flags);
		(*tfl).total_chars_printed += len;
		if ((*tfl).argtype == 'X')
			ft_putnbr_hex_capit(arg, tfl, t_prnt);
		if (((*tfl).argtype == 'x') || \
		((*tfl).argtype == 'p'))
			ft_putnbr_hex(arg, tfl, t_prnt);
	}
}

void	print_number(unsigned long long arg, t_format *tfl, t_print *t_prnt, \
					int len)
{
	if ((arg != 0) &&
	((*tfl).precision > len) &&
	((*tfl).precision <= (*tfl).minfw))
		length_precision_diff(tfl, t_prnt, len);
	if ((*tfl).argtype == 'u')
	{
		if ((arg != 0) || \
		((arg == 0) && (!((*tfl).flags & FLAG_PRECIS)) &&
		((((*tfl).flags & FLAG_MINUS)))) ||
		((arg == 0) && ((*tfl).minfw == 0) && ((*tfl).flags == 0)))
		{
			(*tfl).total_chars_printed += len;
			ft_putnbr_un_int(arg, tfl, t_prnt);
		}
	}
	else if ((*tfl).argtype == 'o')
	{
		if ((arg != 0) || \
		((arg == 0) && ((*tfl).flags & FLAG_HT) &&
		((*tfl).precision <= (*tfl).minfw)) ||
		((arg == 0) && (!((*tfl).flags & FLAG_PRECIS)) &&
		((((*tfl).flags & FLAG_MINUS)))) ||
		((arg == 0) && ((*tfl).minfw == 0) && ((*tfl).flags == 0)))
		{
			// printf("\n EDW");
			(*tfl).total_chars_printed += len;
			ft_putnbr_octal(arg, tfl, t_prnt);
		}
	}
	else
		print_hex_pointer(arg, tfl, t_prnt, len);
	if (arg == 0)
		length_precision_diff_zeros(tfl, t_prnt, len);
}

void	print_number_int(long long arg, t_format *tfl, t_print *tpr, int len)
{
	if ((arg != 0) || \
	((arg == 0) && (!((*tfl).flags & FLAG_PRECIS))) ||
	((arg == 0) && ((*tfl).flags == 0)))
	{
		// printf("edw WWW\n");
		(*tfl).total_chars_printed += len;
		if (((*tfl).precision > len) && ((*tfl).precision < (*tfl).minfw))
			length_precision_diff(tfl, tpr, len);
		ft_putnbr_int(arg, tfl, tpr);
	}
	else if (((*tfl).precision > len) && (arg == 0))
	{
		// printf("edw HHHH min = %d\n", (*tfl).minfw);
		length_precision_diff_zeros(tfl, tpr, len);
	}
}
