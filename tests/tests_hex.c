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

#include "../ft_printf.h"
#include "test_header.h"

void				test_hex1(void)
{
	char			*returned_line_dprintf;
	char			*returned_line_ft_dprintf;
	int				total_chars_p;
	int				total_chars_ftp;
	int				fd;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 22 >x : '%x'  ,  >+x: undefined behaviour but works \n", -2000);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 22 >x : '%x'  ,  >+x: undefined behaviour but works \n", -2000);
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
		printf(ANSI_COLOR_GREEN"Test 22 with %%x ,  %%+x: undefined behaviour but works : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 22 with %%x ,  %%+x: undefined behaviour : Wrong!\n");
}

void				test_hex2(void)
{
	unsigned int	num;
	char			*returned_line_dprintf;
	char			*returned_line_ft_dprintf;
	int				total_chars_p;
	int				total_chars_ftp;
	int				fd;

	num = 4294967295;
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test_23 (hex2) : %%x='%x' , %%#x='%#x',  %%x='%x', %%#*x='%#*x', '%x'\n", 0, num, 32, 17, num, -42);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test_23 (hex2) : %%x='%x' , %%#x='%#x',  %%x='%x', %%#*x='%#*x', '%x'\n", 0, num, 32, 17, num, -42);
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
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) \
	&& (total_chars_p == total_chars_ftp))
		printf(ANSI_COLOR_GREEN"Test 23 (hex2) : with %%#x and %%#*x : Correct!\n");
	else
	{
		printf(ANSI_COLOR_RED"Test 23 (hex2) : with %%#x and %%#*x : Wrong!\n");
		printf("It works correctly if I run it alone but if I run all tests then it has error\n");
		printf("After the 3rd argument when it va_arg it gets another value (like the double) not the one that want\n");
	}
}

void				test_hex3(void)
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
	total_chars_p = dprintf(fd, "Test 24 (hex3) : %%0.11='%0.11x' , %%*.15x='%x' , %%X='%X', %%.13='%.13x'\n", num, 0, num1, num);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 24 (hex3) : %%0.11='%0.11x' , %%*.15x='%x' , %%X='%X', %%.13='%.13x'\n", num, 0, num1, num);
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
		printf(ANSI_COLOR_GREEN"Test 24 (hex3) :  %%0.11x , %%*.15x , %%.13x : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 24 (hex3) :  %%0.11x , %%*.15x , %%.13x : Wrong!\n");
}

void				test_hex4(void)
{
	unsigned short	num;
	char			*returned_line_dprintf;
	char			*returned_line_ft_dprintf;
	int				total_chars_p;
	int				total_chars_ftp;
	int				fd;

	num = 65535;
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 25 >hx : '%hx' ,   >-*hx  : '%-*.2hx'   > -5x : undefined behaviour\n", num, 9, num);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 25 >hx : '%hx' ,   >-*hx  : '%-*.2hx'   > -5x : undefined behaviour\n", num, 9, num);
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
		printf(ANSI_COLOR_GREEN"Test 25 with %%hx , %%-*.2hx ,  > -5x : undefined behaviour : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 25 with %%hx , %%-*.2hx ,  > -5x : undefined behaviour : Wrong!\n");
}

void				test_hex5(void)
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
		printf(ANSI_COLOR_GREEN"Test 26 with %%020hhx and %%015hhx : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 26 with %%020hhx and %%015hhx : Wrong!\n");
}

void				test_hex6(void)
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
		printf(ANSI_COLOR_GREEN"Test 27 : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 27 : Wrong!\n");
}

void					test_hex7(void)
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
	// 	printf(ANSI_COLOR_GREEN"Test 28 (hex7) : Correct!\n");
	// else
	// 	printf(ANSI_COLOR_RED"Test 28 (hex7) : Wrong!\n");

	ft_printf(ANSI_COLOR_MAGENTA"Test 28 (hex7) : With all flags it doesnt compile so Undefined Behaviour? for %%#-08x but it works\n");
}

