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

void			test_17(void)
{
	int		    num;
	int			total_chars_p;
	int			total_chars_ftp;

	num = 74;
	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"Test 17 6o : '%6o'\n", num);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test 17 6o : '%6o'\n", num);
	assert(total_chars_p == total_chars_ftp);
	// printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	// printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);
}

void				test_18(void)
{
	unsigned short	num;
	int				total_chars_p;
	int				total_chars_ftp;

	num = 5623;
	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"Test 18   >05o : '%05o' , >#*o : '%#*o'\n", num, 22, num);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test 18   >05o : '%05o' , >#*o : '%#*o'\n", num, 22, num);
	assert(total_chars_p == total_chars_ftp);
	// printf(ANSI_COLOR_RED"total_chars_p   = %d \n", total_chars_p);
	// printf(ANSI_COLOR_RED"total_chars_ftp = %d \n", total_chars_ftp);
}

void				test_19(void)
{
	unsigned char	num;
	// int				total_chars_p;
	// int				total_chars_ftp;

	num = 120;
	write(1, "\n", 1);
	ft_printf(ANSI_COLOR_MAGENTA"Test 19 Error/Warning >> ");
	// total_chars_p = printf(ANSI_COLOR_CYAN"Test 19 space7o THE PRINTF : '% 7o'\n", num);
	ft_printf(ANSI_COLOR_YELLOW"Test 19 space7o MY  PRINTF : '% 7o'\n\n", num);
	// printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	// printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);
}
