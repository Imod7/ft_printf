/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests_octal.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/13 20:29:54 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/09/17 08:26:40 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

int					test_hex1(void)
{
	char			*returned_line_dprintf;
	char			*returned_line_ft_dprintf;
	int				total_chars_p;
	int				total_chars_ftp;
	int				fd;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 22 (hex1) : %%x='%x', %%+x: undefined behaviour but works \n", -2000);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 22 (hex1) : %%x='%x', %%+x: undefined behaviour but works \n", -2000);
	assert(total_chars_p == total_chars_ftp);

	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	assert(strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) \
	&& (total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_MAGENTA"Test 22 (hex1)		-> SUCCESS! UNDEFINED BEHAVIOUR\n");
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 22 (hex1) undefined behaviour : FAIL!\n");
		return (-1);
	}
}

int					test_hex2(void)
{
	unsigned int	num;
	char			*returned_line_dprintf;
	char			*returned_line_ft_dprintf;
	int				total_chars_p;
	int				total_chars_ftp;
	int				fd;

	num = 4294967295;
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 23 (hex2) : %%#x='%#x',  %%x='%x', %%#*x='%#*x', '%x'\n", num, 32, 17, num, -42);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 23 (hex2) : %%#x='%#x',  %%x='%x', %%#*x='%#*x', '%x'\n", num, 32, 17, num, -42);
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
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) \
	&& (total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 23 (hex2)		-> SUCCESS!\n");
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 23 (hex2)		-> FAIL!\n");
		printf("Before there was an error that after the 3rd argument it rinted garbage because of FAIL typecasting\n");
		return (-1);
	}
}