void					test_hex8(void)
{
	// unsigned short 		num;
	// int					total_chars_p;
	// int					total_chars_ftp;

	// num = 65535;
	// total_chars_p = printf(ANSI_COLOR_CYAN"Test_29   >hX: '%hX' ,  >0.13X: %0.13X ,  >.12X: %.12X ,  >.9X: %*.9X \n", num, num, num, 10, num);
	// total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test_29   >hX: '%hX' ,  >0.13X: %0.13X ,  >.12X: %.12X ,  >.9X: %*.9X \n", num, num, num, 10, num);
	// assert(total_chars_p == total_chars_ftp);
	// printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	// printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);
	unsigned short	num;
	char			*returned_line_dprintf;
	char			*returned_line_ft_dprintf;
	int				total_chars_p;
	int				total_chars_ftp;
	int				fd;

	num = 65535;
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test_29   >hX: '%hX' ,  >0.13X: %0.13X ,  >.12X: %.12X ,  >.9X: %*.9X \n", num, num, num, 10, num);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test_29   >hX: '%hX' ,  >0.13X: %0.13X ,  >.12X: %.12X ,  >.9X: %*.9X \n", num, num, num, 10, num);
	assert(total_chars_p == total_chars_ftp);

	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	assert(strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
		printf(ANSI_COLOR_GREEN"Test 29 (hex8) : %%020hhx and %%015hhx : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 29 (hex8) : %%020hhx and %%015hhx : Wrong!\n");
}

void					test_hex9(void)
{
	// unsigned char 		num;
	// int					total_chars_p;
	// int					total_chars_ftp;

	// num = 255;
	// total_chars_p = printf(ANSI_COLOR_CYAN"Test_30:   >09hhX : '%09hhX'   >#09hhX:  '%#09hhX'\n", num, num);
	// total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test_30:   -09hhX : '%09hhX'   -#09hhX:  '%#09hhX'\n", num, num);
	// assert(total_chars_p == total_chars_ftp);
	// printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	// printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);
	unsigned char	num;
	char			*returned_line_dprintf;
	char			*returned_line_ft_dprintf;
	int				total_chars_p;
	int				total_chars_ftp;
	int				fd;

	num = 255;
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 30 (hex9) : >09hhX : '%09hhX'   >#09hhX:  '%#09hhX'\n", num, num);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 30 (hex9) : >09hhX : '%09hhX'   >#09hhX:  '%#09hhX'\n", num, num);
	assert(total_chars_p == total_chars_ftp);

	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	assert(strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
		printf(ANSI_COLOR_GREEN"Test 30 (hex9) : %%020hhx and %%015hhx : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 30 (hex9) : %%020hhx and %%015hhx : Wrong!\n");
}

void					test_hex10(void)
{
	// unsigned long 		num;
	// int					total_chars_p;
	// int					total_chars_ftp;

	// num = 4294967295;
	// total_chars_p = printf(ANSI_COLOR_CYAN"Test_31:  0*lX : '%0*lX'\n", 15, num);
	// total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test_31:  0*lX : '%0*lX'\n", 15, num);
	// assert(total_chars_p == total_chars_ftp);
	// printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	// printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);
	unsigned long	num;
	char			*returned_line_dprintf;
	char			*returned_line_ft_dprintf;
	int				total_chars_p;
	int				total_chars_ftp;
	int				fd;

	num = 4294967295;
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 31 (hex10) :  0*lX : '%0*lX'\n", 15, num);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 31 (hex10) :  0*lX : '%0*lX'\n", 15, num);
	assert(total_chars_p == total_chars_ftp);

	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	assert(strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
		printf(ANSI_COLOR_GREEN"Test 31 (hex10) : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 31 (hex10) : Wrong!\n");
}

void					test_hex11(void)
{
	unsigned long long	num;
	// int					total_chars_p;
	int					total_chars_ftp;

	num = 18446744073709551615U;
	ft_printf(ANSI_COLOR_MAGENTA"Test_32 Error (w flags in gcc) / Warning (wo flags) >> ");
	// total_chars_p = printf(ANSI_COLOR_CYAN"32=test_hex11 space*llX : '% *llX'\n", 28, num);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test_32: space*llX : '% *llX'\n", 28, num);
	// assert(total_chars_p == total_chars_ftp);
}

void					test_hex12(void)
{
	unsigned long long	num;
	int					total_chars_p;
	int					total_chars_ftp;
	int					fd;
	char				*returned_line_dprintf;
	char				*returned_line_ft_dprintf;

	num = 123789555845795653;
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test_33 = test_hex12 %%-*llX : '%-*llX'\n", 66, num);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test_33 = test_hex12 %%-*llX : '%-*llX'\n", 66, num);
	assert(total_chars_p == total_chars_ftp);

	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	assert(strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0);

	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
		printf(ANSI_COLOR_GREEN"Test 33 with %%-*llX : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 33 with %%-*llX : Wrong!\n");
}
