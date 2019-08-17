/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests_double.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/17 04:34:22 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/08/17 04:34:25 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "test_header.h"

void			test_pointer1(void)
{
	int			num;
	void		*ptr;
	int			total_chars_p;
	int			total_chars_ftp;

	num = -586;
	ptr = &num;
	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"37 = -19p : '%-19p'\n", ptr);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"37 = -19p : '%-19p'\n", ptr);
	assert(total_chars_p == total_chars_ftp);
	// printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	// printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);
}

void			test_pointer2(void)
{
	long long	num;
	void		*ptr;
	int			total_chars_p;
	int			total_chars_ftp;

	num = 9223372036854775807;
	ptr = &num;
	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"38 = -*p : '%-*p', '%*p'\n", 29, ptr, 16, ptr);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"38 = -*p : '%-*p', '%*p'\n", 29, ptr, 16, ptr);
	assert(total_chars_p == total_chars_ftp);
}
