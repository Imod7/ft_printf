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
	// printf(ANSI_COLOR_BLUE"check_arg_zero function SET FLAG ARG ZERO, pad_len = %d\n", t_prnt->pad_len);
	t_flags->flags |= FLAG_ARG_ZERO;
	if (t_flags->precision > t_flags->minfw)
		t_prnt->pad_len = -1;
	else if ((t_flags->precision < t_flags->minfw) && \
	(t_flags->argtype == 'p'))
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
	if ((t_flags->flags & (FLAG_PLUS & FLAG_PRECIS)) && \
	(!(t_prnt->pad_len)))
		t_prnt->pad_len = t_flags->minfw - 1;
	else if (t_flags->flags & (FLAG_PLUS) && \
	(!(t_flags->flags & FLAG_PRECIS)) && (!(t_prnt->pad_len)))
		t_prnt->pad_len = t_flags->minfw - 2;
	else if (t_flags->flags & (FLAG_PLUS) && (t_prnt->pad_len))
		t_prnt->pad_len -= 1;
	if ((t_flags->flags & FLAG_SPACE) && \
	(t_flags->flags & FLAG_MINUS))
	{
		// t_prnt->pad_len = 0;
		if (t_flags->precision == 0)
			t_prnt->pad_len = t_flags->minfw - *len - 1;
		else
			t_prnt->pad_len = t_flags->minfw - t_flags->precision - 1;
		// t_flags->flags |= FLAG_PADLEN_SET;
		// printf(ANSI_COLOR_YELLOW"SPACE KAI MINUS\n");
	}
	// printf(ANSI_COLOR_BLUE">>pad = %d\n"ANSI_COLOR_RESET, t_prnt->pad_len);
}

