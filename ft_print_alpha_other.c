/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_other.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 17:48:09 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/08/19 17:48:14 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		print_string(va_list argptr, t_format *t_flags, t_print *t_prnt)
{
	char	*arg;
	int		len;

	arg = va_arg(argptr, char *);
	if (arg == NULL)
	{
		write((*t_flags).fd, "(null)", 6);
		(*t_flags).total_chars_printed = (*t_flags).total_chars_printed + 6;
	}
	else
	{
		len = ft_strlen(arg);
		print_sign(t_flags, t_prnt);
		if ((((*t_flags).precision < len) && ((*t_flags).precision != 0) \
		&& (len != 0)) || (((*t_flags).flags & FLAG_PRECIS) &&
		((*t_flags).precision == 0)))
			len = (*t_flags).precision;
		(*t_flags).total_chars_printed = (*t_flags).total_chars_printed + len;
		if (((*t_flags).flags & FLAG_MINUS) > 0)
		{
			if (((*t_flags).flags & FLAG_PRECIS) && ((*t_flags).precision == 0))
				;
			else
				write((*t_flags).fd, arg, len);
			if (((*t_flags).minfw != 0) && \
			((*t_flags).minfw != (*t_flags).precision))
				print_padding(t_flags, t_prnt, len);
		}
		else
		{
			if (((*t_flags).minfw != 0) && \
			((*t_flags).minfw != (*t_flags).precision))
				print_padding(t_flags, t_prnt, len);
			if (((*t_flags).flags & FLAG_PRECIS) && ((*t_flags).precision == 0))
				;
			else
				write((*t_flags).fd, arg, len);
		}
	}
}

void		print_char(va_list argptr, t_format *t_flags, t_print *t_prnt)
{
	char	arg;
	int		len;

	arg = va_arg(argptr, int);
	len = 1;
	(*t_flags).total_chars_printed++;
	(*t_flags).flags &= ~FLAG_PLUS;
	(*t_flags).flags &= ~FLAG_SPACE;
	if ((*t_flags).flags & FLAG_MINUS)
	{
		write((*t_flags).fd, &arg, 1);
		print_sign(t_flags, t_prnt);
		print_padding(t_flags, t_prnt, len);
	}
	else
	{
		print_sign(t_flags, t_prnt);
		print_padding(t_flags, t_prnt, len);
		write((*t_flags).fd, &arg, 1);
	}
}

void		print_other(char arg, t_format *t_flags, t_print *t_prnt)
{
	int		len;

	len = 1;
	(*t_flags).flags &= ~FLAG_SPACE;
	(*t_flags).total_chars_printed++;
	if (((*t_flags).flags & FLAG_MINUS) > 0)
	{
		write((*t_flags).fd, &arg, 1);
		print_sign(t_flags, t_prnt);
		print_padding(t_flags, t_prnt, len);
	}
	else
	{
		print_sign(t_flags, t_prnt);
		print_padding(t_flags, t_prnt, len);
		write((*t_flags).fd, &arg, 1);
	}
}
