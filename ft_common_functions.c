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
	if (((*t_flags).argtype == 'o') &&
	((*t_flags).flags & FLAG_HT) &&
	((*t_flags).minfw >= (*t_flags).precision) &&
	((*t_flags).precision == 0))
		(*t_flags).special_chars_printed++;
	if ((((*t_flags).argtype == 'x') ||
	((*t_flags).argtype == 'X')) &&
	((*t_flags).flags & FLAG_HT) &&
	((*t_flags).minfw > (*t_flags).precision))
		(*t_flags).special_chars_printed += 2;
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
	if (((*t_flags).precision > len) && \
	((*t_flags).precision < (*t_flags).minfw))
	{
		(*t_flags).special_chars_printed += diff;
	}
	if (((*t_flags).precision) > ((*t_flags).minfw))
		(*t_prnt).pad_len = diff;
	if ((((*t_flags).flags & FLAG_PRECIS) > 0) && \
	(((*t_flags).argtype != 's') || ((*t_flags).argtype != 'c')))
		(*t_flags).flags &= ~FLAG_ZERO;
}
