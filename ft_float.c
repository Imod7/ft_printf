/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_float.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/24 11:33:11 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/09/24 11:33:14 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				initialization(char *fr, short *pr)
{
	size_t			index;

	fr[0] = '1';
	fr[1] = '.';
	fr[2] = '0';
	index = 3;
	while (index < 400)
	{
		fr[index] = 0;
		index++;
	}
	pr[5000] = '0';
	pr[5001] = '.';
	pr[5002] = '0';
	index = 0;
	while (index < 5000)
	{
		pr[index] = 0;
		index++;
	}
	index = 5003;
	while (index < 10000)
	{
		pr[index] = 0;
		index++;
	}
}

void				check_modifier_float(va_list argptr, t_float *fl, t_format *t_flags)
{
	if ((*t_flags).modifier == N)
		(*fl).f_num = va_arg(argptr, double);
	if ((*t_flags).modifier == l)
		(*fl).f_num = va_arg(argptr, double);
	else if ((*t_flags).modifier == L)
		(*fl).f_num = va_arg(argptr, long double);
}

void				exponent_calculation(short *pr, short exp)
{
	int				index;

	index = 0;
	if (exp < 0)
	{
		while (index < exp * (-1))
		{
			prod_divide_by_two(pr);
			index++;
		}
	}
	else if (exp > 0)
	{
		while (index < exp)
		{
			str_double(pr);
			index++;
		}
	}
}

void				ft_ftoa(va_list argptr, t_format *t_flags, t_float *fl, short *pr)
{
	char			fraction[400];
	int				index;
	unsigned long	bit;

	check_modifier_float(argptr, fl, t_flags);
	initialization(fraction, pr);
	index = 63;
	while (index >= 0)
	{
		bit = 1UL << index;
		if ((*fl).mantissa & bit)
			str_add_prod_frac(pr, fraction);
		frac_divide_by_two(fraction);
		index--;
	}
	if ((*fl).exponent[4] != 0)
	{
		if (((*fl).exponent[4] & (1 << 15)) > 0)
			(*t_flags).flags |= FLAG_NEGAT;
		(*fl).exponent[4] &= ~(1 << 15);
		(*fl).exponent[4] = (*fl).exponent[4] - 16383;
		exponent_calculation(pr, (*fl).exponent[4]);
	}
	else if ((*fl).exponent[4] == 0)
		pr[5003] = 0;
	if (((*t_flags).flags & FLAG_NEGAT) > 0)
	{
		(*t_flags).total_chars_printed++;
		write((*t_flags).fd, "-", 1);
	}
}
