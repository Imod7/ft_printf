/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_float_round.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/29 22:31:49 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/09/29 22:31:50 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		zero_prec_rounding(short *pr, int prec_index)
{
	int		current_digit;
	int		next_digit;

	current_digit = pr[5001 - prec_index - 1] - '0';
	next_digit = pr[5001 + prec_index + 1] - '0';
	if (next_digit > 5)
		current_digit++;
	else if (next_digit == 5)
	{
		if (current_digit % 2 == 1)
			current_digit++;
	}
	pr[5001 - prec_index - 1] = (current_digit % 10) + '0';
	pr[5001] = 0;
}

void		dec_part_rounding(short *pr, int prec_index)
{
	int		current_digit;

	current_digit = (pr[5001 + prec_index] - '0') + 1;
	// printf("\n >>>>> pr[5001 + %d] = %d\n", prec_index, current_digit);
	while ((current_digit % 10 == 0) && (prec_index > 0))
	{
		pr[5001 + prec_index] = (current_digit % 10) + '0';
		// printf("\n >> prec_index = %d\n", prec_index);
		// printf("\n   >> next digit pr[5001 + %d] = %d\n", prec_index, current_digit);
		// printf("\n   >> pr[5001 + %d] = %c\n", prec_index, pr[5001 + prec_index]);
		prec_index--;
		current_digit = (pr[5001 + prec_index] - '0') + 1;
	}
	// current_digit = (pr[5001 + prec_index] - '0') + 1;
	if ((current_digit % 10 == 0) && (prec_index == 0))
	{
		pr[5001 - prec_index] = (current_digit % 10) + '0';
	}
	else
	{
		pr[5001 + prec_index] = (current_digit % 10) + '0';
		current_digit = (pr[5001 + prec_index] - '0') + 1;
	}
}

void		equal_five(short *pr, int prec_index)
{
	int		current_digit;

	current_digit = (pr[5001 + prec_index] - '0') + 1;
	// printf("\n >>>>> pr[5001 + %d] = %d\n", prec_index, current_digit);
	while ((current_digit % 10 == 0) && (prec_index > 0))
	{
		pr[5001 + prec_index] = (current_digit % 10) + '0';
		// printf("\n >> prec_index = %d\n", prec_index);
		// printf("\n   >> next digit pr[5001 + %d] = %d\n", prec_index, current_digit);
		// printf("\n   >> pr[5001 + %d] = %c\n", prec_index, pr[5001 + prec_index]);
		prec_index--;
		current_digit = (pr[5001 + prec_index] - '0') + 1;
	}
	// current_digit = (pr[5001 + prec_index] - '0') + 1;
	if ((current_digit % 10 == 0) && (prec_index == 0))
	{
		pr[5001 - prec_index] = (current_digit % 10) + '0';
	}
}

void		check_precision(short *pr, t_format *t_flags)
{
	int		prec_index;
	int		next_digit;
	int		current_digit;
	int		len;
	int		temp;

	current_digit = 0;
	if (((*t_flags).flags & FLAG_PRECIS) == 0)
		(*t_flags).precision = 6;
	temp = 5002;
	len = 0;
	while (pr[temp] != 0)
	{
		len++;
		temp++;
	}
	if (len < (*t_flags).precision)
	{
		prec_index = 1;
		while (prec_index <= ((*t_flags).precision - len))
		{
			pr[5001 + len + prec_index] = '0';
			prec_index++;
		}
		pr[5001 + len + prec_index] = 0;
	}
	else
	{
		next_digit = (pr[5001 + (*t_flags).precision + 1] - '0');
		// printf("\n next digit = %d\n", next_digit);
		if ((next_digit > 5) && ((*t_flags).precision != 0))
			dec_part_rounding(pr, (*t_flags).precision);
		else if ((next_digit < 5) && ((*t_flags).precision != 0))
			pr[5001 + (*t_flags).precision + 1] = 0;
		else if (next_digit == 5)
			equal_five(pr, (*t_flags).precision);
		else if ((*t_flags).precision == 0)
			zero_prec_rounding(pr, (*t_flags).precision);
		pr[5001 + (*t_flags).precision + 1] = 0;
	}
}
