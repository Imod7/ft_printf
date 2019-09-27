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
	// pr[5003] = '5';
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

void		check_modifier_float(va_list argptr, t_float *fl, t_format *t_flags)
{
	if ((*t_flags).modifier == N)
		(*fl).f_num = va_arg(argptr, double);
		// (*fl).f_num = (double)((*fl).f_num);
	if ((*t_flags).modifier == l)
		(*fl).f_num = va_arg(argptr, double);
		// (*fl).f_num = (double)((*fl).f_num);
	else if ((*t_flags).modifier == L)
		(*fl).f_num = va_arg(argptr, long double);
		// (*fl).f_num = (long double)((*fl).f_num);
}

void				ft_ftoa(va_list argptr, t_format *t_flags)
{
	t_float			fl_num;
	char			fraction[400];
	short			product[10000];
	int				pos;
	unsigned long	bit;

	printf("\nflag = %d\n", (*t_flags).flags);
	// fl_num.f_num = va_arg(argptr, long double);
	check_modifier_float(argptr, &fl_num, t_flags);
	// while (fl_num.mantissa > 0)
	initialization(fraction, product);
	printf(ANSI_COLOR_CYAN"\nOriginal Float Number = %Lf\n", fl_num.f_num);
	printf(ANSI_COLOR_YELLOW"\nmantissa in hex = %llx\n", fl_num.mantissa);
	printf(ANSI_COLOR_MAGENTA"mantissa in binary IN ORDER (from bit 0 to bit 63) \n");
	print_mantissa_inorder(fl_num.mantissa);
	printf(ANSI_COLOR_MAGENTA"\nmantissa in binary IN REVERSE (from bit 63 to bit 0) \n");
	print_mantissa_inreverse(fl_num.mantissa);
	printf(ANSI_COLOR_CYAN"\nexponent in hex = %x\n", fl_num.exponent[0]);
	printf(ANSI_COLOR_YELLOW"exponent in binary \n");
	print_exponent_binary(fl_num.exponent[4]);
	pos = 63;
	while (pos >= 0)
	{
		bit = 1UL << pos;
		if (fl_num.mantissa & bit)
		{
			printf("\n\n--- Mantissa Found Bit equal to 1 ---");
			printf("\nmantissa in hex = %llx\n", fl_num.mantissa);
			printf("mantissa in binary\n");
			print_mantissa_inreverse(fl_num.mantissa);
			printf("\none shifted in binary\n");
			print_mantissa_inreverse(bit);
			printf("\nFraction : ");
			print_fraction(fraction);
			printf("\nProduct  : ");
			print_product(product);
			str_add_prod_frac(product, fraction);
		}
		str_divide_by_two(fraction);
		pos--;
	}	
	pos = 14;
	while (pos >= 0)
	{
		bit = 1 << pos;
		if (fl_num.exponent[4] & bit)
		{
			printf("\n\n--- Exponent Found Bit equal to 1 ---");
			printf(ANSI_COLOR_CYAN"\nexponent in hex = %x\n", fl_num.exponent[0]);
			printf(ANSI_COLOR_YELLOW"exponent in binary \n");
			print_exponent_binary(fl_num.exponent[4]);
			printf("\none shifted in binary\n");
			print_exponent_binary(bit);
			str_double(product);
		}
		pos--;
	}
	printf(ANSI_COLOR_GREEN"\n\nFINAL FLOAT  : ");
	print_product(product);
	printf("\n\n");
}
