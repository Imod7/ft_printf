/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests_exceptions.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 00:07:04 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/08/19 00:07:09 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "test_header.h"

void			test_exceptions1(void)
{
	int		    num;
	// int			total_chars_p;
	// int			total_chars_ftp;

	num = 74;
	write(1, "\n", 1);
	ft_printf(ANSI_COLOR_MAGENTA"Test 39 Undefined Behaviour \n");
	// total_chars_p = printf(ANSI_COLOR_CYAN"Test_39   >percentpercent   : '%%'     >k   : '%kjjj'  ,  > -9k   '% -9k'\n", num);
	// total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test_39   >percentpercent   : '%%'     >k   : '%kjjj'  ,  > -9k   '% -9k'\n", num);
	// assert(total_chars_p == total_chars_ftp);
	// printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	// printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);
}

void			test_exceptions2(void)
{
	int		    num;
	// int			total_chars_p;
	// int			total_chars_ftp;

	num = 74;
	write(1, "\n", 1);
	ft_printf(ANSI_COLOR_MAGENTA"Test 41 Undefined Behaviour \n");
	// total_chars_p = printf(ANSI_COLOR_RED"Test_41   >percentpercent   : '%%'     >15-mk   : '%15-mkjjj'  ,  >space9-v: '% 9-v'\n", num);
	// total_chars_ftp = ft_printf(ANSI_COLOR_RED"Test_41   >percentpercent   : '%%'     >15-mk   : '%15-mkjjj'  ,  >space9-v: '% 9-v'\n", num);
	// assert(total_chars_p == total_chars_ftp);
	// printf(ANSI_COLOR_MAGENTA"total_chars_p   = %d \n", total_chars_p);
	// printf(ANSI_COLOR_MAGENTA"total_chars_ftp = %d \n", total_chars_ftp);
}
