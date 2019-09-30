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
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			total_chars_p;
	int			total_chars_ftp;
	int			fd;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	// total_chars_p = dprintf(fd, "Test 42 : %%.11f='%.11f', %%+f='%+f'\n", 45.34512345678, 876.643);
	total_chars_p = dprintf(fd, "Test 42 : %%f='%.20f', %%f='%f'\n", -125.33, -125.33);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 42 : %%f='%.20f', %%f='%f'\n", -125.33, -125.33);
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
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
		printf(ANSI_COLOR_GREEN"Test 42 (float1) negative arg : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 42 (float1) negative arg : Wrong!\n");
}

void		test_float2(void)
{
	int		total_chars_p;
	int		total_chars_ftp;
	int		fd;
	char	*returned_line_dprintf;
	char	*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test_44 : %%.2f='%.2f', %%.0f='%.0f', %%.0f='%.0f'\n", 2.5, 2.5, 3.5);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test_44 : %%.2f='%.2f', %%.0f='%.0f', %%.0f='%.0f'\n", 2.5, 2.5, 3.5);
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
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
		printf(ANSI_COLOR_GREEN"Test 44 (float2) : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 44 (float2) : Wrong!\n");
}

void		test_float3(void)
{
	int		total_chars_p;
	int		total_chars_ftp;
	int		fd;
	char	*returned_line_dprintf;
	char	*returned_line_ft_dprintf;
	float	num;

	num = 1.192092896e-07F;
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 45 : %%.2f='%.2f', %%.0f='%.0f', %%.0f='%.0f'\n", num, num, num);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 45 : %%.2f='%.2f', %%.0f='%.0f', %%.0f='%.0f'\n", num, num, num);
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
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
		printf(ANSI_COLOR_GREEN"Test 45 (float3) : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 45 (float3) : Wrong!\n");
}

void		test_float4(void)
{
	int		total_chars_p;
	int		total_chars_ftp;
	double	numd;
	int		fd;
	char	*returned_line_dprintf;
	char	*returned_line_ft_dprintf;

	numd = 2.718281828;
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	// total_chars_p = printf(ANSI_COLOR_RED"Test_46 : %%f='%f', %%lf='%lf' , %%f='%f'\n", num, num, numd);
	total_chars_p = dprintf(fd, "Test 46 : %%.0f='%.0f', %%.1f='%.1f', %%.2f='%.2f', %%.6f='%.6f', %%f='%f', %%.7f='%.7f'\n", numd, numd, numd, numd, numd, numd);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 46 : %%.0f='%.0f', %%.1f='%.1f', %%.2f='%.2f', %%.6f='%.6f', %%f='%f', %%.7f='%.7f'\n", numd, numd, numd, numd, numd, numd);
	// assert(total_chars_p == total_chars_ftp);

	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	// assert(strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && (total_chars_p == total_chars_ftp))
		printf(ANSI_COLOR_GREEN"Test 46 (float4) : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 46 (float4) : Wrong!\n");
}

void		test_float5(void)
{
	int		total_chars_p;
	int		total_chars_ftp;
	double	num;
	int		fd;
	char	*returned_line_dprintf;
	char	*returned_line_ft_dprintf;

	// num = 2.2204460492503131e-016;
	num = 2.01234567890155;
// 3756446352456454545615151.18934765781367137389565646848445137;
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	// total_chars_p = dprintf(fd, "Test_47\n%.0f\n%.1f\n%.2f\n%.6f\n%f\n%.7f\nf\n%lf\n%.30f\n", num, num , num, num, num, num, num, num);
	total_chars_p = dprintf(fd, "Test_47 : %%.12f='%.12f'\n", num);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test_47 : %%.12f='%.12f'\n", num);
	// assert(total_chars_p == total_chars_ftp);

	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	// assert(strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) \
	&& (total_chars_p == total_chars_ftp))
		printf(ANSI_COLOR_GREEN"Test 47  : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 47 : Wrong!\n");
}

void		test_float6(void)
{
	int		total_chars_p;
	int		total_chars_ftp;
	double	num;
	int		fd;
	char	*returned_line_dprintf;
	char	*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 57 : rounding(197.5)='%.0f', round(196.5)='%.0f', round(195.5)='%.0f'\n", 197.5, 196.5, 195.5);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 57 : rounding(197.5)='%.0f', round(196.5)='%.0f', round(195.5)='%.0f'\n", 197.5, 196.5, 195.5);
	// assert(total_chars_p == total_chars_ftp);

	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	// assert(strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) \
	&& (total_chars_p == total_chars_ftp))
		printf(ANSI_COLOR_GREEN"Test 57 (float6) : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 57 (float6) : Wrong!\n");
}

void		test_float7(void)
{
	int		total_chars_p;
	int		total_chars_ftp;
	int		fd;
	char	*returned_line_dprintf;
	char	*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 58 : round(108.765625)='%9.5f', round(108.046875)='%9.5f'\n", 108.765625, 108.046875);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 58 : round(108.765625)='%9.5f', round(108.046875)='%9.5f'\n", 108.765625, 108.046875);
	// assert(total_chars_p == total_chars_ftp);

	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	// assert(strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) \
	&& (total_chars_p == total_chars_ftp))
		printf(ANSI_COLOR_GREEN"Test 58 (float7) : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 58 (float7) : Wrong!\n");
}

void		test_float8(void)
{
	int		total_chars_p;
	int		total_chars_ftp;
	int		fd;
	char	*returned_line_dprintf;
	char	*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 59 : %%.64(0.15)='%.64f'\n", 0.15);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 59 : %%.64(0.15)='%.64f'\n", 0.15);
	// assert(total_chars_p == total_chars_ftp);

	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	// assert(strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) \
	&& (total_chars_p == total_chars_ftp))
		printf(ANSI_COLOR_GREEN"Test 59 (float8) : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 59 (float8) : Wrong!\n");
}

void		test_float9(void)
{
	int		total_chars_p;
	int		total_chars_ftp;
	int		fd;
	char	*returned_line_dprintf;
	char	*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 60 : %%.64(1.25)='%.64f', %%.2(1.25)='%.2f', %%.1(1.25)='%.1f'\n", 1.25, 1.25, 1.25);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 60 : %%.64(1.25)='%.64f', %%.2(1.25)='%.2f', %%.1(1.25)='%.1f'\n", 1.25, 1.25, 1.25);
	// assert(total_chars_p == total_chars_ftp);

	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	// assert(strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) \
	&& (total_chars_p == total_chars_ftp))
		printf(ANSI_COLOR_GREEN"Test 60 (float9) : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 60 (float9) : Wrong!\n");
}
