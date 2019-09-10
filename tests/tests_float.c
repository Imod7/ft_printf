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
	total_chars_ftp = ft_printf(ANSI_COLOR_RED"Test_42 : >f  '%.11f' , >+f  '%+f'\n", 45.34512345678, 876.643);
	// assert(total_chars_p == total_chars_ftp);
	printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	// printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);
}

void		test_float2(void)
{
	int		total_chars_p;
	int		total_chars_ftp;

	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_RED"Test_43 : >.2f  '%.2f' , >.0f  '%.0f' , >.0f   %.0f\n", 2.5, 2.5, 3.5);
	total_chars_ftp = printf(ANSI_COLOR_RED"Test_43 : >.2f  '%.2f' , >.0f  '%.0f' , >.0f   %.0f\n", 2.5, 2.5, 3.5);
	// assert(total_chars_p == total_chars_ftp);
	printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);
}

void		test_float3(void)
{
	int		total_chars_p;
	int		total_chars_ftp;
	float	num;

	num = 1.192092896e-07F;
	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_RED"Test_44 : >f='%f'\n", num);
	total_chars_ftp = printf(ANSI_COLOR_RED"Test_44 : >f='%f'\n", num);
	// assert(total_chars_p == total_chars_ftp);
	printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);
}

void		test_float4(void)
{
	int		total_chars_p;
	int		total_chars_ftp;
	float	num;
	double	numd;
	int		fd;
	char	*returned_line_dprintf;
	char	*returned_line_ft_dprintf;

	num = 2.2204460492503131e-016;
	numd = 2.718281828;
	write(1, "\n", 1);
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	// total_chars_p = printf(ANSI_COLOR_RED"Test_45 : %%f='%f', %%lf='%lf' , %%f='%f'\n", num, num, numd);
	total_chars_p = printf(ANSI_COLOR_RED"Test_45\n%.0f\n%.1f\n%.2f\n%.6f\n%f\n%.7f", numd, numd, numd, numd, numd, numd);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	// total_chars_ftp = ft_printf(ANSI_COLOR_RED"Test_45 : %%f='%f', %%lf='%lf' , %%f='%f'\n", num, num, numd);
	total_chars_ftp = ft_printf(ANSI_COLOR_RED"Test_45\n%.0f\n%.1f\n%.2f\n%.6f\n%f\n%.7f", numd, numd, numd, numd, numd, numd);
	// assert(total_chars_p == total_chars_ftp);
	printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);

	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	// assert(strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0);

	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && (total_chars_p == total_chars_ftp))
		printf(ANSI_COLOR_GREEN"Test 45 with %%f : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 45 with %%f : Wrong!\n");
}
