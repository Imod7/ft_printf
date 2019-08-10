/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/09 00:20:25 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/08/09 00:24:25 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		test_one(void)
{
	printf(ANSI_COLOR_CYAN"'Test 1 THE PRINTF : with the number '%+08d' and the string '%s' and the char '%c'\n", 45, "coding", 'K');
	ft_printf(ANSI_COLOR_YELLOW"'Test 1 MY  PRINTF : with the number '%+08d' and the string '%s' and the char '%c'\n\n", 45, "coding", 'K');
}

void		test_two(void)
{
	printf(ANSI_COLOR_CYAN"Test 2 THE PRINTF : '%+08d' blabla\n", 45);
	ft_printf(ANSI_COLOR_YELLOW"Test 2 MY  PRINTF : '%+08d' blabla\n\n", 45);
}

void		test_three(void)
{
	printf(ANSI_COLOR_CYAN"Test 3 THE PRINTF : '%+8d' \n", 55);
	ft_printf(ANSI_COLOR_YELLOW"Test 3 MY  PRINTF : '%+8d' \n\n", 55);
}

void		test_four(void)
{
	printf(ANSI_COLOR_CYAN"Test 4 THE PRINTF : '%010d'\n", 1256);
	ft_printf(ANSI_COLOR_YELLOW"Test 4 MY  PRINTF : '%010d'\n\n", 1256);
}

void		test_five(void)
{
	printf(ANSI_COLOR_CYAN"Test 5 THE PRINTF : '%-10d'\n", 99);
	ft_printf(ANSI_COLOR_YELLOW"Test 5 MY  PRINTF : '%-10d'\n\n", 99);
}

void		test_six(void)
{
	int		a;
	short	b;

	a = 32761;
	b = (short)a;
	printf(ANSI_COLOR_CYAN"Test 6 hd THE PRINTF : '%hd'\n", b);
	ft_printf(ANSI_COLOR_YELLOW"Test 6 hd MY  PRINTF : '%hd'\n\n", b);
}

void			test_seven(void)
{
	int			a;
	signed char	b;

	a = 125;
	b = (signed char)a;
	printf(ANSI_COLOR_CYAN"Test 7 hhd THE PRINTF : '%hhd'\n", b);
	ft_printf(ANSI_COLOR_YELLOW"Test 7 hhd MY  PRINTF : '%hhd'\n\n", b);
}

void			test_eight(void)
{
	int			a;
	long		b;

	a = 6552231;
	b = (long)a;
	printf(ANSI_COLOR_CYAN"Test 8 ld THE PRINTF : '%ld'\n", b);
	ft_printf(ANSI_COLOR_YELLOW"Test 8 ld MY  PRINTF : '%ld'\n\n", b);
}

void			test_nine(void)
{
	int			a;
	long long	b;

	a = 2788999;
	b = (long long)a;
	printf(ANSI_COLOR_CYAN"Test 9 lld THE PRINTF : '%lld'\n", b);
	ft_printf(ANSI_COLOR_YELLOW"Test 9 lld MY  PRINTF : '%lld'\n\n", b);
}
