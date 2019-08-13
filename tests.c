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
	printf(ANSI_COLOR_CYAN"Test 2 +08d THE PRINTF : '%+08d' blabla\n", 45);
	ft_printf(ANSI_COLOR_YELLOW"Test 2 +08d MY  PRINTF : '%+08d' blabla\n\n", 45);
}

void		test_three(void)
{
	printf(ANSI_COLOR_CYAN"Test 3 +8d THE PRINTF : '%+8d' \n", 55);
	ft_printf(ANSI_COLOR_YELLOW"Test 3 +8d MY  PRINTF : '%+8d' \n\n", 55);
}

void		test_four(void)
{
	printf(ANSI_COLOR_CYAN"Test 4 010d THE PRINTF : '%010d'\n", 1256);
	ft_printf(ANSI_COLOR_YELLOW"Test 4 010d MY  PRINTF : '%010d'\n\n", 1256);
}

void		test_five(void)
{
	printf(ANSI_COLOR_CYAN"Test 5 -10d THE PRINTF : '%-10d'\n", 99);
	ft_printf(ANSI_COLOR_YELLOW"Test 5 -10d MY  PRINTF : '%-10d'\n\n", 99);
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

void			test_ten(void)
{
	char		c;

	c = 'A';
	ft_printf(ANSI_COLOR_GREEN"Test 10 should show error >> ");
	// printf(ANSI_COLOR_CYAN"Test 10 +c THE PRINTF : '%+c'\n", c);
	ft_printf(ANSI_COLOR_YELLOW"\nTest 10 +c MY  PRINTF : '%+c'\n\n", c);
}

void			test_eleven(void)
{
	char		c;

	c = 'G';
	printf(ANSI_COLOR_CYAN"\nTest 11 -8c THE PRINTF : '%-8c'\n", c);
	ft_printf(ANSI_COLOR_YELLOW"Test 11 -8c MY  PRINTF : '%-8c'\n\n", c);
}

void			test_twelve(void)
{
	char		c;

	c = 'K';
	ft_printf(ANSI_COLOR_GREEN"Test 12 should show error >> ");
	// printf(ANSI_COLOR_CYAN"Test 12 -0c THE PRINTF : '%-0c'\n", c);
	ft_printf(ANSI_COLOR_YELLOW"\nTest 12 -0c MY  PRINTF : '%-0c'\n\n", c);
}

void			test_thirteen(void)
{
	char		c;

	c = 'M';
	ft_printf(ANSI_COLOR_GREEN"Test 13 should show error >> ");
	// printf(ANSI_COLOR_CYAN"Test 13 hc THE PRINTF : '%hc'\n", c);
	ft_printf(ANSI_COLOR_YELLOW"Test 13 hc MY  PRINTF : '%hc'\n\n", c);
}

void			test_fourteen(void)
{
	char		c;

	c = 'G';
	ft_printf(ANSI_COLOR_GREEN"Test 14 should show error >> ");
	// printf(ANSI_COLOR_CYAN"Test 14 hhc THE PRINTF : '%hhc'\n", c);
	ft_printf(ANSI_COLOR_YELLOW"Test 14 hhc MY  PRINTF : '%hhc'\n\n", c);
}

void			test_fifteen(void)
{
	char		c;

	c = 'B';
	printf(ANSI_COLOR_CYAN"Test 15 9lc THE PRINTF : '%9lc'\n", c);
	ft_printf(ANSI_COLOR_YELLOW"Test 15 9lc MY  PRINTF : '%9lc'\n\n", c);
}

void			test_16(void)
{
	char		c;

	c = 'C';
	ft_printf(ANSI_COLOR_GREEN"Test 16 should show error >> ");
	// printf(ANSI_COLOR_CYAN"Test 16 4llc THE PRINTF : '%4llc'\n", c);
	ft_printf(ANSI_COLOR_YELLOW"Test 16 4llc MY  PRINTF : '%4llc'\n\n", c);
}

void			test_20(void)
{
	int			num;

	num = 54;
	printf(ANSI_COLOR_CYAN"Test 20 .15d THE PRINTF : '%.15d'\n", num);
	ft_printf(ANSI_COLOR_YELLOW"Test 20 .15d MY  PRINTF : '%.15d'\n\n", num);
}

void			test_21(void)
{
	int			num;

	num = 88;
	printf(ANSI_COLOR_CYAN"Test 21 .15d THE PRINTF : '%.15d'\n", num);
	ft_printf(ANSI_COLOR_YELLOW"Test 21 .15d MY  PRINTF : '%.15d'\n\n", num);
}
