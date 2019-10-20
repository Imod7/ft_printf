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
	else if (((*t_flags).precision < (*t_flags).minfw) && \
	(!((*t_flags).flags & (FLAG_HT))) &&
	((*t_flags).argtype != 'o') &&
	(!((*t_flags).flags & (FLAG_ZERO))))
	{
		// printf(ANSI_COLOR_YELLOW"\nminfw - precision\n");
		(*tprnt).pad_len = (*t_flags).minfw - (*t_flags).precision;
	}
	else if (((*t_flags).precision <= (*t_flags).minfw) && \
	((((*t_flags).flags & (FLAG_HT))  &&
	((*t_flags).argtype == 'o')) ||
	((*t_flags).flags & (FLAG_ZERO))))
	{
		(*tprnt).pad_len = (*t_flags).minfw - *len;
		// printf(ANSI_COLOR_YELLOW"\nminfw - len\n");
	}
	// else if (((*t_flags).precision < (*t_flags).minfw) && \
	// ((*t_flags).flags & (FLAG_ZERO)))
	// 	(*tprnt).pad_len = (*t_flags).minfw - *len;
	// else if ((*t_flags).precision != 0)
	// 	(*tprnt).pad_len = (*t_flags).minfw - *len;
	else
	{
		// printf(ANSI_COLOR_YELLOW"it gets here?\n");
		(*tprnt).pad_len = (*t_flags).minfw;
	}
}

void	length_precision_diff_zeros(t_format *t_flags, t_print *t_pr, int len)
{
	int	diff;

	// if (((*t_flags).minfw != 0) && ((*t_flags).precision != 0))
	if (((*t_flags).minfw != 0) && ((*t_flags).precision < (*t_flags).minfw) &&
	(!((*t_flags).flags & (FLAG_HT))))
	{
		// printf("\nprecision < minfw , pad  = %d\n", (*t_pr).pad_len);
		diff = (*t_flags).minfw - (*t_pr).pad_len;
	}
	else if (((*t_flags).minfw == 0) && ((*t_flags).precision != 0))
		diff = (*t_flags).precision;
	else
	{
		// printf("\nother\n");
		diff = (*t_flags).precision - (*t_pr).pad_len - \
		(*t_flags).special_chars_printed - len;
	}
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
