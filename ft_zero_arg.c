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

void	check_arg_zero(t_format *t_flags, int *len, t_print *t_prnt)
{
	*len = *len;
	// printf(ANSI_COLOR_BLUE"check_arg_zero function\n");
	t_flags->flags |= FLAG_ARG_ZERO;
	if (t_flags->precision > t_flags->minfw)
		t_prnt->pad_len = -1;
	else if ((t_flags->precision < t_flags->minfw) && \
	(t_flags->argtype == 'p'))
	// (!(t_flags->flags & (FLAG_PRECIS))))
	{
		t_prnt->pad_len = t_flags->minfw - t_flags->special_chars_printed -
		*len;
		// printf(ANSI_COLOR_BLUE"%d %d %d\n", t_flags->minfw, t_flags->special_chars_printed, *len);
	}
		
	else if ((t_flags->precision < t_flags->minfw) && \
	(!(t_flags->flags & (FLAG_HT))) &&
	(t_flags->precision != 0) && \
	(!(t_flags->flags & (FLAG_ZERO))))
	{
		t_prnt->pad_len = t_flags->minfw - t_flags->precision;
		// printf("t_prnt->pad_len = %d\n", t_prnt->pad_len);
	}
	// else if ((t_flags->precision <= t_flags->minfw) && \
	// (((t_flags->flags & (FLAG_HT)) &&
	// (t_flags->argtype == 'o'))
	// || (t_flags->flags & (FLAG_ZERO))))
	// {
	// 	t_prnt->pad_len = t_flags->minfw - *len;
	// 	printf(ANSI_COLOR_MAGENTA"pad = %d\n", t_prnt->pad_len);
	// }
	// else
	// 	t_prnt->pad_len = t_flags->minfw;
	if (t_flags->flags & (FLAG_PLUS) && (!(t_prnt->pad_len)))
		t_prnt->pad_len = t_flags->minfw - 1;
	else if (t_flags->flags & (FLAG_PLUS) && (t_prnt->pad_len))
		t_prnt->pad_len -= 1;
	if (t_flags->flags & FLAG_SPACE)
		t_prnt->pad_len = 0;
	// printf(ANSI_COLOR_BLUE">>/pad = %d\n"ANSI_COLOR_RESET, t_prnt->pad_len);
}

void	length_diff_zeros_unsigned(t_format *t_flags, t_print *t_prnt, int len,\
									int *diff)
{
	// printf(ANSI_COLOR_YELLOW"length_diff_zeros_unsigned function\n"ANSI_COLOR_RESET);
	if ((t_flags->minfw == t_flags->precision) && (t_flags->minfw != 0))
	{
		// printf(ANSI_COLOR_YELLOW"MIN == PREC = pad%d min%d len%d\n"ANSI_COLOR_RESET, t_prnt->pad_len, t_flags->minfw, len);
		*diff = t_flags->precision;
	}
	else if ((t_flags->minfw == t_flags->precision) && \
	(t_flags->minfw == 0) &&
	(
	(!((t_flags->flags & (FLAG_PRECIS)) && t_flags->precision == 0) && \
	(t_flags->argtype == 'o')) || \
	(!((t_flags->flags & (FLAG_PRECIS))) && \
	(ft_strchr("di", t_flags->argtype) != 0)) || \
	(t_flags->flags & (FLAG_PLUS) && (t_flags->argtype == 'o')) ||
	((t_flags->flags & (FLAG_HT)) && (t_flags->argtype == 'o'))))
	{
		*diff = len;
		// printf(ANSI_COLOR_YELLOW"MIN == PREC min not zero = pad%d min%d len%d diff%d\n"ANSI_COLOR_RESET, t_prnt->pad_len, t_flags->minfw, len, *diff);
	}
	else if ((t_flags->minfw > t_flags->precision) && \
	(t_flags->minfw != 0))
	{
		// printf(ANSI_COLOR_YELLOW"MIN > PREC min not zero = pad%d min%d len%d diff%d\n"ANSI_COLOR_RESET, t_prnt->pad_len, t_flags->minfw, len, *diff);
		if ((t_flags->precision == 0) && (t_prnt->pad_len <= 0))
		{
			t_prnt->pad_len = t_flags->minfw - len;
		}
		else if ((t_flags->precision != 0) && (t_prnt->pad_len <= 0))
		{
			t_prnt->pad_len = t_flags->minfw - t_flags->precision;
		}
		if ((t_flags->flags & (FLAG_HT | FLAG_SPACE | FLAG_MINUS | FLAG_PLUS))
		&& ((t_flags->flags & (FLAG_PRECIS)))
		&& (t_flags->precision == 0) && \
		(ft_strchr("o", t_flags->argtype) == 0))
		{
			t_prnt->pad_len = 0;
			*diff = 0;
		}
		else
		{
			if ((t_flags->flags & (FLAG_PLUS)) && (t_prnt->sign_printed == 1))
				// *diff = t_flags->minfw - t_prnt->pad_len - 1;
				*diff = t_flags->precision;
			else if ((t_flags->flags & (FLAG_SPACE)) && (t_prnt->sign_printed == 1)
			&& (t_flags->flags & (FLAG_ZERO)))
			{
					// printf("GETS HERE");
					*diff = t_flags->minfw - t_prnt->pad_len - 1;
			}
			else
				*diff = t_flags->minfw - t_prnt->pad_len;
		}
	}
	else if (t_flags->minfw < t_flags->precision)
	{
		t_prnt->pad_len = 0;
		*diff = t_flags->precision;
	}
	else
	{
		*diff = t_flags->precision - t_prnt->pad_len - \
		t_flags->special_chars_printed - len;
		// printf(ANSI_COLOR_YELLOW".............................else case diff = %d\n"ANSI_COLOR_RESET, *diff);
	}
}

// void	diff_zeros_pointer(t_format *t_flags, t_print *t_prnt, int len,\
// 									int *diff)
// {

// }

void	length_precision_diff_zeros(t_format *t_flags, t_print *t_prnt, int len)
{
	int	diff;

	diff = 0;
	// if (t_prnt->diff != -1)
	// {
	// if (!(t_flags->flags & (FLAG_MINUS)))
	// (t_flags->argtype == 'u') &&
	// (t_flags->minfw == t_flags->precision)))
	length_diff_zeros_unsigned(t_flags, t_prnt, len, &diff);
	if ((t_flags->argtype == 'p') && (t_flags->precision != 0))
		diff = t_flags->precision;
	else if ((t_flags->argtype == 'p') && (t_flags->precision == 0))
	{
		diff = 0;
	}
	
	// 	diff_zeros_pointer(t_flags, t_prnt, len, &diff);
	// }
	if (diff > 0)
	{
		if ((t_flags->flags & (FLAG_SPACE)) && (t_prnt->sign_printed == 1))
		{
			t_prnt->pad_len = t_flags->minfw - diff - 1;
		}
		else
			t_prnt->pad_len = t_flags->minfw - diff;
		t_flags->special_chars_printed += diff;
	}
	// printf(ANSI_COLOR_YELLOW"length_precision_diff_zeros\ndiff = %d\nt_prnt->diff = %d\npad = %d\nt_flags->flags=%d, special_chars = %d\n"ANSI_COLOR_RESET, diff, t_prnt->diff, t_prnt->pad_len, t_flags->flags - 2048, t_flags->special_chars_printed);
	while (diff > 0)
	{
		t_prnt->writer(&"0", 1, t_prnt);
		diff--;
	}
}
