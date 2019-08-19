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

#include "../ft_printf.h"
#include "test_header.h"

void		test_one(void)
{
	int		total_chars_p;
	int		total_chars_ftp;

	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"'Test 1 : with the number '%+08d' and the string '%s' and the char '%c'\n", 45, "coding", 'K');
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"'Test 1 : with the number '%+08d' and the string '%s' and the char '%c'\n", 45, "coding", 'K');
	// assert(total_chars_p == total_chars_ftp);
	printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);
}

void		test_two(void)
{
	int		total_chars_p;
	int		total_chars_ftp;

	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"Test 2 +08d : '%+08d' blabla  '%6d' glopglop '%s'\n", 45, 899, "teleia");
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test 2 +08d : '%+08d' blabla  '%6d' glopglop '%s'\n", 45, 899, "teleia");
	assert(total_chars_p == total_chars_ftp);
}

void		test_three(void)
{
	int		total_chars_p;
	int		total_chars_ftp;

	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"Test 3 +8d : '%+8d' \n", 55);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test 3 +8d : '%+8d' \n", 55);
	assert(total_chars_p == total_chars_ftp);
}

void		test_int4(void)
{
	int		total_chars_p;
	int		total_chars_ftp;

	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"Test_4   >010d : '%010d'  > -9d : '% -9d'  > -9d negat value : '% -9d' \n", 1256, 596, -99);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test_4   >010d : '%010d'  > -9d : '% -9d'  > -9d negat value : '% -9d' \n", 1256, 596, -99);
	assert(total_chars_p == total_chars_ftp);
}

void		test_int5(void)
{
	int		total_chars_p;
	int		total_chars_ftp;

	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"Test 5 -10d : '%-10d'\n", 199);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test 5 -10d : '%-10d'\n", 199);
	assert(total_chars_p == total_chars_ftp);
}

void		test_six(void)
{
	int		a;
	short	b;
	int		total_chars_p;
	int		total_chars_ftp;

	a = 32761;
	b = (short)a;
	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"Test 6   >hd :  '%hd'  \n", b);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test 6   >hd :  '%hd'  \n", b);
	assert(total_chars_p == total_chars_ftp);
}

void			test_seven(void)
{
	int			a;
	signed char	b;
	int			total_chars_p;
	int			total_chars_ftp;

	a = 125;
	b = (signed char)a;
	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"Test 7   >hhd : '%hhd'    >-15hhd : '%-15hhd'\n", b, b);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test 7   >hhd : '%hhd'    >-15hhd : '%-15hhd'\n", b, b);
	assert(total_chars_p == total_chars_ftp);
}

void			test_eight(void)
{
	int			a;
	long		b;
	int			total_chars_p;
	int			total_chars_ftp;

	a = 6552231;
	b = (long)a;
	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"Test 8 ld : '%ld'\n", b);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test 8 ld : '%ld'\n", b);
	assert(total_chars_p == total_chars_ftp);
}

void			test_nine(void)
{
	int			a;
	long long	b;
	int			total_chars_p;
	int			total_chars_ftp;

	a = 2788999;
	b = (long long)a;
	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"Test 9 lld : '%lld'\n", b);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test 9 lld : '%lld'\n", b);
	assert(total_chars_p == total_chars_ftp);
}

void			test_ten(void)
{
	char		c;

	c = 'A';
	write(1, "\n", 1);
	ft_printf(ANSI_COLOR_MAGENTA"Test 10 Error/Warning >> ");
	// printf(ANSI_COLOR_CYAN"Test 10 +c THE PRINTF : '%+c'\n", c);
	ft_printf(ANSI_COLOR_YELLOW"Test 10 +c MY  PRINTF : '%+c'\n", c);
}

void			test_eleven(void)
{
	char		c;
	int			total_chars_p;
	int			total_chars_ftp;

	c = 'G';
	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"Test 11 -8c : '%-8c'\n", c);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test 11 -8c : '%-8c'\n", c);
	assert(total_chars_p == total_chars_ftp);
	// printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	// printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);
}

void			test_twelve(void)
{
	char		c;

	c = 'K';
	ft_printf(ANSI_COLOR_MAGENTA"Test 12 Error/Warning >> ");
	// printf(ANSI_COLOR_CYAN"Test 12 -0c THE PRINTF : '%-0c'\n", c);
	ft_printf(ANSI_COLOR_YELLOW"\nTest 12 -0c MY  PRINTF : '%-0c'\n\n", c);
}

void			test_thirteen(void)
{
	char		c;

	c = 'M';
	ft_printf(ANSI_COLOR_MAGENTA"Test 13 Error/Warning >> ");
	// printf(ANSI_COLOR_CYAN"Test 13 hc THE PRINTF : '%hc'\n", c);
	ft_printf(ANSI_COLOR_YELLOW"Test 13 hc MY  PRINTF : '%hc'\n\n", c);
}

void			test_fourteen(void)
{
	char		c;

	c = 'G';
	ft_printf(ANSI_COLOR_MAGENTA"Test 14 Error/Warning >> ");
	// printf(ANSI_COLOR_CYAN"Test 14 hhc THE PRINTF : '%hhc'\n", c);
	ft_printf(ANSI_COLOR_YELLOW"Test 14 hhc MY  PRINTF : '%hhc'\n\n", c);
}

void			test_fifteen(void)
{
	char		c;
	int			total_chars_p;
	int			total_chars_ftp;

	c = 'B';
	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"Test 15 9lc : '%9lc'\n", c);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test 15 9lc : '%9lc'\n", c);
	assert(total_chars_p == total_chars_ftp);
	// printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	// printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);
}

void			test_16(void)
{
	char		c;

	c = 'C';
	write(1, "\n", 1);
	ft_printf(ANSI_COLOR_MAGENTA"Test 16 Error/Warning >> ");
	// printf(ANSI_COLOR_CYAN"Test 16 4llc THE PRINTF : '%4llc'\n", c);
	ft_printf(ANSI_COLOR_YELLOW"Test 16 4llc MY  PRINTF : '%4llc'\n\n", c);
}

void			test_20(void)
{
	int			num;
	int			total_chars_p;
	int			total_chars_ftp;

	num = 54;
	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"Test 20   >.11d : '%.11d'   >*.18d: '%*.18d'   >0.14d   '%0.14d'\n", num, 33, num, num);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test 20   >.11d : '%.11d'   >*.18d: '%*.18d'   >0.14d   '%0.14d'\n", num, 33, num, num);
	assert(total_chars_p == total_chars_ftp);
	// printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	// printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);
}

void			test_21(void)
{
	int			num;
	int			total_chars_p;
	int			total_chars_ftp;

	num = 88;
	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"Test 21 .15d : '%.15d'  >24.5d    '%24.5d'\n", num, num);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test 21 .15d : '%.15d'  >24.5d    '%24.5d'\n", num, num);
	assert(total_chars_p == total_chars_ftp);
	// printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	// printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);
}
