/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_checks_unsigned.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/13 13:43:06 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/10/13 13:43:08 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		unsig_minus(unsigned long long ar, t_format *fl, t_print *pn, int l)
{
	if ((((*fl).precision) > l) &&
	(((*fl).precision) > ((*fl).minfw)))
	{
		print_inverse(fl, pn, l);
		print_number(ar, fl, pn, l);
	}
	else
	{
		print_number(ar, fl, pn, l);
		print_inverse(fl, pn, l);
	}
}

void		unsign_checkht(unsigned long long arg, t_format *t_flags, int len)
{
	char	c;

	if ((((*t_flags).argtype == 'o') > 0) &&
	(arg != 0) && ((*t_flags).flags & FLAG_HT) &&
	// ((*t_flags).minfw >= (*t_flags).precision) &&
	(*t_flags).precision < len)
	{
		c = '0';
		write((*t_flags).fd, &c, 1);
		(*t_flags).total_chars_printed++;
		(*t_flags).special_chars_printed++;
	}
	if ((((*t_flags).flags & FLAG_HT) > 0) && (arg != 0) && \
	((*t_flags).argtype != 'o'))
	{
		if (((*t_flags).argtype == 'x') || ((*t_flags).argtype == 'p'))
			write((*t_flags).fd, "0x", 2);
		else
			write((*t_flags).fd, "0X", 2);
		(*t_flags).total_chars_printed += 2;
		if (((*t_flags).minfw > (*t_flags).precision) && \
		((*t_flags).argtype != 'p'))
			(*t_flags).special_chars_printed += 2;
	}
}
