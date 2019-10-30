/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_float_addition.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 14:12:32 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/09/26 14:12:34 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int				length_product_decpart(short *pr)
{
	size_t		index;
	int			len;

	index = 5002;
	len = 0;
	while (pr[index] != 0)
	{
		index++;
		len++;
	}
	return (len);
}

void			frac_divide_by_two(char *fr)
{
	int			temp;
	int			len;
	int			index;
	int			carry;

	index = 2;
	carry = 0;
	len = ft_strlen(fr);
	if (fr[0] == '1')
	{
		fr[0] = '0';
		carry = 1;
	}
	while (index <= len)
	{
		if (fr[index] != 0)
			temp = fr[index] - '0';
		else
			temp = 0;
		temp = ((carry * 10) + temp) / 2;
		carry = fr[index] % 2;
		fr[index] = temp + '0';
		index++;
	}
}

void			str_add_prod_frac(short *pr, char *fr)
{
	int			len_pr;
	int			len_fr;
	int			index;
	int			sum;
	int			carry;

	len_pr = length_product(pr);
	len_fr = length_fraction(fr);
	index = len_pr;
	while (index < len_fr)
	{
		pr[5000 + index] = '0';
		index++;
	}
	index = len_fr;
	carry = 0;
	while (index > 2)
	{
		sum = (pr[5000 + index - 1] - '0') + (fr[index - 1] - '0') + carry;
		pr[5000 + index - 1] = (sum % 10) + '0';
		carry = sum / 10;
		index--;
	}
	if (carry > 0)
	{
		sum = (pr[5000] - '0');
		sum++;
		pr[5000] = sum + '0';
	}
	sum = (pr[5000] - '0') + (fr[0] - '0');
	pr[5000] = sum + '0';
}

void			str_double(short *pr)
{
	int			index;
	int			carry;
	int			sum;

	index = 5000 + length_product_decpart(pr);
	carry = 0;
	while (index >= 5002)
	{
		sum = ((pr[index] - '0') * 2) + carry;
		pr[index] = (sum % 10) + '0';
		carry = sum / 10;
		index--;
	}
	sum = ((pr[5000] - '0') * 2) + carry;
	pr[5000] = (sum % 10) + '0';
	carry = sum / 10;
	index = 5000 - 1;
	while (carry > 0 || (pr[index] != 0))
	{
		if (pr[index] == 0)
			pr[index] = '0';
		sum = ((pr[index] - '0') * 2) + carry;
		pr[index] = (sum % 10) + '0';
		carry = sum / 10;
		index--;
	}
}

void			prod_divide_by_two(short *pr)
{
	int			temp;
	int			len;
	int			index;
	int			carry;

	index = 2;
	carry = 0;
	len = 5000 + length_product(pr);
	index = 5002;
	if (pr[5000] == '1')
	{
		pr[5000] = '0';
		carry = 1;
	}
	while (index <= len)
	{
		if (pr[index] != 0)
			temp = pr[index] - '0';
		else
			temp = 0;
		temp = ((carry * 10) + temp) / 2;
		carry = pr[index] % 2;
		pr[index] = temp + '0';
		index++;
	}
}
