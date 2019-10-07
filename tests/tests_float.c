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

#include "test_header.h"

int				test_float1(void)
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
		printf(ANSI_COLOR_GREEN"Test 42 (float1)	: SUCCESS!\n");
	else
		printf(ANSI_COLOR_RED"Test 42 (float1)		: FAIL!\n");
}

int			test_float2(void)
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
		printf(ANSI_COLOR_GREEN"Test 44 (float2)	: SUCCESS!\n");
	else
		printf(ANSI_COLOR_RED"Test 44 (float2)		: FAIL!\n");
}

int			test_float3(void)
{
	int		total_chars_p;
	int		total_chars_ftp;
	int		fd;
	char	*returned_line_dprintf;
	char	*returned_line_ft_dprintf;
	float	num;

	num = 1.192092896e-07F;
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 45 : %%.0f='%.0f', %%.1f='%.0f', %%.2f='%.2f', %%.2f='%.2f'\n", num, num, num, 0.00001);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 45 : %%.0f='%.0f', %%.1f='%.0f', %%.2f='%.2f', %%.2f='%.2f'\n", num, num, num, 0.00001);
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
		printf(ANSI_COLOR_GREEN"Test 45 (float3)	: SUCCESS!\n");
	else
		printf(ANSI_COLOR_RED"Test 45 (float3)		: FAIL!\n");
}

int			test_float4(void)
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
		printf(ANSI_COLOR_GREEN"Test 46 (float4)	: SUCCESS!\n");
	else
		printf(ANSI_COLOR_RED"Test 46 (float4)		: FAIL!\n");
}

int			test_float5(void)
{
	int		total_chars_p;
	int		total_chars_ftp;
	double	num;
	double	num1;
	int		fd;
	char	*returned_line_dprintf;
	char	*returned_line_ft_dprintf;

	// num = 2.2204460492503131e-016;
	num = 1.24e-23;
	// num1 = 2.01234567890155;
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test_47 : %%.0f='%.0f', %%.1f='%.1f', %%.2f='%.2f', %%.6f='%.6f', %%f='%f', %%.7f='%.7f', %%f='%f', %%.30f='%.30f'\n", num, num , num, num, num1, num1, num1, num1);
	// total_chars_p = dprintf(fd, "Test_47 : %%.12f='%.12f'\n", num);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test_47 : %%.0f='%.0f', %%.1f='%.1f', %%.2f='%.2f', %%.6f='%.6f', %%f='%f', %%.7f='%.7f', %%f='%f', %%.30f='%.30f'\n", num, num , num, num, num1, num1, num1, num1);
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
		printf(ANSI_COLOR_GREEN"Test 47 (float5)	: SUCCESS!\n");
	else
		printf(ANSI_COLOR_RED"Test 47 (float5)		: FAIL!\n");
}

int			test_float6(void)
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
		printf(ANSI_COLOR_GREEN"Test 57 (float6)	: SUCCESS!\n");
	else
		printf(ANSI_COLOR_RED"Test 57 (float6)		: FAIL!\n");
}

int			test_float7(void)
{
	int		total_chars_p;
	int		total_chars_ftp;
	int		fd;
	char	*returned_line_dprintf;
	char	*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 58 : %%9.5f='%9.5f', %%9.5f='%9.5f', %%6.3f='%6.3f', %%4.8f='%4.8f'\n", 108.765975, 108.048895, 1.31072, 0.0);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 58 : %%9.5f='%9.5f', %%9.5f='%9.5f', %%6.3f='%6.3f', %%4.8f='%4.8f'\n", 108.765975, 108.048895, 1.31072, 0.0);
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
		printf(ANSI_COLOR_GREEN"Test 58 (float7)	: SUCCESS!\n");
	else
		printf(ANSI_COLOR_RED"Test 58 (float7)		: FAIL!\n");
}

int			test_float8(void)
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
		printf(ANSI_COLOR_GREEN"Test 59 (float8)	: SUCCESS!\n");
	else
		printf(ANSI_COLOR_RED"Test 59 (float8)		: FAIL!\n");
}

int			test_float9(void)
{
	int		total_chars_p;
	int		total_chars_ftp;
	int		fd;
	char	*returned_line_dprintf;
	char	*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 60 : %%.64='%.64f', %%.2='%.2f', %%.1='%.1f'\n", 1.25, 1.25, 1.25);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 60 : %%.64='%.64f', %%.2='%.2f', %%.1='%.1f'\n", 1.25, 1.25, 1.25);
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
		printf(ANSI_COLOR_GREEN"Test 60 (float9)	-> SUCCESS!\n");
	else
		printf(ANSI_COLOR_RED"Test 60 (float9)		-> FAIL!\n");
}

int			test_float10(void)
{
	int		total_chars_p;
	int		total_chars_ftp;
	int		fd;
	char	*returned_line_dprintf;
	char	*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 63 : %%-f='%-f', %%- .0f='%%- .0f', %%- .0f='%- .0f'\n", (double)42, (double)9.5, (double)-989.5);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 63 : %%-f='%-f', %%- .0f='%%- .0f', %%- .0f='%- .0f'\n", (double)42, (double)9.5, (double)-989.5);
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
	{
		printf(ANSI_COLOR_GREEN"Test 63 (float10)	-> SUCCESS!\n");
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 63 (float10)	-> FAIL!\n");
		return (-1);
	}
}

int			test_float11(void)
{
	int		total_chars_p;
	int		total_chars_ftp;
	int		fd;
	char	*returned_line_dprintf;
	char	*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 64 : %%- .0f='%- .0f'\n",  (double)-989.5);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 64 : %%- .0f='%- .0f'\n",  (double)-989.5);
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
	{
		printf(ANSI_COLOR_GREEN"Test 64 (float11)	-> SUCCESS!\n");
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 64 (float11)	-> FAIL!\n");
		return (-1);
	}
}