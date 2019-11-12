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
	{
		(*tprnt).pad_len = -1;
		// printf("\n EDW panta ?");
	}
	else if ((((*t_flags).precision < (*t_flags).minfw) && \
	((*t_flags).argtype == 'p')) || \
	(!((*t_flags).flags & (FLAG_PRECIS))))
	{
		// printf("\n EDW tewra ?");
		(*tprnt).pad_len = (*t_flags).minfw - (*t_flags).special_chars_printed -
		*len;
	}
	else if (((*t_flags).precision < (*t_flags).minfw) && \
	(!((*t_flags).flags & (FLAG_HT))) &&
	// ((*t_flags).argtype != 'o') &&
	(!((*t_flags).flags & (FLAG_ZERO))))
	{
		// printf("\n EDW mipws ?");
		(*tprnt).pad_len = (*t_flags).minfw - (*t_flags).precision;
	}
	else if (((*t_flags).precision <= (*t_flags).minfw) && \
	((((*t_flags).flags & (FLAG_HT)) &&
	((*t_flags).argtype == 'o')) ||
	((*t_flags).flags & (FLAG_ZERO))))
		(*tprnt).pad_len = (*t_flags).minfw - *len;
	else
	{
		(*tprnt).pad_len = (*t_flags).minfw;
		// printf("\n EDW sto ELSE");
	}
	if ((*t_flags).flags & (FLAG_PLUS))
		(*tprnt).pad_len -= 1;
	if ((*t_flags).flags & FLAG_SPACE)
		(*tprnt).pad_len = 0;
}

void	length_precision_diff_zeros(t_format *t_flags, t_print *t_pr, int len)
{
	int	diff;

	// printf("EDW pad_len = %d\n", (*t_pr).pad_len);
	if ((*t_flags).minfw == (*t_flags).precision)
		diff = (*t_flags).precision - len;
	else if (((*t_flags).minfw != 0) && \
	((*t_flags).precision < (*t_flags).minfw) &&
	(!((*t_flags).flags & (FLAG_HT))) &&
	(!((*t_flags).flags & (FLAG_MINUS))))
	{
		diff = (*t_flags).minfw - (*t_pr).pad_len;
		// printf("\n >>> diff = %d", diff);
	}
	else if (((*t_flags).minfw == 0) || ((*t_flags).precision != 0))
	{
		diff = (*t_flags).precision;
		// printf("\n --- diff = %d", diff);
	}
	else
	{
		diff = (*t_flags).precision - (*t_pr).pad_len - \
		(*t_flags).special_chars_printed - len;
		// printf("\n ooooo diff = %d", diff);
	}
	if ((((*t_flags).flags & (FLAG_SPACE)) &&
	((*t_flags).flags & (FLAG_MINUS))) ||
	((*t_flags).minfw == (*t_flags).precision))
	{
		(*t_pr).pad_len = (*t_flags).minfw - (*t_flags).precision - len;
	}
	if (diff > 0)
	{
		(*t_flags).special_chars_printed += diff;
		(*t_flags).total_chars_printed += diff;
	}
	while (diff > 0)
	{
		// printf("\n edw tupwnei");
		write((*t_flags).fd, "0", 1);
		diff--;
		// if (!((*t_flags).flags & (FLAG_MINUS)))
		// 	(*t_pr).pad_len = -1;
		// 	(*t_pr).diff = -1;
		// printf("\n --- pad = %d", (*t_pr).pad_len);
	}
}
