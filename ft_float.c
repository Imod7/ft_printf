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

void            print_bin(uint64_t mant)
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

void            str_half(char *fr)
{
    double      temp;

    temp = 0;
    if (fr[0] == '1')
        fr[0] = '0';
    if (fr[201] == '0')
        fr[201] = '5';
    else
    {
        temp = ft_atoi(&fr[201]);
        temp = temp / 2;
        printf("\ntemp = %f\n", temp);
    }
}

void            str_add(short *pr, char *fr)
{
    pr[0] = '1';
    fr[0] = '0';
}

void            ft_ftoa(va_list argptr, t_format *t_flags)
{
    t_float     fl_num;
    char		fraction[400];
	short		product[10000];

    printf("\nflag = %d\n", (*t_flags).flags);
    fraction[0] = '1';
    fraction[1] = '.';
    fraction[201] = '0';
    product[5000] = '0';
    product[5001] = '.';
    product[5002] = '0';
    fl_num.f_num = va_arg(argptr, long double);
    while (fl_num.mantissa > 0)
    {
        printf("\nmantissa = %llu\n", fl_num.mantissa);
        print_bin(fl_num.mantissa);
        if (fl_num.mantissa & 1)
            str_add(product, fraction);
        str_half(fraction);
        fl_num.mantissa = fl_num.mantissa << 1;
    }
}
