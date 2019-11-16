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

#include "includes/ft_printf.h"

void		zero_prec_rounding(short *pr, int prec_index)
{
	int		current_digit;
	int		next_digit;
	int		carry;

	current_digit = pr[FLOAT_MIDDLE - prec_index - 1] - '0';
	next_digit = pr[FLOAT_MIDDLE + prec_index + 1] - '0';
	if (next_digit > 5)
		current_digit++;
	else if (next_digit == 5)
	{
		if (current_digit % 2 == 1)
			current_digit++;
	}
	pr[FLOAT_MIDDLE - prec_index - 1] = (current_digit % 10) + '0';
	carry = current_digit / 10;
	if (current_digit % 10 == 0)
	{
		prec_index--;
		if (pr[FLOAT_MIDDLE + prec_index - 1] == 0)
			pr[FLOAT_MIDDLE + prec_index - 1] = '0';
		current_digit = pr[FLOAT_MIDDLE + prec_index - 1] - '0';
		pr[FLOAT_MIDDLE + prec_index - 1] = (current_digit % 10) + '0' + carry;
	}
	pr[FLOAT_MIDDLE] = 0;
}

void		dec_part_rounding(short *pr, int prec_index)
{
	int		current_digit;
	int		carry;

	carry = 0;
	current_digit = (pr[FLOAT_MIDDLE + prec_index] - '0') + 1;
	while ((current_digit % 10 == 0) && (prec_index > 0))
	{
		pr[FLOAT_MIDDLE + prec_index] = (current_digit % 10) + '0';
		carry = current_digit / 10;
		prec_index--;
		current_digit = (pr[FLOAT_MIDDLE + prec_index] - '0') + 1;
	}
	if ((carry != 0) && (prec_index == 0))
	{
		current_digit = (pr[(FLOAT_MIDDLE - 1) + prec_index] - '0') + 1;
		pr[(FLOAT_MIDDLE - 1) + prec_index] = (current_digit % 10) + '0';
	}
	else
	{
		pr[FLOAT_MIDDLE + prec_index] = (current_digit % 10) + '0';
		current_digit = (pr[FLOAT_MIDDLE + prec_index] - '0') + 1;
	}
}

void		equal_five(short *pr, int prec_index)
{
	int		temp;
	int		carry;

	carry = 0;
	temp = (pr[FLOAT_MIDDLE + prec_index] - '0') + 1;
	if (((temp - 1) >= 5) && (temp != 10))
		pr[FLOAT_MIDDLE + prec_index] = temp + '0';
	while ((temp % 10 == 0) && (prec_index > 0))
	{
		pr[FLOAT_MIDDLE + prec_index] = (temp % 10) + '0';
		carry = temp / 10;
		prec_index--;
		temp = (pr[FLOAT_MIDDLE + prec_index] - '0') + 1;
	}
	if (carry != 0)
		pr[FLOAT_MIDDLE + prec_index] = temp + '0';
}

void		len_bigger_than_prec(short *pr, t_format *t_flags)
{
	int		next_digit;

	next_digit = (pr[FLOAT_MIDDLE + (*t_flags).precision + 1] - '0');
	if ((next_digit > 5) && ((*t_flags).precision != 0))
		dec_part_rounding(pr, (*t_flags).precision);
	else if ((next_digit < 5) && ((*t_flags).precision != 0))
		pr[FLOAT_MIDDLE + (*t_flags).precision + 1] = 0;
	else if ((next_digit == 5) && ((*t_flags).precision != 0))
		equal_five(pr, (*t_flags).precision);
	else if ((*t_flags).precision == 0)
		zero_prec_rounding(pr, (*t_flags).precision);
	pr[FLOAT_MIDDLE + (*t_flags).precision + 1] = 0;
}

void		check_precision(short *pr, t_format *t_flags)
{
	int		prec_index;
	int		current_digit;
	int		len;
	int		temp;

	current_digit = 0;
	if (((*t_flags).flags & FLAG_PRECIS) == 0)
		(*t_flags).precision = 6;
	temp = FLOAT_MIDDLE + 1;
	while (pr[temp] != 0)
		temp++;
	len = temp - (FLOAT_MIDDLE + 1);
	if (len < (*t_flags).precision)
	{
		prec_index = 1;
		while (prec_index <= ((*t_flags).precision - len))
		{
			pr[FLOAT_MIDDLE + len + prec_index] = '0';
			prec_index++;
		}
		pr[FLOAT_MIDDLE + len + prec_index] = 0;
	}
	else
		len_bigger_than_prec(pr, t_flags);
}
