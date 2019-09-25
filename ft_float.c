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

void			initialization(char *fr, short *pr)
{
	size_t		index;

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
	pr[5002] = '8';
	pr[5003] = '5';
	index = 0;
	while (index < 5000)
	{
		pr[index] = 0;
		index++;
	}
	index = 5004;
	while (index < 10000)
	{
		pr[index] = 0;
		index++;
	}
}

int			find_len_fr_dotpart(char *fr, size_t right)
{
	size_t		index;
	int			len;

	index = 0;
	len = 0;
	while (fr[index] != '.')
		index++;
	if (fr[index] == '.')
		index++;
	while (fr[index] != 0)
	{
		if (right == 1)
			index++;
		else
			index--;
		len++;
	}
	return (len);
}

int			find_len_pr_dotpart(short *pr, size_t right)
{
	size_t		index;
	int			len;

	index = 0;
	len = 0;
	while (pr[index] != '.')
		index++;
	if (pr[index] == '.')
		index++;
	while (pr[index] != 0)
	{
		// printf("\npr[index] = %c\n", pr[index]);
		if (right == 1)
			index++;
		else
			index--;
		len++;
	}
	return (len);
}

void			print_bin(uint64_t mant)
{
	int			bit;
	int			pos;

	pos = 64;
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

void			print_product(short *pr, int len)
{
	int			index;

	index = 0;
	printf(ANSI_COLOR_CYAN"%c%c"ANSI_COLOR_RESET, pr[5000], pr[5001]);
	// printf("\nproduct len = %d, index = %d\n", len, index);
	while (index < len)
	{
		printf(ANSI_COLOR_CYAN"%c"ANSI_COLOR_RESET, pr[5002 + index]);
		index++;
	}
}

void			strings_reverse(char *fr, int len_fr, short *pr, int len_pr)
{
	int			begin;
	int			end;
	char		temp;

	begin = 2;
	end = len_fr + 1;
	while (begin < len_fr)
	{
		temp = fr[begin];
		fr[begin] = fr[end];
		fr[end] = temp;
		begin++;
		end--;
	}
	begin = 5002;
	end = len_pr + 5001;
	while (begin < end)
	{
		temp = pr[begin];
		pr[begin] = pr[end];
		pr[end] = temp;
		begin++;
		end--;
	}
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
	// printf("len = %d\n", len);
	// if (len == 3)
	// 	temp = 10;
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
	// printf("temp = %d\n", temp);
	// fr[2] = temp;
}

void			str_add_prod_frac(short *pr, char *fr)
{
	int			lenpr_right;
	int			lenfr_right;
	int			len;
	int			index;
	int			sum;
	// int			carry;

	lenpr_right = find_len_pr_dotpart(pr, 1);
	lenfr_right = find_len_fr_dotpart(fr, 1);
	printf(ANSI_COLOR_MAGENTA"Length of Product after dot = %d\n"ANSI_COLOR_RESET, lenpr_right);
	printf(ANSI_COLOR_MAGENTA"Length of Fraction after dot = %d\n"ANSI_COLOR_RESET, lenfr_right);
	if (lenpr_right > lenfr_right)
		len = lenfr_right;
	else
		len = lenpr_right;
	printf("Reverse strings\n");
	strings_reverse(fr, lenfr_right, pr, lenpr_right);
	printf("\nFraction Reversed: ");
	print_fraction(fr);
	printf("\nProduct Reversed : ");
	print_product(pr, lenpr_right);
	index = 0;
	while (index < len)
	{
		sum = (fr[1 + index] - '0') + (pr[5001 + index] - '0');
		index++;
	}
}

void			ft_ftoa(va_list argptr, t_format *t_flags)
{
	t_float		fl_num;
	char		fraction[400];
	short		product[10000];
	int			pos;

	printf("\nflag = %d\n", (*t_flags).flags);
	fl_num.f_num = va_arg(argptr, long double);
	// while (fl_num.mantissa > 0)
	initialization(fraction, product);
	printf(ANSI_COLOR_YELLOW"--- MANTISSA START ---"ANSI_COLOR_RESET);
	printf("\nmantissa in hex = %llx\n", fl_num.mantissa);
	printf("mantissa in binary = %llx\n", fl_num.mantissa);
	print_bin(fl_num.mantissa);
	pos = 30;
	while (pos >= 0)
	// while (fl_num.mantissa > 0)
	{
		// printf("\nmantissa in hex = %llx\n", fl_num.mantissa);
		// printf("mantissa in binary = %llx\n", fl_num.mantissa);
		// print_bin(fl_num.mantissa);
		if (fl_num.mantissa & 1)
		{
			printf("\n--- Mantissa Found Bit equal to 1 ---");
			printf("\nFraction : ");
			print_fraction(fraction);
			printf("\n");
			str_add_prod_frac(product, fraction);
			printf("\n");
		}
		str_divide_by_two(fraction);
		// I should shift to the left but then if 
		// fl_num.mantissa = fl_num.mantissa << 1;
		fl_num.mantissa = fl_num.mantissa >> 1;
		pos--;
	}
}
