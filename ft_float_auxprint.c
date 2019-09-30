/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_float_auxprint.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 14:49:46 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/09/26 14:49:48 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_mantissa_inorder(uint64_t mant)
{
	int			bit;
	int			pos;

	pos = 0;
	while (pos <= 63)
	{
		bit = mant >> pos;
		if (bit & 1)
			printf(ANSI_COLOR_CYAN"1 "ANSI_COLOR_RESET);
		else
			printf(ANSI_COLOR_YELLOW"0 "ANSI_COLOR_RESET);
		pos++;
	}
}

void			print_mantissa_inreverse(uint64_t mant)
{
	int			bit;
	int			pos;

	pos = 63;
	while (pos >= 0)
	{
		bit = mant >> pos;
		if (bit & 1)
			printf(ANSI_COLOR_CYAN"1 "ANSI_COLOR_RESET);
		else
			printf(ANSI_COLOR_YELLOW"0 "ANSI_COLOR_RESET);
		pos--;
	}
}

void			print_exponent_binary(short exp)
{
	int			bit;
	int			pos;

	pos = 15;
	while (pos >= 0)
	{
		bit = exp >> pos;
		if (bit & 1)
			printf(ANSI_COLOR_CYAN"1 "ANSI_COLOR_RESET);
		else
			printf(ANSI_COLOR_YELLOW"0 "ANSI_COLOR_RESET);
		pos--;
	}
}

void			print_fraction(char *fr)
{
	int			len;
	int			index;

	len = ft_strlen(fr);
	index = 2;
	printf(ANSI_COLOR_CYAN"%c%c"ANSI_COLOR_RESET, fr[0], fr[1]);
	while (index < len)
	{
		printf(ANSI_COLOR_CYAN"%c"ANSI_COLOR_RESET, fr[index]);
		index++;
	}
}

void			print_product(short *pr)
{
	int			index;

	index = 0;
	while (pr[index] == 0)
		index++;
	while (pr[index] != 0)
	{
		printf(ANSI_COLOR_CYAN"%c"ANSI_COLOR_RESET, pr[index]);
		index++;
	}
}

void			print_final_float(short *pr, t_format *t_flags)
{
	int			index;

	index = 0;
	while (pr[index] == 0)
		index++;
	while (pr[index] != 0)
	{
		// printf(ANSI_COLOR_CYAN"%c"ANSI_COLOR_RESET, pr[index]);
		write((*t_flags).fd, &pr[index], 1);
		index++;
	}
}
