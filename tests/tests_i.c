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
#include <fcntl.h>

void			test_i1(void)
{
	int			num;
	int			total_chars_p;
	int			total_chars_ftp;
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			fd;

	num = -2147483648;
	write(1, "\n", 1);
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	// if (fd < 0)
	// 	return (0);
	total_chars_p = dprintf(fd, "Test_34, test_i1 %%0.22i : '%0.22i'\n", num);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test_34, test_i1 %%0.22i : '%0.22i'\n", num);
	assert(total_chars_p == total_chars_ftp);
	// printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	// printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);

	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	assert(strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0);

	if (strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0)
		printf(ANSI_COLOR_GREEN"Test 34 with %%0.22i : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 34 with %%0.22i : Wrong!\n");
}

void			test_i2(void)
{
	int			num;
	int			total_chars_p;
	int			total_chars_ftp;
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			fd;

	num = -21;
	write(1, "\n", 1);
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test_35 :  %%*.5i='%*.5i'  %%*.6i='%*.6i'  %%0.7i='%0.7i' \n", 5, num, 11, num, -954);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test_35 :  %%*.5i='%*.5i'  %%*.6i='%*.6i'  %%0.7i='%0.7i' \n", 5, num, 11, num, -954);
	// assert(total_chars_p == total_chars_ftp);
	// printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	// printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);

	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	// assert(strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0);

	if (strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0)
		printf(ANSI_COLOR_GREEN"Test 35 with %%*.5i, %%*.6i, %%0.7i : Correct!\n");
	else
	{
		printf(ANSI_COLOR_RED"Test 35 with %%*.5i, %%*.6i, %%0.7i : Wrong!\n");
		printf("Error when field width is equal to precision \n");
	}
}

void			test_i3(void)
{
	long		num;
	int			total_chars_p;
	int			total_chars_ftp;

	num = -2147483648;
	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"Test_36 : %%-17.4li and argum is the limit of long='%-17.4li' , %%.i='%.li'\n", num, num);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test_36 : %%-17.4li and argum is the limit of long='%-17.4li' , %%.i='%.li'\n", num, num);
	assert(total_chars_p == total_chars_ftp);
}

void		test_i4(void)
{
	int		total_chars_p;
	int		total_chars_ftp;

	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"Test_40 : %%010i='%010i' , %%space-9.4i='% -9.4i' , %%space-9i negat value='% -9i' \n", 1256, 596, -99);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test_40 : %%010i='%010i' , %%space-9.4i='% -9.4i' , %%space-9i negat value='% -9i' \n", 1256, 596, -99);
	assert(total_chars_p == total_chars_ftp);
}
