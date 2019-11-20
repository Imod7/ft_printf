/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_zero_arg.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/17 18:49:42 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/10/17 18:49:45 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

/*
** function check_arg_zero
** Setting pad_len = -1 so the print_format function
** doesn't print any padding
*/

void	check_arg_zero(t_format *t_flags, int *len, t_print *tprnt)
{
	if ((*t_flags).precision > (*t_flags).minfw)
		(*tprnt).pad_len = -1;
	else if ((((*t_flags).precision < (*t_flags).minfw) && \
	((*t_flags).argtype == 'p')) || \
	(!((*t_flags).flags & (FLAG_PRECIS))))
		(*tprnt).pad_len = (*t_flags).minfw - (*t_flags).special_chars_printed -
		*len;
	else if (((*t_flags).precision < (*t_flags).minfw) && \
	(!((*t_flags).flags & (FLAG_HT))) &&
	(!((*t_flags).flags & (FLAG_ZERO))))
		(*tprnt).pad_len = (*t_flags).minfw - (*t_flags).precision;
	else if (((*t_flags).precision <= (*t_flags).minfw) && \
	((((*t_flags).flags & (FLAG_HT)) &&
	((*t_flags).argtype == 'o')) ||
	((*t_flags).flags & (FLAG_ZERO))))
		(*tprnt).pad_len = (*t_flags).minfw - *len;
	else
		(*tprnt).pad_len = (*t_flags).minfw;
	if ((*t_flags).flags & (FLAG_PLUS))
		(*tprnt).pad_len -= 1;
	if ((*t_flags).flags & FLAG_SPACE)
		(*tprnt).pad_len = 0;
}

void	length_precision_diff_zeros(t_format *t_flags, t_print *t_pr, int len)
{
	int	diff;

	diff = 0;
	if (!((((*t_flags).flags & (FLAG_MINUS)) > 0) && \
	((*t_flags).argtype == 'u') &&
	((*t_flags).minfw == (*t_flags).precision)))
	{
		if ((*t_flags).minfw == (*t_flags).precision)
			diff = (*t_flags).precision - len;
		else if (((*t_flags).minfw != 0) && \
		((*t_flags).precision < (*t_flags).minfw) &&
		(!((*t_flags).flags & (FLAG_HT))) &&
		(!((*t_flags).flags & (FLAG_MINUS))) &&
		(!((*t_flags).flags & (FLAG_PLUS))))
			diff = (*t_flags).minfw - (*t_pr).pad_len;
		else if (((*t_flags).minfw == 0) || ((*t_flags).precision != 0))
			diff = (*t_flags).precision;
		else
		{
			diff = (*t_flags).precision - (*t_pr).pad_len - \
			(*t_flags).special_chars_printed - len;
		}
		if ((((*t_flags).flags & (FLAG_SPACE)) &&
		((*t_flags).flags & (FLAG_MINUS))) ||
		((*t_flags).minfw == (*t_flags).precision))
			(*t_pr).pad_len = (*t_flags).minfw - (*t_flags).precision - len;
	}
	if (diff > 0)
	{
		(*t_flags).special_chars_printed += diff;
		(*t_flags).total_chars_printed += diff;
	}
	while (diff > 0)
	{
		t_pr->writer(&"0", 1, t_pr);
		diff--;
	}
}
