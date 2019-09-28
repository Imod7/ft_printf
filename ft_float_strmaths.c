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
	while (pr[index] != 0)
	{
		index++;
		len++;
	}
	return (len);
}

void			str_divide_by_two(char *fr)
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
		// printf("fr[%d] = %c\n", index, fr[index]);
		if (fr[index] != 0)
			temp = fr[index] - '0';
		else
			temp = 0;
		// printf(ANSI_COLOR_CYAN"temp = %d\n"ANSI_COLOR_RESET, temp);
		temp = ((carry * 10) + temp) / 2;
		// printf(ANSI_COLOR_YELLOW"temp = %d\n"ANSI_COLOR_RESET, temp);
		carry = fr[index] % 2;
		// printf("carry = %d\n", carry);
		fr[index] = temp + '0';
		// printf(ANSI_COLOR_CYAN"fr[%d] = %d\n\n"ANSI_COLOR_RESET, index, temp);
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
	printf(ANSI_COLOR_MAGENTA"\nLength of Fraction=%d\n", len_fr);
	printf("Length of Product =%d"ANSI_COLOR_RESET, len_pr);
	index = len_pr;
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
	sum = (pr[5000] - '0') + (fr[0] - '0');
	pr[5000] = sum + '0';
	printf(ANSI_COLOR_GREEN"\nProduct  : ");
	print_product(pr);
}

void			str_double(short *pr)
{
	int			len;
	int			index;
	int			carry;
	int			sum;

	index = 2;
	carry = 0;
	len = length_product(pr);
	printf(ANSI_COLOR_YELLOW"\n----STr_double Start---\nProduct before dbl : ");
	print_product(pr);
	printf(ANSI_COLOR_YELLOW"\nLength  : %d", len);
	index = 5000 + len - 1;
	carry = 0;
	while (index > 5001)
	{
		sum = ((pr[index] - '0') * 2) + carry;
		// printf(ANSI_COLOR_MAGENTA"\nCurrent Sum : ");
		// printf("%d "ANSI_COLOR_RESET, sum);
		pr[index] = (sum % 10) + '0';
		// printf(ANSI_COLOR_MAGENTA"\npr[%d] = %d ", 5000 + index - 1, pr[5000 + index - 1]);
		// printf("%d "ANSI_COLOR_RESET, sum);
		carry = sum / 10;
		index--;
	}
	sum = ((pr[5000] - '0') * 2) + carry;
	// printf(ANSI_COLOR_MAGENTA"\nCurrent Sum : ");
	// printf("%d "ANSI_COLOR_RESET, sum);
	pr[5000] = (sum % 10) + '0';
	carry = sum / 10;
	printf(ANSI_COLOR_YELLOW"\npr[5000] = %c", pr[5000]);
	// printf("%d "ANSI_COLOR_RESET, sum);
	index = 5000 - 1;
	while (carry > 0 || (pr[index] != 0))
	{
		// printf(ANSI_COLOR_YELLOW"\nindex= %d , carry %d", index, carry);
		if (pr[index] == 0)
			pr[index] = '0';
		sum = ((pr[index] - '0') * 2) + carry;
		// printf(ANSI_COLOR_MAGENTA"\nCurrent Sum : ");
		// printf("%d "ANSI_COLOR_RESET, sum);
		pr[index] = (sum % 10) + '0';
		// printf(ANSI_COLOR_MAGENTA"\npr[%d] = %d ", 5000 + index - 1, pr[5000 + index - 1]);
		// printf("%d "ANSI_COLOR_RESET, sum);
		carry = sum / 10;
		index--;
	}
	printf(ANSI_COLOR_YELLOW"\nProduct after dbl :    ");
	print_product(pr);
	printf("\n");
}

