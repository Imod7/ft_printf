/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/09 00:20:25 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/08/09 00:24:25 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "test_header.h"

void		test_one(void)
{
	int		total_chars_p;
	int		total_chars_ftp;

	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"'Test 1 : with the number '%+08d' and the string '%s' and the char '%c'\n", 45, "coding", 'K');
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"'Test 1 : with the number '%+08d' and the string '%s' and the char '%c'\n", 45, "coding", 'K');
	// assert(total_chars_p == total_chars_ftp);
	printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);
}

void		test_two(void)
{
	// int		total_chars_p;
	// int		total_chars_ftp;

	// write(1, "\n", 1);
	// total_chars_p = printf(ANSI_COLOR_CYAN"Test 2 +08d : '%+08d' blabla  '%6d' glopglop '%s'\n", 45, 899, "teleia");
	// total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test 2 +08d : '%+08d' blabla  '%6d' glopglop '%s'\n", 45, 899, "teleia");
	// assert(total_chars_p == total_chars_ftp);
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			total_chars_p;
	int			total_chars_ftp;
	int			fd;

	write(1, "\n", 1);
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 2 +08d : '%+08d' blabla  '%6d' glopglop '%s'\n", 45, 899, "teleia");
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 2 +08d : '%+08d' blabla  '%6d' glopglop '%s'\n", 45, 899, "teleia");
	assert(total_chars_p == total_chars_ftp);

	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);

	// assert(strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0);

	if (strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0)
		printf(ANSI_COLOR_GREEN"Test 2  %%+08d , %%6d , %%s' : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 2  %%+08d , %%6d , %%s' : Wrong!\n");
}

void		test_three(void)
{
	// total_chars_p = printf(ANSI_COLOR_CYAN"Test 3 +8d : '%+8d' \n", 55);
	// total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test 3 +8d : '%+8d' \n", 55);
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			total_chars_p;
	int			total_chars_ftp;
	int			fd;

	write(1, "\n", 1);
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 3 +8d : '%+8d' \n", 55);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd,"Test 3 +8d : '%+8d' \n", 55);
	assert(total_chars_p == total_chars_ftp);

	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);

	assert(strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0);

	if (strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0)
		printf(ANSI_COLOR_GREEN"Test 3 %%+8d : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 3 %%+8d : Wrong!\n");
}

void		test_int4(void)
{
	// int		total_chars_p;
	// int		total_chars_ftp;

	// write(1, "\n", 1);
	// total_chars_p = printf(ANSI_COLOR_CYAN"Test_4   >010d : '%010d'  > -9d : '% -9d'  > -9d negat value : '% -9d' \n", 1256, 596, -99);
	// total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test_4   >010d : '%010d'  > -9d : '% -9d'  > -9d negat value : '% -9d' \n", 1256, 596, -99);
	// assert(total_chars_p == total_chars_ftp);
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			total_chars_p;
	int			total_chars_ftp;
	int			fd;

	write(1, "\n", 1);
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test_4  '%010d' , '% -9d' , '% -9d' \n", 1256, 596, -99);

	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test_4  '%010d' , '% -9d' , '% -9d' \n", 1256, 596, -99);
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
	// printf("\n'%s'\n", returned_line_dprintf);
	// printf("'%s'\n", returned_line_ft_dprintf);
	if (strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0)
		printf(ANSI_COLOR_GREEN"Test_4 with %%010d, %%space-9d and %%space-9d negat value : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test_4 with %%010d, %%space-9d and %%space-9d negat value : Wrong!\n");
}

void		test_int5(void)
{
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			total_chars_p;
	int			total_chars_ftp;
	int			fd;

	write(1, "\n", 1);
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 5 '%-10d'\n", 199);

	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 5 '%-10d'\n", 199);
	assert(total_chars_p == total_chars_ftp);

	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);

	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	assert(strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0);

	if (strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0)
		printf(ANSI_COLOR_GREEN"Test 5 with %%-10d : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 5 with %%-10d : Wrong!\n");
}

void		test_six(void)
{
	int			a;
	short		b;
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			total_chars_p;
	int			total_chars_ftp;
	int			fd;

	a = 32761;
	b = (short)a;
	write(1, "\n", 1);
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 6  '%hd'  \n", b);
	get_next_line(fd, &returned_line_dprintf);

	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 6  '%hd'  \n", b);
	assert(total_chars_p == total_chars_ftp);

	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);

	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	assert(strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0);

	if (strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0)
		printf(ANSI_COLOR_GREEN"Test 6 with %%hd : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 6 with %%hd : Wrong!\n");
}

