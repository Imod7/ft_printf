/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_unsigned.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 17:43:33 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/08/19 17:43:37 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void					print_number(unsigned long long arg, t_format *t_flags)
{
	if ((*t_flags).argtype == 'o')
		ft_putnbr_octal(arg, (*t_flags).fd);
	else if ((*t_flags).argtype == 'X')
		ft_putnbr_hex_capit(arg, (*t_flags).fd);
	else
		ft_putnbr_hex(arg, (*t_flags).fd);
}

void					pr_withminus(unsigned long long arg, t_format *t_flags, int len)
{
	// printf(ANSI_COLOR_YELLOW"\nFlag_MINUS=TRUE AND");
	if (((*t_flags).flags & FLAG_PRECIS) > 0)
	{
		// printf(ANSI_COLOR_YELLOW"\nFlag_PREC=TRUE\n");
		print_inverse(t_flags, len);
		print_number(arg, t_flags);
	}
	else if ((((*t_flags).flags & FLAG_NEGAT) == 0) && \
	(((*t_flags).flags & FLAG_SPACE) == 0) && \
	(((*t_flags).flags & FLAG_PRECIS) == 0))
	{
		// printf(ANSI_COLOR_YELLOW"\nFlag_Negat=FALSE && Flag_Space=FALSE\n");
		print_number(arg, t_flags);
		print_inverse(t_flags, len);
	}
	else if ((((*t_flags).flags & FLAG_NEGAT) > 0) && \
	(((*t_flags).flags & FLAG_SPACE) > 0))
	{
		// printf(ANSI_COLOR_YELLOW"\nFlag_Negat=TRUE && Flag_Space=TRUE\n");
		(*t_flags).flags &= ~FLAG_SPACE;
		print_sign(t_flags);
		print_number(arg, t_flags);
		print_padding(t_flags, len);
	}
	else
	{
		// printf(ANSI_COLOR_YELLOW"\nOther Cases\n");
		print_inverse(t_flags, len);
		print_number(arg, t_flags);
	}
}

void					check_ht(unsigned long long arg, t_format *t_flags)
{
	char				c;

	// printf("\n%d\n", (*t_flags).argtype);
	// print_binary((*t_flags).flags);
	if ((((*t_flags).argtype == 'o') > 0) && \
	((((*t_flags).flags & FLAG_PRECIS) > 0) || \
	(((*t_flags).flags & FLAG_HT) > 0)))
	{
		c = '0';
		// printf("check HT flag\n");
		write((*t_flags).fd, &c, 1);
		// (*t_flags).special_chars_printed++;
		(*t_flags).total_chars_printed++;
		// printf("\nspecial chars = %d\n", (*t_flags).special_chars_printed);
	}
	else
	{
		if ((((*t_flags).flags & FLAG_HT) > 0) && (arg != 0))
		{
			if (((*t_flags).argtype == 'x') || ((*t_flags).argtype == 'p'))
				write((*t_flags).fd, "0x", 2);
			else
				write((*t_flags).fd, "0X", 2);
			(*t_flags).total_chars_printed = (*t_flags).total_chars_printed + 2;
		// (*t_flags).special_chars_printed = (*t_flags).special_chars_printed + 2;
		}
	}
}

void					print_hex_octal(va_list argptr, t_format *t_flags)
{
	unsigned long long	arg;
	int					len;

	if ((*t_flags).argtype == 'p')
	{
		(*t_flags).flags |= FLAG_HT;
		arg = va_arg(argptr, unsigned long);
		(*t_flags).special_chars_printed = (*t_flags).special_chars_printed + 2;
	}
	else
	{
		arg = va_arg(argptr, unsigned long long);
		check_modif_un(&arg, t_flags);
	}
	check_plusflag(t_flags);
	(*t_flags).flags &= ~FLAG_PLUS;
	len = number_of_digits_un(arg, *t_flags);
	(*t_flags).total_chars_printed = (*t_flags).total_chars_printed + len;
	if ((*t_flags).minfw < (*t_flags).precision)
		(*t_flags).minfw = (*t_flags).precision;
	if (((*t_flags).flags & FLAG_MINUS) > 0)
	{
		(*t_flags).flags &= ~FLAG_ZERO;
		check_ht(arg, t_flags);
		pr_withminus(arg, t_flags, len);
	}
	else if (((*t_flags).flags & FLAG_ZERO) > 0)
	{
		check_ht(arg, t_flags);
		print_inverse(t_flags, len);
		print_number(arg, t_flags);
	}
	else if ((((*t_flags).flags & FLAG_MINUS) == 0) && \
	(((*t_flags).flags & FLAG_ZERO) == 0))
	{
		// printf(ANSI_COLOR_MAGENTA"\nFlag_Minus=FALSE AND Flag_Zero=FALSE");
		print_order(t_flags, len);
		check_ht(arg, t_flags);
		print_number(arg, t_flags);
	}
}
