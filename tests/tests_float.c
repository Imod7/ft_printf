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
	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 42 (float1)	-> SUCCESS!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 42 (float1)	-> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
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
	{
		printf(ANSI_COLOR_GREEN"Test 44 (float2)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 44 (float2)	-> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
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
	{
		printf(ANSI_COLOR_GREEN"Test 45 (float3)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 45 (float3)	-> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
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
	total_chars_p = dprintf(fd, "%%.0f='%.0f', %%.1f='%.1f', %%.2f='%.2f', %%.6f='%.6f', %%f='%f', %%.7f='%.7f'\n", numd, numd, numd, numd, numd, numd);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%.0f='%.0f', %%.1f='%.1f', %%.2f='%.2f', %%.6f='%.6f', %%f='%f', %%.7f='%.7f'\n", numd, numd, numd, numd, numd, numd);
	// assert(total_chars_p == total_chars_ftp);
	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	// assert(strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && (total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 46 (float4)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 46 (float4)	-> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
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
	total_chars_p = dprintf(fd, "%%.0f='%.0f', %%.1f='%.1f', %%.2f='%.2f', \
	%%.6f='%.6f', %%f='%f', %%.7f='%.7f', %%f='%f', %%.30f='%.30f'\n", num, num, num, num, num1, num1, num1, num1);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%.0f='%.0f', %%.1f='%.1f', %%.2f='%.2f', \
	%%.6f='%.6f', %%f='%f', %%.7f='%.7f', %%f='%f', %%.30f='%.30f'\n", num, num, num, num, num1, num1, num1, num1);
	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) \
	&& (total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 47 (float5)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 47 (float5)	-> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
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
	total_chars_p = dprintf(fd, "Checks: %%.0f rounding(197.5)='%.0f', %%.0f round(196.5)='%.0f', %%.0f round(195.5)='%.0f'\n", 197.5, 196.5, 195.5);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Checks: %%.0f rounding(197.5)='%.0f', %%.0f round(196.5)='%.0f', %%.0f round(195.5)='%.0f'\n", 197.5, 196.5, 195.5);
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
		printf(ANSI_COLOR_GREEN"Test 57 (float6)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 57 (float6)	-> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int			test_float7(void)
{
	int		total_chars_p;
	int		total_chars_ftp;
	int		fd;
	char	*returned_line_dprintf;
	char	*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%9.5f='%9.5f', %%9.5f='%9.5f', %%6.3f='%6.3f', %%4.8f='%4.8f'\n", 108.765975, 108.048895, 1.31072, 0.0);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%9.5f='%9.5f', %%9.5f='%9.5f', %%6.3f='%6.3f', %%4.8f='%4.8f'\n", 108.765975, 108.048895, 1.31072, 0.0);
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
		printf(ANSI_COLOR_GREEN"Test 58 (float7)	-> SUCCESS!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 58 (float7)		-> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
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
	{
		printf(ANSI_COLOR_GREEN"Test 59 (float8)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 59 (float8)	-> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int			test_float9(void)
{
	int		total_chars_p;
	int		total_chars_ftp;
	int		fd;
	char	*returned_line_dprintf;
	char	*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%.64='%.64f', %%.2='%.2f', \
	%%.1='%.1f'\n", 1.25, 1.25, 1.25);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%.64='%.64f', %%.2='%.2f', \
	%%.1='%.1f'\n", 1.25, 1.25, 1.25);
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
		printf(ANSI_COLOR_GREEN"Test 60 (float9)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 60 (float9)	-> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int			test_float10(void)
{
	int		total_chars_p;
	int		total_chars_ftp;
	int		fd;
	char	*returned_line_dprintf;
	char	*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%-f='%-f', %%- .0f='%%- .0f', \
	%%- .0f='%- .0f'\n", (double)42, (double)9.5, (double)-989.5);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%-f='%-f', %%- .0f='%%- .0f', \
	%%- .0f='%- .0f'\n", (double)42, (double)9.5, (double)-989.5);
	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) \
	&& (total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 63 (float10)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 63 (float10)	-> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
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
	total_chars_p = dprintf(fd, "%%- .0f='%- .0f', %%20.10f='%20.10f'\n",\
	(double)-989.5, (double)-((double)10 / 3));
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%- .0f='%- .0f', %%20.10f='%20.10f'\n",\
	(double)-989.5, (double)-((double)10 / 3));
	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) \
	&& (total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 64 (float11)	-> SUCCESS!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 64 (float11)	-> FAIL!\n");
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int			test_float12(void)
{
	int		total_chars_p;
	int		total_chars_ftp;
	int		fd;
	char	*returned_line_dprintf;
	char	*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%-20.10f='%-20.10f', %%020.10f='%020.10f'\n",  (double)-((double)10 / 3), (double)-((double)10 / 3));
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%-20.10f='%-20.10f', %%020.10f='%020.10f'\n",  (double)-((double)10 / 3), (double)-((double)10 / 3));
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
		printf(ANSI_COLOR_GREEN"Test 65 (float12)	-> SUCCESS!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 65 (float12)	-> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int			test_float13(void)
{
	int		total_chars_p;
	int		total_chars_ftp;
	int		fd;
	char	*returned_line_dprintf;
	char	*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%-f='%-f'\n",  -1.0 / 0.0);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%-f='%-f'\n",  -1.0 / 0.0);
	// assert(total_chars_p == total_chars_ftp);

	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	// assert(strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0)
	&& (total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 66 (float13)	-> SUCCESS!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 66 (float13)	-> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int			test_float14(void)
{
	int		total_chars_p;
	int		total_chars_ftp;
	int		fd;
	char	*returned_line_dprintf;
	char	*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%-10.10f='%-10.10f'\n",  -1.0 / 0.0);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%-10.10f='%-10.10f'\n",  -1.0 / 0.0);
	// assert(total_chars_p == total_chars_ftp);
	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	// assert(strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0)
	&& (total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 67 (float14)	-> SUCCESS!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 67 (float14)	-> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int			test_float15(void)
{
	int		total_chars_p;
	int		total_chars_ftp;
	int		fd;
	char	*returned_line_dprintf;
	char	*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%-f='%-f'\n",  1.0 / 0.0);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%-f='%-f'\n",  1.0 / 0.0);
	// assert(total_chars_p == total_chars_ftp);

	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	// assert(strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0)
	&& (total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 68 (float15)	-> SUCCESS!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 68 (float15)	-> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int			test_float16(void)
{
	int		total_chars_p;
	int		total_chars_ftp;
	int		fd;
	char	*returned_line_dprintf;
	char	*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%-f='%-f'\n",  0.0 / 0.0);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%-f='%-f'\n",  0.0 / 0.0);
	// assert(total_chars_p == total_chars_ftp);

	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	// assert(strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0)
	&& (total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 69 (float16)	-> SUCCESS!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 69 (float16)	-> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int			test_float17(void)
{
	int		total_chars_p;
	int		total_chars_ftp;
	int		fd;
	char	*returned_line_dprintf;
	char	*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%10.10f='%10.10f', %%10.10f='%10.10f', %%10.10f='%10.10f'\n",  -1.0 / 0.0, 1.0 / 0.0, 0.0 / 0.0);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%10.10f='%10.10f', %%10.10f='%10.10f', %%10.10f='%10.10f'\n",  -1.0 / 0.0, 1.0 / 0.0, 0.0 / 0.0);
	// assert(total_chars_p == total_chars_ftp);
	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	// assert(strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0)
	&& (total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 70 (float17)	-> SUCCESS!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 70 (float17)	-> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int			test_float18(void)
{
	int		total_chars_p;
	int		total_chars_ftp;
	int		fd;
	char	*returned_line_dprintf;
	char	*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%-Lf='%-Lf'\n", (long double)42);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%-Lf='%-Lf'\n", (long double)42);
	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0)
	&& (total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 79 (float18)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 79 (float18)	-> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int			test_float19(void)
{
	int		total_chars_p;
	int		total_chars_ftp;
	int		fd;
	char	*returned_line_dprintf;
	char	*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%f='%f'\n", -5.9999999);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%f='%f'\n", -5.9999999);
	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0)
	&& (total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 115 (float19)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 115 (float19)   -> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int			test_float20(void)
{
	int		total_chars_p;
	int		total_chars_ftp;
	int		fd;
	char	*returned_line_dprintf;
	char	*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%-+.50Lf='%-+.50Lf'\n", \
	(long double)((long double)10 / 3));
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%-+.50Lf='%-+.50Lf'\n", \
	(long double)((long double)10 / 3));
	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0)
	&& (total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 116 (float20)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 116 (float20)   -> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int			test_float21(void)
{
	int		total_chars_p;
	int		total_chars_ftp;
	int		fd;
	char	*returned_line_dprintf;
	char	*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%.3Lf='%.3Lf', %%.8Lf='%.8Lf'\n", LDBL_MIN, LDBL_MIN);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%.3Lf='%.3Lf', %%.8Lf='%.8Lf'\n", LDBL_MIN, LDBL_MIN);
	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0)
	&& (total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 117 (float21)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 117 (float21)   -> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int			test_float22(void)
{
	int		total_chars_p;
	int		total_chars_ftp;
	int		fd;
	char	*returned_line_dprintf;
	char	*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%.550lf='%.550lf', %%.950Lf='%.950Lf'\n", -DBL_TRUE_MIN, -LDBL_MIN);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%.550lf='%.550lf', %%.950Lf='%.950Lf'\n", -DBL_TRUE_MIN, -LDBL_MIN);
	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0)
	&& (total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 118 (float22)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 118 (float22)   -> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int			test_float23(void)
{
	int		total_chars_p;
	int		total_chars_ftp;
	int		fd;
	char	*returned_line_dprintf;
	char	*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%#.0f='%#.0f', %%.1f='%.1f', %%.1f='%.1f', %%.1f='%.1f'\n", -7.4, -3.85, 1.95, 2.65);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%#.0f='%#.0f', %%.1f='%.1f', %%.1f='%.1f', %%.1f='%.1f'\n", -7.4, -3.85, 1.95, 2.65);
	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0)
	&& (total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 119 (float23)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 119 (float23)   -> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int			test_float24(void)
{
	int		total_chars_p;
	int		total_chars_ftp;
	int		fd;
	char	*returned_line_dprintf;
	char	*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Il fait au moins %f\n", (double)-8000);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Il fait au moins %f\n", (double)-8000);
	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0)
	&& (total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 121 (float24)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 121 (float24)   -> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int			test_float25(void)
{
	int		total_chars_p;
	int		total_chars_ftp;
	int		fd;
	char	*returned_line_dprintf;
	char	*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%.0f='%.0f', %%5.0f='%5.0f'\n", 0.000039, \
	-7.3);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%.0f='%.0f', %%5.0f='%5.0f'\n", 0.000039, \
	-7.3);
	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0)
	&& (total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 122 (float25)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 122 (float25)   -> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}