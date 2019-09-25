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

void			print_bin(uint64_t mant)
{
	int			bit;
	int			pos;

	pos = 0;
	while (pos <= 64)
	{
		bit = mant << pos;
		if (bit & 1)
			printf("1 ");
		else
			printf("0 ");
		pos++;
	}
}

// void			initialize_fraction(char *fr)
// {
// 	int			index;

// 	index = 2;
// 	fr[0] = '1';
// 	fr[1] = '.';
// 	while (index < 400)
// 	{
// 		fr[index] = '0';
// 		index++;
// 	}
// }

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

void			str_add(short *pr, char *fr)
{
	pr[0] = '1';
	fr[0] = '0';
}

void			ft_ftoa(va_list argptr, t_format *t_flags)
{
	t_float		fl_num;
	char		fraction[400];
	short		product[10000];
	int			temp;

	printf("\nflag = %d\n", (*t_flags).flags);
	// initialize_fraction(fraction);
	fraction[0] = '1';
	fraction[1] = '.';
	fraction[2] = '0';
	product[5000] = '0';
	product[5001] = '.';
	product[5002] = '0';
	fl_num.f_num = va_arg(argptr, long double);
	// while (fl_num.mantissa > 0)
	temp = 0;
	while (temp < 10)
	{
		printf("\nmantissa = %llu\n", fl_num.mantissa);
		print_bin(fl_num.mantissa);
		if (fl_num.mantissa & 1)
			str_add(product, fraction);
		printf("\nfraction : ");
		print_fraction(fraction);
		printf("\n");
		str_divide_by_two(fraction);
		fl_num.mantissa = fl_num.mantissa << 1;
		temp++;
	}
}
