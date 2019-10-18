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
	// if ((((*fl).argtype == 'o') > 0) && \
	// (((*fl).flags & FLAG_HT) > 0))
	// {
	// 	(*fl).special_chars_printed++;
	// }
	if ((((*fl).precision) > l) &&
	(((*fl).precision) > ((*fl).minfw)))
	{
		// printf("\nsign padding number\n");
		print_inverse(fl, pn, l);
		print_number(ar, fl, pn, l);
	}
	// else if (((*fl).flags & FLAG_MINUS) &&
	// (((*fl).precision) < ((*fl).minfw)))
	// {
	// 	printf("\n  sign padding number\n");
	// 	print_inverse(fl, pn, l);
	// 	print_number(ar, fl, l);
	// }
	// else if ((((*fl).flags & FLAG_NEGAT) == 0) && \
	// (((*fl).flags & FLAG_SPACE) == 0) && \
	// (((*fl).flags & FLAG_PRECIS) == 0))
	// {
	// 	printf("\n13edw\n");
	// 	print_number(ar, fl, l);
	// 	print_inverse(fl, pn, l);
	// }
	// if ((((*fl).flags & FLAG_NEGAT) > 0) && \
	// (((*fl).flags & FLAG_SPACE) > 0))
	// {
	// 	printf("\n14edw\n");
	// 	(*fl).flags &= ~FLAG_SPACE;
	// 	print_sign(fl, pn);
	// 	print_number(ar, fl, l);
	// 	print_padding(fl, pn, l);
	// }
	else
	{
		print_number(ar, fl, pn, l);
		print_inverse(fl, pn, l);
	}
}

void		unsign_checkht(unsigned long long arg, t_format *t_flags)
{
	char	c;

	if ((((*t_flags).argtype == 'o') > 0) &&
	((arg != 0) && (((*t_flags).flags & FLAG_HT) > 0)) &&
	((*t_flags).minfw > (*t_flags).precision))
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
