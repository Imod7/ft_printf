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

void	check_arg_zero(unsigned long long *arg, t_format *t_flags)
{
	*arg = 0;
	if ((*t_flags).minfw == 0)
	{
		(*t_flags).flags &= ~FLAG_PRECIS;
		(*t_flags).flags &= ~FLAG_ZERO;
	}
	// if (((*t_flags).flags & FLAG_HT) > 0)
	// 	(*t_flags).flags |= FLAG_ZERO;
	// if (((*t_flags).precision == 0) && \
	// (((*t_flags).flags & FLAG_PRECIS) > 0))
	// {
	// 	(*t_flags).flags &= ~FLAG_PRECIS;
	// 	(*t_flags).flags &= ~FLAG_ZERO;
	// }
}

void	print_order(t_format *t_flags, int len)
{
	print_padding(t_flags, len);
	print_sign(t_flags);
}

void	print_inverse(t_format *t_flags, int len)
{
	print_sign(t_flags);
	print_padding(t_flags, len);
}

void	print_number(unsigned long long arg, t_format *t_flags)
{
	if ((arg != 0) ||
	((arg == 0) && (((*t_flags).flags & FLAG_HT) > 0)))
	{
		if ((*t_flags).argtype == 'o')
			ft_putnbr_octal(arg, (*t_flags).fd);
	}
	if ((*t_flags).argtype == 'X')
		ft_putnbr_hex_capit(arg, (*t_flags).fd);
	else if (((*t_flags).argtype == 'x') || \
	((*t_flags).argtype == 'p'))
		ft_putnbr_hex(arg, (*t_flags).fd);
	else if ((*t_flags).argtype == 'u')
		ft_putnbr_un_int(arg, (*t_flags).fd);
	else if (((*t_flags).argtype == 'd') || \
	((*t_flags).argtype == 'i'))
		ft_putnbr_int(arg, (*t_flags).fd);
}
