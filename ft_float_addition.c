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

#include "ft_printf.h"

int				length_fraction(char *fr)
{
	size_t		index;
	int			len;

	index = 0;
	len = 0;
	// while (fr[index] != '.')
	// 	index++;
	// if (fr[index] == '.')
	// 	index++;
	while (fr[index] != 0)
	{
		index++;
		len++;
	}
	return (len);
}

int				length_product(short *pr)
{
	size_t		index;
	int			len;

	index = 5000;
	len = 0;
	// while (pr[index] != '.')
	// 	index++;
	// if (pr[index] == '.')
	// 	index++;
	while (pr[index] != 0)
	{
		index++;
		len++;
	}
	return (len);
}

void			str_add_prod_frac(short *pr, char *fr)
{
	int			len_pr;
	int			len_fr;
	// int			len;
	int			index;
	int			sum;
	int			carry;

	len_pr = length_product(pr);
	len_fr = length_fraction(fr);
	printf(ANSI_COLOR_MAGENTA"\nLength of Fraction = %d\n"ANSI_COLOR_RESET, len_fr);
	printf(ANSI_COLOR_MAGENTA"Length of Product  = %d\n"ANSI_COLOR_RESET, len_pr);
	index = len_pr;
	// len = len_fr;
	while (index < len_fr)
	{
		pr[5000 + index] = '0';
		index++;
	}
	printf("\nFraction : ");
	print_fraction(fr);
	printf("\nProduct  : ");
	print_product(pr);
	index = len_fr;
	carry = 0;
	while (index > 2)
	{
		sum = (pr[5000 + index - 1] - '0') + (fr[index - 1] - '0') + carry;
		// printf(ANSI_COLOR_MAGENTA"\nCurrent Sum : ");
		// printf("%d "ANSI_COLOR_RESET, sum);
		pr[5000 + index - 1] = (sum % 10) + '0';
		// printf(ANSI_COLOR_MAGENTA"\npr[%d] = %d ", 5000 + index - 1, pr[5000 + index - 1]);
		// printf("%d "ANSI_COLOR_RESET, sum);
		carry = sum / 10;
		index--;
	}
	if (carry > 0)
	{
		// printf("\npr[5000] = %c\n", pr[5000]);
		sum = (pr[5000] - '0');
		sum++;
		pr[5000] = sum + '0';
	}
	printf(ANSI_COLOR_GREEN"\nProduct  : ");
	print_product(pr);
}