void			test_int7(void)
{
	// int			a;
	// signed char	b;
	// int			total_chars_p;
	// int			total_chars_ftp;

	// a = 125;
	// b = (signed char)a;
	// write(1, "\n", 1);
	// total_chars_p = printf(ANSI_COLOR_CYAN"Test 7   >hhd : '%hhd'    >-15hhd : '%-15hhd'\n", b, b);
	// total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test 7   >hhd : '%hhd'    >-15hhd : '%-15hhd'\n", b, b);
	// assert(total_chars_p == total_chars_ftp);

	int				a;
	signed char		b;
	char			*returned_line_dprintf;
	char			*returned_line_ft_dprintf;
	int				total_chars_p;
	int				total_chars_ftp;
	int				fd;

	a = 125;
	b = (signed char)a;
	write(1, "\n", 1);
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 7 :  '%hhd' , '%-15hhd'\n", b, b);
	get_next_line(fd, &returned_line_dprintf);

	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 7 :  '%hhd' , '%-15hhd'\n", b, b);
	assert(total_chars_p == total_chars_ftp);

	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);

	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	assert(strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0);

	if (strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0)
		printf(ANSI_COLOR_GREEN"Test 7 with %%hhd and %%-15hhd : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 7 with %%hhd and %%-15hhd : Wrong!\n");
}

void			test_int8(void)
{
	// int			a;
	// long		b;
	// int			total_chars_p;
	// int			total_chars_ftp;

	// a = 6552231;
	// b = (long)a;
	// write(1, "\n", 1);
	// total_chars_p = printf(ANSI_COLOR_CYAN"Test 8 ld : '%ld'\n", b);
	// total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test 8 ld : '%ld'\n", b);
	// assert(total_chars_p == total_chars_ftp);

	int			a;
	long		b;
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			total_chars_p;
	int			total_chars_ftp;
	int			fd;

	a = 6552231;
	b = (long)a;
	write(1, "\n", 1);
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 8 '%ld'\n", b);
	get_next_line(fd, &returned_line_dprintf);

	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 8 '%ld'\n", b);
	assert(total_chars_p == total_chars_ftp);

	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);

	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	assert(strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0);

	if (strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0)
		printf(ANSI_COLOR_GREEN"Test 8 : with %%ld : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 8 : with %%ld : Wrong!\n");
}

void			test_int9(void)
{
	// int			a;
	// long long	b;
	// int			total_chars_p;
	// int			total_chars_ftp;

	// a = 2788999;
	// b = (long long)a;
	// write(1, "\n", 1);
	// total_chars_p = printf(ANSI_COLOR_CYAN"Test 9 lld : '%lld'\n", b);
	// total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test 9 lld : '%lld'\n", b);
	// assert(total_chars_p == total_chars_ftp);
	int			a;
	long long	b;
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			total_chars_p;
	int			total_chars_ftp;
	int			fd;

	a = 2788999;
	b = (long long)a;
	write(1, "\n", 1);
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 9 : '%lld'\n", b);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 9 : '%lld'\n", b);
	assert(total_chars_p == total_chars_ftp);

	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	assert(strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0);

	if (strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0)
		printf(ANSI_COLOR_GREEN"Test 9 : with %%lld : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 9 : with %%lld : Wrong!\n");
}

void			test_ten(void)
{
	char		c;

	c = 'A';
	write(1, "\n", 1);
	ft_printf(ANSI_COLOR_MAGENTA"Test 10  with %%+c Undefined Behaviour");
	// printf(ANSI_COLOR_CYAN"Test 10 +c THE PRINTF : '%+c'\n", c);
	// ft_printf(ANSI_COLOR_YELLOW"Test 10 +c MY  PRINTF : '%+c'\n", c);
}

void			test_eleven(void)
{
	char		c;
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			total_chars_p;
	int			total_chars_ftp;
	int			fd;

	c = 'G';
	write(1, "\n", 1);
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 11 : '%-8c'\n", c);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 11 : '%-8c'\n", c);
	assert(total_chars_p == total_chars_ftp);

	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	assert(strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0);

	if (strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0)
		printf(ANSI_COLOR_GREEN"Test 11 : with %%-8c : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 11 : with %%-8c : Wrong!\n");
	// printf(ANSI_COLOR_RED"\n'%s'\n", returned_line_dprintf);
	// printf("'%s'\n", returned_line_ft_dprintf);
}