int					test_hex3(void)
{
	int				num1;
	int				num;
	char			*returned_line_dprintf;
	char			*returned_line_ft_dprintf;
	int				total_chars_p;
	int				total_chars_ftp;
	int				fd;

	num1 = -42;
	num = 4000;
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%0.11='%0.11x' , %%*.15x='%x' , %%X='%X', %%.13='%.13x', %%.3x='%.3x', %%0.4x='%0.4x'\n", num, 0, num1, num, 0 ,0);
	// total_chars_p = dprintf(fd, "%%.3x='%.3x', %%0.4x='%0.4x'\n", 0, 0);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%0.11='%0.11x' , %%*.15x='%x' , %%X='%X', %%.13='%.13x', %%.3x='%.3x', %%0.4x='%0.4x'\n", num, 0, num1, num, 0 ,0);
	// total_chars_ftp = ft_dprintf(fd, "%%.3x='%.3x', %%0.4x='%0.4x'\n", 0, 0);
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
		printf(ANSI_COLOR_GREEN"Test 24 (hex3) ZERO ARG	-> SUCCESS!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 24 (hex3) ZERO ARG	-> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int					test_hex4(void)
{
	// unsigned long	num;
	char			*returned_line_dprintf;
	char			*returned_line_ft_dprintf;
	int				total_chars_p;
	int				total_chars_ftp;
	int				fd;
	int				fd1;

	// num = 4294967296;
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	// printf("fd = %d\n", fd);
	// total_chars_p = dprintf(fd, "Test 25 (hex4) : %%hx='%hx', %%-*hx='%-*hx', %%-*.2hx='%-*.2hx', %%-5x='-5x' : undefined behaviour\n", num, 9, num, 9, num);
	total_chars_p = dprintf(fd, "Test 25 (hex4) : undefined behaviourhh\nYaakkjeeejjj");
	fd1 = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	// printf("fd1 = %d\n", fd1);
	// total_chars_ftp = ft_dprintf(fd, "Test 25 (hex4) : %%hx='%hx', %%-*hx='%-*hx', %%-*.2hx='%-*.2hx', %%-5x='-5x' : undefined behaviour\n", num, 9, num, 9, num);
	total_chars_ftp = ft_dprintf(fd1, "Test 25 (hex4) : undefined behaviourhh\nYaakkjeeejjj");
	// close(fd);
	// close(fd1);
	fd = open("result_dprintf.txt", O_RDONLY);
	// printf("fd = %d\n", fd);
	get_next_line(fd, &returned_line_dprintf);
	//If i put a close(fd); here it segfaults because the next fd takes the same number of the previous fd
	fd1 = open("result_ftdprintf.txt", O_RDONLY);
	// printf("fd1 = %d\n", fd1);
	get_next_line(fd1, &returned_line_ft_dprintf);
	// close(fd1);
	// assert(strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0);
	// printf("\n line = %s", returned_line_dprintf);
	// printf("\n line = %s", returned_line_ft_dprintf);
	// close(fd);
	close(fd1);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 25 (hex4)		-> SUCCESS!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 25 (hex4)	-> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int					test_hex5(void)
{
	unsigned char	num;
	char			*returned_line_dprintf;
	char			*returned_line_ft_dprintf;
	int				total_chars_p;
	int				total_chars_ftp;
	int				fd;

	num = 255;
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 26 : %%020hhx='%020hhx', %%015hhx='%015hhx', %%#X=%#X, %%#x=%#x, %%#09X=%#09X, %%#09x=%#09x\n", num, num, 5569, 241, 4788, 8899);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 26 : %%020hhx='%020hhx', %%015hhx='%015hhx', %%#X=%#X, %%#x=%#x, %%#09X=%#09X, %%#09x=%#09x\n", num, num, 5569, 241, 4788, 8899);
	// assert(total_chars_p == total_chars_ftp);
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
		printf(ANSI_COLOR_GREEN"Test 26			-> SUCCESS!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 26 (hex5)		-> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int						test_hex6(void)
{
	unsigned long long	num;
	unsigned long		num1;
	int					total_chars_p;
	int					total_chars_ftp;
	char				*returned_line_dprintf;
	char				*returned_line_ft_dprintf;
	int					fd;

	num = 4294967296;
	num1 = 4294967296;
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, ANSI_COLOR_CYAN"Test 27 (hex6) : %%lx='%lx', %%llx='%llx', %%-15x='%-15x'\n", num1, num, 542);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, ANSI_COLOR_CYAN"Test 27 (hex6) : %%lx='%lx', %%llx='%llx', %%-15x='%-15x'\n", num1, num, 542);
	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 27 		-> SUCCESS!\n");
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 27 	-> FAIL!\n");
		return (-1);
	}
}

int						test_hex7(void)
{
	// unsigned long long	num;
	// int					total_chars_p;
	// int					total_chars_ftp;
	// char				*returned_line_dprintf;
	// char				*returned_line_ft_dprintf;
	// int					fd;

	// num = 18446744073709551615U;
	// fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	// // total_chars_p = dprintf(fd, "Test 28 (hex7) : limit of unsigned long long llx : '%llx', %%#-08x='%#-08x'\n", num, 42);
	// fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	// // total_chars_ftp = ft_dprintf(fd, "Test 28 (hex7) : limit of unsigned long long llx : '%llx', %%#-08x='%#-08x'\n", num, 42);
	// // assert(total_chars_p == total_chars_ftp);

	// close(fd);
	// fd = open("result_dprintf.txt", O_RDONLY);
	// get_next_line(fd, &returned_line_dprintf);
	// close(fd);
	// fd = open("result_ftdprintf.txt", O_RDONLY);
	// get_next_line(fd, &returned_line_ft_dprintf);
	// // assert(strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0);
	// if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	// (total_chars_p == total_chars_ftp))
	// 	printf(ANSI_COLOR_GREEN"Test 28 (hex7) : SUCCESS!\n");
	// else
	// 	printf(ANSI_COLOR_RED"Test 28 (hex7) : FAIL!\n");

	ft_printf(ANSI_COLOR_MAGENTA"Test 28 (hex7) 		-> UNDEFINED BEHAVIOUR\n");
	return (0);
}

int					test_hex8(void)
{
	unsigned short	num;
	char			*returned_line_dprintf;
	char			*returned_line_ft_dprintf;
	int				total_chars_p;
	int				total_chars_ftp;
	int				fd;

	num = 65535;
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 29 (hex8) : %%hX='%hX', %%0.13X='%0.13X', %%.12X='%.12X', %%.9X='%*.9X' \n", num, num, num, 10, num);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 29 (hex8) : %%hX='%hX', %%0.13X='%0.13X', %%.12X='%.12X', %%.9X='%*.9X' \n", num, num, num, 10, num);
	// assert(total_chars_p == total_chars_ftp);

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
		printf(ANSI_COLOR_GREEN"Test 29 (hex8) 		-> SUCCESS!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 29 (hex8) 		-> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int					test_hex9(void)
{
	unsigned char	num;
	char			*returned_line_dprintf;
	char			*returned_line_ft_dprintf;
	int				total_chars_p;
	int				total_chars_ftp;
	int				fd;

	num = 255;
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%09hhX='%09hhX', \
	%%#09hhX='%#09hhX'\n", num, num);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%09hhX='%09hhX', \
	%%#09hhX='%#09hhX'\n", num, num);
	// assert(total_chars_p == total_chars_ftp);

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
		printf(ANSI_COLOR_GREEN"Test 30 (hex9)		-> SUCCESS!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 30 (hex9)		-> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int					test_hex10(void)
{
	unsigned long	num;
	char			*returned_line_dprintf;
	char			*returned_line_ft_dprintf;
	int				total_chars_p;
	int				total_chars_ftp;
	int				fd;

	num = 4294967295;
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%0*lX='%0*lX'\n", 15, num);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%0*lX='%0*lX'\n", 15, num);
	// assert(total_chars_p == total_chars_ftp);
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
		printf(ANSI_COLOR_GREEN"Test 31 (hex10) 	-> SUCCESS!\n");
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 31 (hex10)	-> FAIL!\n");
		return (-1);
	}
}

int						test_hex11(void)
{
	unsigned long long	num;
	// int					total_chars_p;
	int					total_chars_ftp;

	num = 18446744073709551615U;
	ft_printf(ANSI_COLOR_MAGENTA"Test 32 (hex11)		-> UNDEFINED BEHAVIOUR??? \n");
	// total_chars_p = printf(ANSI_COLOR_CYAN"32=test_hex11 space*llX : '% *llX'\n", 28, num);
	// total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"\nTest_32: space*llX : '% *llX'\n", 28, num);
	// assert(total_chars_p == total_chars_ftp);
	return (0);
}

int						test_hex12(void)
{
	unsigned long long	num;
	int					total_chars_p;
	int					total_chars_ftp;
	int					fd;
	char				*returned_line_dprintf;
	char				*returned_line_ft_dprintf;

	num = 123789555845795653;
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%-*llX='%-*llX', %%#.x='%#.x', %%#.0x='%#.0x', %%.x='%.x', %%.0x='%.0x', %%#x='%#x'\n", 66, num, 0, 0, 0, 0, 0);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%-*llX='%-*llX', %%#.x='%#.x', %%#.0x='%#.0x', %%.x='%.x', %%.0x='%.0x', %%#x='%#x'\n", 66, num, 0, 0, 0, 0, 0);
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
		printf(ANSI_COLOR_GREEN"Test 33 (hex12)	ZERO ARG	-> SUCCESS!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 33 (hex12) ZERO ARG	-> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int						test_hex13(void)
{
	int					total_chars_p;
	int					total_chars_ftp;
	int					fd;
	char				*returned_line_dprintf;
	char				*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%5.x='%5.x', %%5.0x='%5.0x', \
	%%5.4x='%5.4x', %%5.9x='%5.9x', %%0.9x='%0.9x', %%x='%x', %%X='%X'\n", \
	 0, 0, 0, 0, 0, 0, 0);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%5.x='%5.x', %%5.0x='%5.0x', \
	%%5.4x='%5.4x', %%5.9x='%5.9x', %%0.9x='%0.9x', %%x='%x', %%X='%X'\n", \
	 0, 0, 0, 0, 0, 0, 0);
	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 56 (hex13)	ZERO ARG -> \
		SUCCESS!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 56 (hex13) ZERO ARG	-> \
		FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int						test_hex14(void)
{
	int					total_chars_p;
	int					total_chars_ftp;
	int					fd;
	char				*returned_line_dprintf;
	char				*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%#*.*x='%#*.*x'\n", 40, 20, 142424242);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%#*.*x='%#*.*x'\n", 40, 20, 142424242);
	// printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	// printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);

	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 76 (hex14)	 -> \
		SUCCESS!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 76 (hex14) 	-> \
		FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int						test_hex15(void)
{
	int					total_chars_p;
	int					total_chars_ftp;
	int					fd;
	char				*returned_line_dprintf;
	char				*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%#.*x='%#.*x'\n", 20, 142424242);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%#.*x='%#.*x'\n", 20, 142424242);
	// printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	// printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);

	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 78 (hex15)	 -> \
		SUCCESS!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 78 (hex15) 	-> \
		FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int						test_hex16(void)
{
	int					total_chars_p;
	int					total_chars_ftp;
	int					fd;
	char				*returned_line_dprintf;
	char				*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%-#*.*x (min =5, prec =0)='%-#*.*x',\
	%%-#*.*x (min =5, prec =2)='%-#*.*x', %%-#*.*x (min =5, prec =5)='%-#*.*x',\
	%%-#*.*x (min =5, prec =8)='%-#*.*x'\n",5, 0, 0, 5, 2, 0, 5, 5, 0, 5, 8, 0);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%-#*.*x (min =5, prec =0)='%-#*.*x',\
	%%-#*.*x (min =5, prec =2)='%-#*.*x', %%-#*.*x (min =5, prec =5)='%-#*.*x',\
	%%-#*.*x (min =5, prec =8)='%-#*.*x'\n",5, 0, 0, 5, 2, 0, 5, 5, 0, 5, 8, 0);
	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 87 (hex16)	ZERO_ARG -> \
		SUCCESS!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 87 (hex16) ZERO_ARG -> \
		FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int						test_hex17(void)
{
	int					total_chars_p;
	int					total_chars_ftp;
	int					fd;
	char				*returned_line_dprintf;
	char				*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%3.3x='%3.3x', %%-3.2X='%-3.2X', \
	%%-5.X='%-5.X', %%-8.5x='%-8.5x', %%-2.0x='%-2.0x', %%-3.11x='%-3.11x'\n", \
	0, 0, 0, 0, 0, 0);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%3.3x='%3.3x', %%-3.2X='%-3.2X', \
	%%-5.X='%-5.X', %%-8.5x='%-8.5x', %%-2.0x='%-2.0x', %%-3.11x='%-3.11x'\n", \
	0, 0, 0, 0, 0, 0);
	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 110 (hex17)	ZERO_ARG -> \
		SUCCESS!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 110 (hex17) ZERO_ARG -> \
		FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int						test_hex18(void)
{
	int					total_chars_p;
	int					total_chars_ftp;
	int					fd;
	char				*returned_line_dprintf;
	char				*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%-#*.*X (MIN=5, PREC=5)='%-#*.*X', \
	%%-#3.5X='%-#3.5X', \
	%%-#7.5X='%-#7.5X', %%-#1.0X='%-#1.0X', %%-#7.4X='%-#7.4X', \
	%%-#4.0X='%-#4.0X'\n", 5, 5, 0, 0, 0, 0, 0, 0);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%-#*.*X (MIN=5, PREC=5)='%-#*.*X', \
	%%-#3.5X='%-#3.5X', \
	%%-#7.5X='%-#7.5X', %%-#1.0X='%-#1.0X', %%-#7.4X='%-#7.4X', \
	%%-#4.0X='%-#4.0X'\n", 5, 5, 0, 0, 0, 0, 0, 0);
	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 123 (hex18)	ZERO_ARG -> \
		SUCCESS!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 123 (hex18) ZERO_ARG -> \
		FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int				test_hex19(void)
{
	int			num;
	int			total_chars_p;
	int			total_chars_ftp;
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			fd;
	int			fd1;

	num = -2147483648;
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%*.*x", 25, 25, 65423000000);
	fd1 = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd1, "%*.*x", 25, 25, 65423000000);
	close(fd);
	close(fd1);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	fd1 = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd1, &returned_line_ft_dprintf);
	close(fd);
	close(fd1);
	// assert(strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 159 (hex19) 	-> SUCCESS!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 159 (hex19) 	-> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}