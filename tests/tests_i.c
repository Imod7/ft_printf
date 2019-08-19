/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests_i.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 13:57:30 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/08/19 13:57:32 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "test_header.h"

void			test_i1(void)
{
	int			num;
	int			total_chars_p;
	int			total_chars_ftp;

	num = -2147483648;
	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"34 = test_i1 0.22i : '%0.22i'\n", num);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"34 = test_i1 0.22i : '%0.22i'\n", num);
	assert(total_chars_p == total_chars_ftp);
}

void			test_i2(void)
{
	int			num;
	int			total_chars_p;
	int			total_chars_ftp;

	num = -21;
	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_RED"Test_35 =  >*.5i : '%*.5i'  >*.6i : '%*.6i'  >0.7i : '%0.7i' \n", 5, num, 11, num, -954);
	total_chars_ftp = ft_printf(ANSI_COLOR_RED"Test_35 =  >*.5i : '%*.5i'  >*.6i : '%*.6i'  >0.7i : '%0.7i' \n", 5, num, 11, num, -954);
	// assert(total_chars_p == total_chars_ftp);
	printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);
}

void			test_i3(void)
{
	long		num;
	int			total_chars_p;
	int			total_chars_ftp;

	num = -2147483648;
	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"Test_36 = with flags -17.4li and limit of long : '%-17.4li'\n", num);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test_36 = with flags -17.4li and limit of long : '%-17.4li'\n", num);
	assert(total_chars_p == total_chars_ftp);
}

void		test_i4(void)
{
	int		total_chars_p;
	int		total_chars_ftp;

	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"Test_40   >010.3i : '%010i'  > -9.4i : '% -9i'  > -9i negat value : '% -9i' \n", 1256, 596, -99);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test_40   >010.3i : '%010i'  > -9.4i : '% -9i'  > -9i negat value : '% -9i' \n", 1256, 596, -99);
	assert(total_chars_p == total_chars_ftp);
}
