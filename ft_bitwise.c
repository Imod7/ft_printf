/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bitwise.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 11:55:15 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/09/17 12:24:55 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_binary(long long num)
{
	int			bit;
	int			pos;

	printf(ANSI_COLOR_MAGENTA"\nthe num is : %d\n", (int)num);
	if (num < 0)
		num = num * (-1);
	pos = 16;
	while (pos >= 0)
	{
		bit = num >> pos;
		if (bit & 1)
			printf("1 ");
		else
			printf("0 ");
		pos--;
	}
}

long long		invert_allbits(long long num)
{
	int			bit;
	int			pos;

	printf(ANSI_COLOR_MAGENTA"\nthe num is : %d\n", (int)num);
	if (num < 0)
		num = num * (-1);
	pos = 16;
	while (pos >= 0)
	{
		num = (num ^ (1 << pos));
		bit = num >> pos;
		pos--;
	}
	return (num);
}

long long		binary_addone(long long num)
{
	int			bit;

	printf(ANSI_COLOR_MAGENTA"\nthe num is : %d\n", (int)num);
	if (num < 0)
		num = num * (-1);
	bit = num >> 0;
	if ((bit & 1) == 0)
		num = (num ^ (1 << 0));
	bit = num >> 0;
	return (num);
}
