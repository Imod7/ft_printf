/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_commonchecks.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/18 16:47:49 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/09/18 16:47:51 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	check_plusflag(t_format *t_flags)
{
	if ((*t_flags).argtype == 'u')
	{
		(*t_flags).flags &= ~FLAG_PLUS;
		(*t_flags).flags &= ~FLAG_SPACE;
	}
	if (((*t_flags).flags & FLAG_PLUS) > 0)
		(*t_flags).flags &= ~FLAG_SPACE;
}

void	print_order(t_format *t_flags, t_print *t_prnt, int len)
{
	if ((((*t_flags).argtype == 'o') > 0) && \
	(((*t_flags).flags & FLAG_HT) > 0))
		(*t_flags).special_chars_printed++;
	print_padding(t_flags, t_prnt, len);
	print_sign(t_flags, t_prnt);
}

void	print_inverse(t_format *t_flags, t_print *t_prnt, int len)
{
	print_sign(t_flags, t_prnt);
	print_padding(t_flags, t_prnt, len);
}

void	length_precision_diff(t_format *t_flags, int len)
{
	int	diff;

	diff = (*t_flags).precision - len;
	(*t_flags).total_chars_printed += diff;
	while (diff > 0)
	{
		write((*t_flags).fd, "0", 1);
		diff--;
	}
}

void	length_precision_diff_zeros(t_format *t_flags, t_print *t_pr, int len)
{
	int	diff;
	// int	increase;

	if (((*t_flags).minfw != 0) && ((*t_flags).precision != 0))
		diff = (*t_flags).minfw - (*t_pr).pad_len;
	else if (((*t_flags).minfw == 0) && ((*t_flags).precision != 0))
		// diff = (*t_flags).precision - len;
		diff = (*t_flags).precision;
	else
		diff = (*t_flags).precision - (*t_pr).pad_len - (*t_flags).special_chars_printed - len;
	// increase = diff - len;
	if (diff > 0)
	{
		(*t_flags).special_chars_printed += diff;
		(*t_flags).total_chars_printed += diff;
	}
	// printf(ANSI_COLOR_YELLOW"PRINTIN THE DIFF = %d\n", diff);
	// printf(ANSI_COLOR_YELLOW"total = %d\n", (*t_flags).total_chars_printed);
	while (diff > 0)
	{
		write((*t_flags).fd, "0", 1);
		diff--;
	}
}

void	print_number(unsigned long long arg, t_format *t_flags, t_print *t_pr,int len)
{
	if ((arg != 0) && ((*t_flags).precision > len) && \
	((*t_flags).precision < (*t_flags).minfw))
			length_precision_diff(t_flags, len);
	if ((*t_flags).argtype == 'u')
	{
		if ((arg != 0) || \
		((arg == 0) && ((*t_flags).flags & FLAG_MINUS)) ||
		((arg == 0) && ((*t_flags).flags & FLAG_PLUS)) ||
		((arg == 0) && ((*t_flags).flags == 0)))
		// if (arg != 0) || 
		// ((arg == 0) && (((*t_flags).flags & FLAG_PRECIS) > 0) && 
		// ((*t_flags).precision > 0)) || \
		// ((arg == 0) && (((*t_flags).flags & FLAG_PRECIS) == 0)))
		{
			(*t_flags).total_chars_printed += len;
			ft_putnbr_un_int(arg, (*t_flags).fd);
		}
	}
	else if ((*t_flags).argtype == 'o')
	{
		if ((arg != 0) || \
		((arg == 0) && (((*t_flags).flags == 0))) || \
		((arg == 0) && (((*t_flags).flags & FLAG_HT) > 0)))
		{
			(*t_flags).total_chars_printed += len;
			ft_putnbr_octal(arg, (*t_flags).fd);
		}
	}
	else
	{
		if ((arg != 0) || \
		((arg == 0) && (((*t_flags).flags == 0))) || \
		((arg == 0) && (((*t_flags).flags & FLAG_HT) > 0) && \
		(((*t_flags).flags & FLAG_PRECIS) == 0)))
		{
			(*t_flags).total_chars_printed += len;
			if ((*t_flags).argtype == 'X')
				ft_putnbr_hex_capit(arg, (*t_flags).fd);
			if (((*t_flags).argtype == 'x') || \
			((*t_flags).argtype == 'p'))
				ft_putnbr_hex(arg, (*t_flags).fd);
		}
	}
	if (arg == 0)
		length_precision_diff_zeros(t_flags, t_pr, len);
}

/*
** function check_arg_zero
** Setting pad_len = -1 so the print_format function
** doesn't print any padding
*/

void	check_arg_zero(t_format *t_flags, int *len, t_print *tprnt)
{
	// printf("this is run\n");
	if ((*t_flags).precision > (*t_flags).minfw)
	{
		// printf("this is run\n");
		(*tprnt).pad_len = -1;
	}
	else if ((*t_flags).precision < (*t_flags).minfw)
		(*tprnt).pad_len = (*t_flags).minfw - (*t_flags).precision;
	else if ((*t_flags).precision != 0)
	{
		// printf("\nhere why?\n");
		(*tprnt).pad_len = (*t_flags).minfw - *len;
	}
	else
		(*tprnt).pad_len = (*t_flags).minfw;
}

void	print_number_int(long long arg, t_format *t_flags, t_print *t_pr, int len)
{
	if ((arg != 0) || \
	((arg == 0) && ((*t_flags).flags & FLAG_MINUS)) ||
	((arg == 0) && ((*t_flags).flags & FLAG_PLUS)) ||
	((arg == 0) && ((*t_flags).flags == 0)))
	{
		(*t_flags).total_chars_printed += len;
		if (((*t_flags).precision > len) && ((*t_flags).precision < (*t_flags).minfw))
			length_precision_diff(t_flags, len);
		ft_putnbr_int(arg, (*t_flags).fd);
	}
	if (((*t_flags).precision > len) && (arg == 0))
		length_precision_diff_zeros(t_flags, t_pr, len);
}

/*
** function minfw_vs_precision
** If precision > len & precision < minfw
** I update my variables special_chars and total_chars
** but the printing happens in function length_precision_diff
*/

void	minfw_vs_precision(t_format *t_flags, t_print *t_prnt, int len)
{
	int	diff;

	diff = (*t_flags).precision - len;
	if (((*t_flags).precision > len) && ((*t_flags).precision < (*t_flags).minfw))
	{
		(*t_flags).special_chars_printed += diff;
		// (*t_flags).total_chars_printed += diff;
	}
	if (((*t_flags).precision) > ((*t_flags).minfw))
		(*t_prnt).pad_len = diff;
	if ((((*t_flags).flags & FLAG_PRECIS) > 0) && \
	(((*t_flags).argtype != 's') || ((*t_flags).argtype != 'c')))
		(*t_flags).flags &= ~FLAG_ZERO;
}
