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

#include "includes/ft_printf.h"

void				initialization(char *fr, short *pr)
{
	size_t			index;

	index = 0;
	while (index < 400)
	{
		fr[index] = 0;
		index++;
	}
	fr[0] = '1';
	fr[1] = '.';
	fr[2] = '0';
	index = 0;
	while (index < FLOAT_TOTAL_LEN)
	{
		pr[index] = 0;
		index++;
	}
	pr[FLOAT_MIDDLE - 1] = '0';
	pr[FLOAT_MIDDLE] = '.';
	pr[FLOAT_MIDDLE + 1] = '0';
}

void				check_modifier_float(va_list argptr, t_float *fl, \
t_format *t_flags)
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

void				exponent_check(t_format *tfl, t_float *fl, short *pr)
{
	if ((*fl).exponent[4] != 0)
	{
		if (((*fl).exponent[4] & (1 << 15)) > 0)
			(*tfl).flags |= FLAG_NEGAT;
		(*fl).exponent[4] &= ~(1 << 15);
		(*fl).exponent[4] = (*fl).exponent[4] - 16383;
		exponent_calculation(pr, (*fl).exponent[4]);
	}
	else if ((*fl).exponent[4] == 0)
		pr[FLOAT_MIDDLE + 2] = 0;
}

int					ft_ftoa(t_format *flags, t_print *tprnt, \
							t_float *float_num, short *pr)
{
	char			fraction[400];
	int				index;
	unsigned long	bit;
	int				inf_nan;

	initialization(fraction, pr);
	index = 63;
	while (index >= 0)
	{
		bit = 1UL << index;
		if ((*float_num).mantissa & bit)
			str_add_prod_frac(pr, fraction);
		frac_divide_by_two(fraction);
		index--;
	}
	inf_nan = check_inf_nan(float_num, tprnt, pr);
	if ((inf_nan == -1) || (inf_nan == 1))
		return (inf_nan);
	exponent_check(flags, float_num, pr);
	return (0);
}
