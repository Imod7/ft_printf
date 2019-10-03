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

#include "ft_printf.h"

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

void	check_arg_zero(t_format *t_flags, int *len)
{
	if (((*t_flags).minfw > 0) || \
	(((*t_flags).minfw == 0) && \
	((*t_flags).minfw < (*t_flags).precision)))
		*len = 0;
}

void	print_order(t_format *t_flags, int len)
{
	if ((((*t_flags).argtype == 'o') > 0) && \
	(((*t_flags).flags & FLAG_HT) > 0))
		(*t_flags).special_chars_printed++;
	print_padding(t_flags, len);
	print_sign(t_flags);
}

void	print_inverse(t_format *t_flags, int len)
{
	print_sign(t_flags);
	print_padding(t_flags, len);
}

void	print_number(unsigned long long arg, t_format *t_flags, int len)
{
	if ((*t_flags).argtype == 'u')
	{
		if ((arg != 0) || \
		((arg == 0) && (((*t_flags).flags & FLAG_PRECIS) > 0) && \
		((*t_flags).precision > 0)) || \
		((arg == 0) && (((*t_flags).flags & FLAG_PRECIS) == 0)))
		{
			(*t_flags).total_chars_printed = (*t_flags).total_chars_printed + len;
			ft_putnbr_un_int(arg, (*t_flags).fd);
		}
	}
	else if ((*t_flags).argtype == 'o')
	{
		if ((arg != 0) || \
		((arg == 0) && (((*t_flags).flags == 0))) || \
		((arg == 0) && (((*t_flags).flags & FLAG_HT) > 0)))
		{
			(*t_flags).total_chars_printed = (*t_flags).total_chars_printed + len;
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
			(*t_flags).total_chars_printed = (*t_flags).total_chars_printed + len;
			if ((*t_flags).argtype == 'X')
				ft_putnbr_hex_capit(arg, (*t_flags).fd);
			if (((*t_flags).argtype == 'x') || \
			((*t_flags).argtype == 'p'))
				ft_putnbr_hex(arg, (*t_flags).fd);
		}
	}
	
}

void	print_number_int(long long arg, t_format *t_flags, int len)
{
	if ((arg != 0) || \
	((arg == 0) && (((*t_flags).flags == 0))) || \
	((arg == 0) && (((*t_flags).flags & FLAG_HT) > 0)) || \
	((arg == 0) && (((*t_flags).flags & FLAG_PLUS) > 0)))
	{
		(*t_flags).total_chars_printed = (*t_flags).total_chars_printed + len;
		// if (((*t_flags).argtype == 'd') || \
		// ((*t_flags).argtype == 'i'))
		ft_putnbr_int(arg, (*t_flags).fd);
	}
}

void		minfw_vs_precision(t_format *t_flags)
{
	if (((*t_flags).minfw == 0) && \
	((*t_flags).minfw < (*t_flags).precision))
		(*t_flags).minfw = (*t_flags).precision;
	if ((((*t_flags).flags & FLAG_PRECIS) > 0) && \
	(((*t_flags).argtype != 's') || ((*t_flags).argtype != 'c')))
		(*t_flags).flags &= ~FLAG_ZERO;
}

void					length_precision_diff(t_format *t_flags, int len)
{
	int					diff;

	diff = (*t_flags).precision - len;
	while (diff > 0)
	{
		write((*t_flags).fd, "0", 1);
		(*t_flags).special_chars_printed++;
		(*t_flags).total_chars_printed++;
		diff--;
	}
}
