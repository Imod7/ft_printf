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
	pr[5002] = '9';
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

// void			strings_reverse(char *fr, int len_fr, short *pr, int len_pr)
// {
// 	int			begin;
// 	int			end;
// 	char		temp;

// 	begin = 2;
// 	end = len_fr + 1;
// 	while (begin < len_fr)
// 	{
// 		temp = fr[begin];
// 		fr[begin] = fr[end];
// 		fr[end] = temp;
// 		begin++;
// 		end--;
// 	}
// 	begin = 5002;
// 	end = len_pr + 5001;
// 	while (begin < end)
// 	{
// 		temp = pr[begin];
// 		pr[begin] = pr[end];
// 		pr[end] = temp;
// 		begin++;
// 		end--;
// 	}
// }

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
	// printf("temp = %d\n", temp);
	// fr[2] = temp;
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
	pos = 40;
	while (pos >= 0)
	// while (fl_num.mantissa > 0)
	{
		printf("\nmantissa in hex = %llx\n", fl_num.mantissa);
		printf("mantissa in binary = %llx\n", fl_num.mantissa);
		print_bin(fl_num.mantissa);
		if (fl_num.mantissa & 1)
		{
			printf("\n--- Mantissa Found Bit equal to 1 ---");
			printf("\nFraction : ");
			print_fraction(fraction);
			printf("\nProduct  : ");
			print_product(product);
			str_add_prod_frac(product, fraction);
		}
		str_divide_by_two(fraction);
		// I should shift to the left but then if 
		// fl_num.mantissa = fl_num.mantissa << 1;
		fl_num.mantissa = fl_num.mantissa >> 1;
		pos--;
	}
}
