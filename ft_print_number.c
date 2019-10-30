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

void	print_hex_pointer(unsigned long long arg, t_format *tfl, int len)
{
	if ((arg != 0) || \
	((arg == 0) && (((*tfl).flags == 0))) || \
	((arg == 0) && (((*tfl).flags & FLAG_HT) > 0) && \
	(((*tfl).flags & FLAG_PRECIS) == 0)))
	{
		(*tfl).total_chars_printed += len;
		if ((*tfl).argtype == 'X')
			ft_putnbr_hex_capit(arg, (*tfl).fd);
		if (((*tfl).argtype == 'x') || \
		((*tfl).argtype == 'p'))
			ft_putnbr_hex(arg, (*tfl).fd);
	}
}

void	print_number(unsigned long long arg, t_format *tfl, t_print *pr,int len)
{
	if ((arg != 0) &&
	((*tfl).precision > len) &&
	((*tfl).precision <= (*tfl).minfw))
		length_precision_diff(tfl, len);
	if ((*tfl).argtype == 'u')
	{
		if ((arg != 0) || \
		((arg == 0) && ((*tfl).flags & FLAG_PLUS)) ||
		((arg == 0) && ((*tfl).flags == 0)))
		{
			(*tfl).total_chars_printed += len;
			ft_putnbr_un_int(arg, (*tfl).fd);
		}
	}
	else if ((*tfl).argtype == 'o')
	{
		if ((arg != 0) || \
		((arg == 0) && (((*tfl).flags == 0))) || \
		((arg == 0) && ((*tfl).flags & FLAG_HT) &&
		((*tfl).precision <= (*tfl).minfw)))
		{
			(*tfl).total_chars_printed += len;
			ft_putnbr_octal(arg, (*tfl).fd);
		}
	}
	else
		print_hex_pointer(arg, tfl, len);
	if (arg == 0)
		length_precision_diff_zeros(tfl, pr, len);
}

void	print_number_int(long long arg, t_format *tfl, t_print *tpr, int len)
{
	if ((arg != 0) || \
	((arg == 0) && ((*tfl).flags & FLAG_MINUS)) ||
	((arg == 0) && ((*tfl).flags & FLAG_PLUS)) ||
	((arg == 0) && ((*tfl).flags & FLAG_ZERO)) ||
	((arg == 0) && ((*tfl).flags == 0)))
	{
		(*tfl).total_chars_printed += len;
		if (((*tfl).precision > len) && ((*tfl).precision < (*tfl).minfw))
			length_precision_diff(tfl, len);
		ft_putnbr_int(arg, (*tfl).fd);
	}
	if (((*tfl).precision > len) && (arg == 0))
		length_precision_diff_zeros(tfl, tpr, len);
}
