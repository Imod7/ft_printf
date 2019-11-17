/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_binary.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/16 19:40:27 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/11/16 19:40:30 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void			print_binary(long long num)
{
	int			bit;
	int			pos;

	printf(ANSI_COLOR_MAGENTA"\nthe num is : %d\n", (int)num);
	if (num < 0)
		num = num * (-1);
	pos = 9;
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
