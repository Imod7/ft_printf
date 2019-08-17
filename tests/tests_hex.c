/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests_octal.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/13 20:29:54 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/08/13 20:29:56 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "test_header.h"

void				test_hex1(void)
{
	unsigned int	num;
	int				total_chars_p;
	int				total_chars_ftp;

	num = -2000;
	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"Test 22 x : '%x'\n", num);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test 22 x : '%x'\n", num);
	assert(total_chars_p == total_chars_ftp);
	// printf(ANSI_COLOR_RED"total_chars_p   = %d \n", total_chars_p);
	// printf(ANSI_COLOR_RED"total_chars_ftp = %d \n", total_chars_ftp);
}

void				test_hex2(void)
{
	unsigned int	num;
	int				total_chars_p;
	int				total_chars_ftp;

	num = 4294967295;
	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_RED"Test_23 #x, #*x  : '%#x', '%#*x'\n", num, 17, num);
	total_chars_ftp = ft_printf(ANSI_COLOR_RED"Test_23 #x, #*x  : '%#x', '%#*x'\n", num, 17, num);
	// assert(total_chars_p == total_chars_ftp);
	printf(ANSI_COLOR_RED"total_chars_p   = %d \n", total_chars_p);
	printf(ANSI_COLOR_RED"total_chars_ftp = %d \n", total_chars_ftp);
}

void				test_hex3(void)
{
	int			    num;
	int				total_chars_p;
	int				total_chars_ftp;

	num = 4000;
	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"Test 24 0.11x : '%0.11x'\n", num);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test 24 0.11x : '%0.11x'\n", num);
	assert(total_chars_p == total_chars_ftp);
	// printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	// printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);
}

void				test_hex4(void)
{
	unsigned short	num;
	int				total_chars_p;
	int				total_chars_ftp;

	num = 65535;
	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"Test 25 hx : '%hx'\n", num);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test 25 hx : '%hx'\n", num);
	assert(total_chars_p == total_chars_ftp);
	// printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	// printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);
}

void				test_hex5(void)
{
	unsigned char	num;
	int				total_chars_p;
	int				total_chars_ftp;

	num = 255;
	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"Test 26 hhx : '%hhx'\n", num);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test 26 hhx : '%hhx'\n", num);
	assert(total_chars_p == total_chars_ftp);
}

void				test_hex6(void)
{
	unsigned long	num;
	int				total_chars_p;
	int				total_chars_ftp;

	num = 4294967295;
	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"Test 27 lx for limit of unsigned long : '%lx'\n", num);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test 27 lx for limit of unsigned long : '%lx'\n", num);
	assert(total_chars_p == total_chars_ftp);
}

void					test_hex7(void)
{
	unsigned long long	num;
	int					total_chars_p;
	int					total_chars_ftp;

	num = 18446744073709551615U;
	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"Test_27 limit of unsigned long long llx : '%llx'\n", num);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test_27 limit of unsigned long long llx : '%llx'\n", num);
	assert(total_chars_p == total_chars_ftp);
}

void					test_hex8(void)
{
	unsigned short 		num;
	int					total_chars_p;
	int					total_chars_ftp;

	num = 65535;
	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"Test_28 hX : '%hX'\n", num);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test_28 hX : '%hX'\n", num);
	assert(total_chars_p == total_chars_ftp);
	// printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	// printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);
}

void					test_hex9(void)
{
	unsigned char 		num;
	int					total_chars_p;
	int					total_chars_ftp;

	num = 255;
	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"Test_29 09hhX : '%09hhX'\n", num);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test_29 09hhX : '%09hhX'\n", num);
	assert(total_chars_p == total_chars_ftp);
	// printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	// printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);
}

void					test_hex10(void)
{
	unsigned long 		num;
	int					total_chars_p;
	int					total_chars_ftp;

	num = 4294967295;
	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"Test_30 0*lX : '%0*lX'\n", 15, num);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test_30 0*lX : '%0*lX'\n", 15, num);
	assert(total_chars_p == total_chars_ftp);
	// printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	// printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);
}

void					test_hex11(void)
{
	unsigned long long	num;
	// int					total_chars_p;
	int					total_chars_ftp;

	num = 18446744073709551615U;
	write(1, "\n", 1);
	ft_printf(ANSI_COLOR_MAGENTA"32=test_hex11 Error (w flags in gcc) / Warning (wo flags) >> ");
	// total_chars_p = printf(ANSI_COLOR_CYAN"32=test_hex11 space*llX : '% *llX'\n", 28, num);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"32=test_hex11 space*llX : '% *llX'\n", 28, num);
	// assert(total_chars_p == total_chars_ftp);
}

void					test_hex12(void)
{
	unsigned long long	num;
	int					total_chars_p;
	int					total_chars_ftp;

	num = 18446744073709551615U;
	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"33 = test_hex12 -*llX : '%-*llX'\n", 66, num);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"33 = test_hex12 -*llX : '%-*llX'\n", 66, num);
	assert(total_chars_p == total_chars_ftp);
	// printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	// printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);
}
