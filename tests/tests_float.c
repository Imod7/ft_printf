/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests_float.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 17:32:58 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/08/19 17:33:01 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "test_header.h"

void		test_float1(void)
{
	int		total_chars_p;
	int		total_chars_ftp;

	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_RED"Test_42 : >f  '%.11f' , >+f  '%+f'\n", 45.34512345678, 876.643);
	total_chars_ftp = ft_printf(ANSI_COLOR_RED"Test_42 : >f  '%f' , >+f  '%+f'\n", 45.34512345678, 876.643);
	// assert(total_chars_p == total_chars_ftp);
	printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);
}