void	minfw_equal_precision(t_format *t_flags, int len,\
							int *diff)
{
	if (t_flags->minfw != 0)
	{
		// printf(ANSI_COLOR_YELLOW"MIN == PREC = pad%d min%d len%d\n"ANSI_COLOR_RESET, t_prnt->pad_len, t_flags->minfw, len);
		*diff = t_flags->precision;
	}
	else if ((t_flags->minfw == 0) &&
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
}

void	minfw_bigger_precision(t_format *t_flags, t_print *t_prnt, int len,\
								int *diff)
{
	printf(ANSI_COLOR_YELLOW"minfw_bigger_precision %d %d\n"ANSI_COLOR_RESET, t_flags->precision, t_prnt->pad_len);
	if (t_prnt->pad_len <= 0)
	{
		if ((t_flags->precision == 0) && \
		((t_flags->argtype != 'o') ||
		(!((t_flags->argtype == 'o') && (t_flags->flags & FLAG_MINUS) &&
		((t_flags->flags & (FLAG_PRECIS)) > 0))) ||
		((t_flags->argtype == 'o') && (t_flags->flags & (FLAG_HT)))))
		{
			// printf(ANSI_COLOR_YELLOW"min - len \n"ANSI_COLOR_RESET);
			t_prnt->pad_len = t_flags->minfw - len;
		}
		else
			t_prnt->pad_len = t_flags->minfw - t_flags->precision;
	}
	if ((t_flags->flags & (FLAG_HT | FLAG_SPACE | FLAG_MINUS | FLAG_PLUS))
	&& ((t_flags->flags & (FLAG_PRECIS)))
	&& (t_flags->precision == 0) && \
	(ft_strchr("o", t_flags->argtype) == 0))
	{
		// printf(ANSI_COLOR_YELLOW"HERE \n"ANSI_COLOR_RESET);
		t_prnt->pad_len = 0;
		*diff = 0;
	}
	else
	{
		if (((t_flags->flags & (FLAG_PLUS | FLAG_SPACE)) && \
		(t_flags->flags & FLAG_PRECIS)) ||
		((t_flags->flags & FLAG_HT) && (ft_strchr("xX", t_flags->argtype) > 0)))
		{
			// printf(ANSI_COLOR_YELLOW"Set pad = prec ??? \n"ANSI_COLOR_RESET);
			*diff = t_flags->precision;
		}
		else if (((t_flags->flags & (FLAG_PLUS | FLAG_HT | FLAG_SPACE)) ||
		(((t_flags->flags & NOFLAGS_MASK) == 0) && \
		(ft_strchr("xX", t_flags->argtype) != 0))) && \
		(!(t_flags->flags & (FLAG_PRECIS))))
		{
			// printf(ANSI_COLOR_YELLOW"here edw \n"ANSI_COLOR_RESET);
			if (((t_flags->flags & FLAG_HT) && (t_flags->argtype == 'o')) ||
			((t_flags->flags & FLAG_SPACE) && (!(t_flags->flags & FLAG_ZERO)) && \
			(ft_strchr("di", t_flags->argtype) > 0)))
			{
				*diff = t_flags->minfw - t_prnt->pad_len;
				// printf(ANSI_COLOR_YELLOW"mallon edw \n"ANSI_COLOR_RESET);
			}
			else
			{
				// printf(ANSI_COLOR_YELLOW"EDW \n"ANSI_COLOR_RESET);
				*diff = t_flags->minfw - t_prnt->pad_len - 1;
			}
		}
		else
		{
			// if ((t_flags->flags & FLAG_HT) && (t_flags->argtype == 'o'))
			// {
			// 	printf(ANSI_COLOR_YELLOW"LAST ELSE octal--- "ANSI_COLOR_RESET);
			// 	*diff = 1;
			// 	t_prnt->pad_len--;
			// }
			// else
			// {
				// printf(ANSI_COLOR_YELLOW"LAST ELSE--- "ANSI_COLOR_RESET);
				*diff = t_flags->minfw - t_prnt->pad_len;
			// }
		}
	}
}

void	length_diff_zeros_unsigned(t_format *t_flags, t_print *t_prnt, int len,\
									int *diff)
{
	// printf(ANSI_COLOR_YELLOW"length_diff_zeros_unsigned function\n"ANSI_COLOR_RESET);
	if (t_flags->minfw == t_flags->precision)
		minfw_equal_precision(t_flags, len, diff);
	else if (t_flags->minfw > t_flags->precision)
		minfw_bigger_precision(t_flags, t_prnt, len, diff);
	else if (t_flags->minfw < t_flags->precision)
	{
		t_prnt->pad_len = 0;
		*diff = t_flags->precision;
	}
}

void	print_padding_with_zeros(t_format *t_flags, t_print *t_prnt, int len)
{
	int	diff;

	diff = 0;
	length_diff_zeros_unsigned(t_flags, t_prnt, len, &diff);
	if ((t_flags->argtype == 'p') && (t_flags->precision != 0))
		diff = t_flags->precision;
	else if ((t_flags->argtype == 'p') && (t_flags->precision == 0))
	{
		diff = 0;
	}
	if (diff > 0)
	{
		if ((t_flags->flags & FLAG_SPACE) && \
			(t_flags->flags & FLAG_MINUS) && (t_flags->precision == 0))
			diff -= 1;
		// if ((t_flags->flags & (FLAG_SPACE)) && (t_prnt->sign_printed == 1) && \
		// (!(t_prnt->pad_len)))
		// {
		// 	printf("space on \n");
		// 	t_prnt->pad_len = t_flags->minfw - diff - 1;
		// 	if ((t_flags->flags & FLAG_SPACE) > 0 &&
		// 	(t_flags->flags & FLAG_ZERO) && \
		// 	(!(t_flags->flags & (FLAG_PRECIS))))
		// 		diff -= 1;
		// }
		// else if ((!(t_flags->flags & FLAG_SPACE)) && \
		// (t_prnt->sign_printed == 1) && (!(t_prnt->pad_len)))
		// {
		// 	// printf("space on ELSE\n");
		// 	t_prnt->pad_len = t_flags->minfw - diff;
		// }
		t_flags->special_chars_printed += diff;
	}
	// printf(ANSI_COLOR_YELLOW"===print_extra_zeros===\ndiff = %d\nt_prnt->diff = %d\npad = %d\nt_flags->flags=%d, special_chars = %d\n"ANSI_COLOR_RESET, diff, t_prnt->diff, t_prnt->pad_len, t_flags->flags, t_flags->special_chars_printed);
	while (diff > 0)
	{
		t_prnt->writer(&"0", 1, t_prnt);
		diff--;
	}
}