void			test_twelve(void)
{
	char		c;

	c = 'K';
	write(1, "\n", 1);
	ft_printf(ANSI_COLOR_MAGENTA"Test 12  with %%-0c Undefined Behaviour");
	// printf(ANSI_COLOR_CYAN"Test 12 -0c THE PRINTF : '%-0c'\n", c);
}

void			test_thirteen(void)
{
	char		c;

	c = 'M';
	ft_printf(ANSI_COLOR_MAGENTA"Test 13  with %%hc Undefined Behaviour");
	// printf(ANSI_COLOR_CYAN"Test 13 hc THE PRINTF : '%hc'\n", c);
	// ft_printf(ANSI_COLOR_YELLOW"Test 13 hc MY  PRINTF : '%hc'\n\n", c);
}

void			test_fourteen(void)
{
	char		c;

	c = 'G';
	write(1, "\n", 1);
	ft_printf(ANSI_COLOR_MAGENTA"Test 14  with %%hhc Undefined Behaviour");
	// printf(ANSI_COLOR_CYAN"Test 14 hhc THE PRINTF : '%hhc'\n", c);
	// ft_printf(ANSI_COLOR_YELLOW"Test 14 hhc MY  PRINTF : '%hhc'\n\n", c);
}

void			test_fifteen(void)
{
	// char		c;
	// int			total_chars_p;
	// int			total_chars_ftp;

	// c = 'B';
	// total_chars_p = printf(ANSI_COLOR_CYAN"Test 15 9lc : '%9lc'\n", c);
	// total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test 15 9lc : '%9lc'\n", c);
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			total_chars_p;
	int			total_chars_ftp;
	int			fd;
	char		c;

	c = 'B';
	write(1, "\n", 1);
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 15 9lc : '%9lc'\n", c);

	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 15 9lc : '%9lc'\n", c);
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
	// printf("\n'%s'\n", returned_line_dprintf);
	// printf("'%s'\n", returned_line_ft_dprintf);
	if (strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0)
		printf(ANSI_COLOR_GREEN"Test_15 with %%9lc : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test_15 with %%9lc : Wrong!\n");
}

void			test_16(void)
{
	char		c;

	c = 'C';
	write(1, "\n", 1);
	ft_printf(ANSI_COLOR_MAGENTA"Test 16 Error/Warning >> ");
	// printf(ANSI_COLOR_CYAN"Test 16 4llc THE PRINTF : '%4llc'\n", c);
	ft_printf(ANSI_COLOR_YELLOW"Test 16 4llc MY  PRINTF : '%4llc'\n\n", c);
}

void			test_20(void)
{
	int			num;
	int			total_chars_p;
	int			total_chars_ftp;

	num = 54;
	write(1, "\n", 1);
	total_chars_p = printf(ANSI_COLOR_CYAN"Test 20   >.11d : '%.11d'   >*.18d: '%*.18d'   >0.14d   '%0.14d'\n", num, 33, num, num);
	total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test 20   >.11d : '%.11d'   >*.18d: '%*.18d'   >0.14d   '%0.14d'\n", num, 33, num, num);
	assert(total_chars_p == total_chars_ftp);
	// printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	// printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);
}

void			test_21(void)
{
	// int			num;
	// int			total_chars_p;
	// int			total_chars_ftp;

	// num = 88;
	// write(1, "\n", 1);
	// total_chars_p = printf(ANSI_COLOR_CYAN"Test 21 .15d : '%.15d'  >24.5d    '%24.5d'\n", num, num);
	// total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test 21 .15d : '%.15d'  >24.5d    '%24.5d'\n", num, num);
	// assert(total_chars_p == total_chars_ftp);
	int			num;
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			total_chars_p;
	int			total_chars_ftp;
	int			fd;

	num = 88;
	write(1, "\n", 1);
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 21 .15d : '%.15d'  >24.5d    '%24.5d'\n", num, num);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 21 .15d : '%.15d'  >24.5d    '%24.5d'\n", num, num);
	assert(total_chars_p == total_chars_ftp);

	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	assert(strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0);

	if (strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0)
		printf(ANSI_COLOR_GREEN"Test 21 : with %%.15d , %%24.5d : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 21 : with %%.15d , %%24.5d : Wrong!\n");
}
