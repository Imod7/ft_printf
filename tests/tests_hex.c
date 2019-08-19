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
	total_chars_p = printf(ANSI_COLOR_CYAN"Test 22 >x : '%x'  ,  >+x: undefined behaviour but works \n", num);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test 22 >x : '%x'  ,  >+x: undefined behaviour but works \n", num);
	// assert(total_chars_p == total_chars_ftp);
	printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);
}

void				test_hex2(void)
{
	unsigned int	num;
	int				total_chars_p;
	int				total_chars_ftp;

	num = 4294967295;
	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"Test_23 #x, #*x  : '%#x', '%#*x'\n", num, 17, num);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test_23 #x, #*x  : '%#x', '%#*x'\n", num, 17, num);
	assert(total_chars_p == total_chars_ftp);
	// printf(ANSI_COLOR_RED"total_chars_p   = %d \n", total_chars_p);
	// printf(ANSI_COLOR_RED"total_chars_ftp = %d \n", total_chars_ftp);
}

void				test_hex3(void)
{
	int			    num;
	int				total_chars_p;
	int				total_chars_ftp;

	num = 4000;
	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"Test 24:  >0.11x : '%0.11x'   >*.15x : '%*.15x'   >.13x : '%.13x'\n", num, 30, num, num);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test 24:  >0.11x : '%0.11x'   >*.15x : '%*.15x'   >.13x : '%.13x'\n", num, 30, num, num);
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
	total_chars_p = printf(ANSI_COLOR_CYAN"Test 25 >hx : '%hx' ,   >-*hx  : '%-*.2hx'   > -5x : undefined behaviour\n", num, 9, num);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test 25 >hx : '%hx' ,   >-*hx  : '%-*.2hx'   > -5x : undefined behaviour\n", num, 9, num);
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
	total_chars_p = printf(ANSI_COLOR_CYAN"Test 26 >020hhx : '%020hhx'   >015hhx : '%015hhx' \n", num, num);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test 26 >020hhx : '%020hhx'   >015hhx : '%015hhx' \n", num, num);
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
	total_chars_p = printf(ANSI_COLOR_CYAN"Test_29   >hX: '%hX' ,  >0.13X: %0.13X ,  >.12X: %.12X ,  >.9X: %*.9X \n", num, num, num, 10, num);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test_29   >hX: '%hX' ,  >0.13X: %0.13X ,  >.12X: %.12X ,  >.9X: %*.9X \n", num, num, num, 10, num);
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
	total_chars_p = printf(ANSI_COLOR_CYAN"Test_30:   >09hhX : '%09hhX'   >#09hhX:  '%#09hhX'\n", num, num);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test_30:   -09hhX : '%09hhX'   -#09hhX:  '%#09hhX'\n", num, num);
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
	total_chars_p = printf(ANSI_COLOR_CYAN"Test_31:  0*lX : '%0*lX'\n", 15, num);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test_31:  0*lX : '%0*lX'\n", 15, num);
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
	ft_printf(ANSI_COLOR_MAGENTA"Test_32 Error (w flags in gcc) / Warning (wo flags) >> ");
	// total_chars_p = printf(ANSI_COLOR_CYAN"32=test_hex11 space*llX : '% *llX'\n", 28, num);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test_32: space*llX : '% *llX'\n", 28, num);
	// assert(total_chars_p == total_chars_ftp);
}

void					test_hex12(void)
{
	unsigned long long	num;
	int					total_chars_p;
	int					total_chars_ftp;

	num = 123789555845795653;
	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"33 = test_hex12 -*llX : '%-*llX'\n", 66, num);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"33 = test_hex12 -*llX : '%-*llX'\n", 66, num);
	assert(total_chars_p == total_chars_ftp);
	// printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	// printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);
}
