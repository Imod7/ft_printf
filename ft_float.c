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

void		check_modifier_float(va_list argptr, t_float *fl, t_format *t_flags)
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

void				ft_ftoa(va_list argptr, t_format *t_flags)
{
	t_float			fl_num;
	char			fraction[400];
	short			product[10000];
	int				index;
	unsigned long	bit;

	// printf("\nflag = %d\n", (*t_flags).flags);
	// fl_num.f_num = va_arg(argptr, long double);
	check_modifier_float(argptr, &fl_num, t_flags);
	// while (fl_num.mantissa > 0)
	initialization(fraction, product);
	// printf(ANSI_COLOR_BLUE"\nOriginal Float Number = %Lf\n", fl_num.f_num);
	// printf(ANSI_COLOR_MAGENTA"\nMantissa in Hex = %llx\n", fl_num.mantissa);
	// printf(ANSI_COLOR_MAGENTA"Mantissa in Binary IN ORDER (from bit 0 to bit 63) \n");
	// print_mantissa_inorder(fl_num.mantissa);
	// printf(ANSI_COLOR_MAGENTA"\nMantissa in Binary IN REVERSE (from bit 63 to bit 0) \n");
	// print_mantissa_inreverse(fl_num.mantissa);
	// printf(ANSI_COLOR_MAGENTA"\nExponent in binary \n");
	// print_exponent_binary(fl_num.exponent[4]);
	// printf(ANSI_COLOR_MAGENTA"\nExponent Original = %d", fl_num.exponent[4]);
	index = 63;
	while (index >= 0)
	{
		bit = 1UL << index;
		if (fl_num.mantissa & bit)
		{
			// printf("\n\n--- Mantissa Found Bit equal to 1 ---");
			// printf(ANSI_COLOR_MAGENTA"\nmantissa in hex = %llx\n", fl_num.mantissa);
			// printf(ANSI_COLOR_MAGENTA"mantissa in binary\n");
			// print_mantissa_inreverse(fl_num.mantissa);
			// printf(ANSI_COLOR_MAGENTA"\none shifted in binary\n");
			// print_mantissa_inreverse(bit);
			// printf(ANSI_COLOR_MAGENTA"\nFraction : ");
			// print_fraction(fraction);
			str_add_prod_frac(product, fraction);
		}
		frac_divide_by_two(fraction);
		index--;
	}
	if (fl_num.exponent[4] != 0)
	{
		if ((fl_num.exponent[4] & (1<<15)) > 0)
			(*t_flags).flags |= FLAG_NEGAT;
		fl_num.exponent[4] &= ~(1<<15);
		fl_num.exponent[4] = fl_num.exponent[4] - 16383;
		exponent_calculation(product, fl_num.exponent[4]);
	}
	else if (fl_num.exponent[4] == 0)
		product[5003] = 0;
	// printf(ANSI_COLOR_MAGENTA"\nExponent in binary\n");
	// print_exponent_binary(fl_num.exponent[4]);
	// printf(ANSI_COLOR_MAGENTA"\nExponent WITHOUT the bias = %d\n", fl_num.exponent[4]);
	// printf(ANSI_COLOR_GREEN"\n\nFINAL FLOAT  : ");
	if (((*t_flags).flags & FLAG_NEGAT) > 0)
	{
		(*t_flags).total_chars_printed++;
		write((*t_flags).fd, "-", 1);
		// printf("-");
	}
	// printf(ANSI_COLOR_YELLOW"\nProduct Raw : \n");
	// print_product(product);
	// printf("\n");
	check_precision(product, t_flags);
	print_padding(t_flags, length_product(product));
	print_final_float(product, t_flags);
	// printf(ANSI_COLOR_YELLOW"\nProduct Result : \n");
	// print_product(product);
	// printf("\n");
	(*t_flags).total_chars_printed = (*t_flags).total_chars_printed + \
	length_product(product);
	clear_forfloat(&fl_num);
}
