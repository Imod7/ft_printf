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

void		test_int1(void)
{
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			total_chars_p;
	int			total_chars_ftp;
	int			fd;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 01 : %%+08d='%+08d' , %%s='%s', %%c='%c' '%x'\n", 45, "coding", 'K', 18);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 01 : %%+08d='%+08d' , %%s='%s', %%c='%c' '%x'\n", 45, "coding", 'K', 18);
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
		printf(ANSI_COLOR_GREEN"Test 1 : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 1 : Wrong!\n");
}

void		test_int2(void)
{
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			total_chars_p;
	int			total_chars_ftp;
	int			fd;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 02 (int2) : %%+08d='%+08d', %%6d='%6d', %%s='%s' %% d='% d', %%+d='%+d'\n", 45, 899, "teleia", -42, -42);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 02 (int2) : %%+08d='%+08d', %%6d='%6d', %%s='%s' %% d='% d', %%+d='%+d'\n", 45, 899, "teleia", -42, -42);
	assert(total_chars_p == total_chars_ftp);

	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	// assert(strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
		printf(ANSI_COLOR_GREEN"Test 2  %%+08d , %%6d , %%s' : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 2  %%+08d , %%6d , %%s' : Wrong!\n");
}

void		test_int3(void)
{
	// total_chars_p = printf(ANSI_COLOR_CYAN"Test 3 +8d : '%+8d' \n", 55);
	// total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test 3 +8d : '%+8d' \n", 55);
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			total_chars_p;
	int			total_chars_ftp;
	int			fd;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 3 (int3) : %%+8d='%+8d' \n", 55);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd,"Test 3 (int3) : %%+8d='%+8d' \n", 55);
	// assert(total_chars_p == total_chars_ftp);

	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	assert(strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0);

	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
		printf(ANSI_COLOR_GREEN"Test 3 %%+8d : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 3 %%+8d : Wrong!\n");
}

void		test_int4(void)
{
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			total_chars_p;
	int			total_chars_ftp;
	int			fd;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 4 (int4): %%010d='%010d', %% -9d='% -9d', %% -9d='% -9d', %%9ld='%9ld' \n", 1256, 596, -99, 4294967296);

	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 4 (int4): %%010d='%010d', %% -9d='% -9d', %% -9d='% -9d', %%9ld='%9ld' \n", 1256, 596, -99, 4294967296);
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
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
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

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 5 (int5) : %%-10d='%-10d', %%05d='%05d', %%0+5d='%0+5d'\n", 199, -42, -42);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 5 (int5) : %%-10d='%-10d', %%05d='%05d', %%0+5d='%0+5d'\n", 199, -42, -42);
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
		printf(ANSI_COLOR_GREEN"Test 5 with %%-10d : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 5 with %%-10d : Wrong!\n");
}

void		test_int6(void)
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
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 6 (int6) : %%hd='%hd', %%5d='%5d', %%.10d='%.10d'\n", b, -42, -42);
	// total_chars_p = dprintf(fd, "%%.10d='%.10d'\n", -42);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 6 (int6) : %%hd='%hd', %%5d='%5d', %%.10d='%.10d'\n", b, -42, -42);
	// total_chars_ftp = ft_dprintf(fd, "%%.10d='%.10d'\n", -42);
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
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 9 : '%lld',  %%.d='%.d', %%.0d='%.0d', %%5.d='%5.d', %%5.0d='%5.0d'\n", b, 0, 0, 0, 0);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 9 : '%lld',  %%.d='%.d', %%.0d='%.0d', %%5.d='%5.d', %%5.0d='%5.0d'\n", b, 0, 0, 0, 0);
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
		printf(ANSI_COLOR_GREEN"Test 9 (int9) ZEROS : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 9 (int9) ZEROS : Wrong!\n");
}

void			test_int10(void)
{
	int			num;
	int			total_chars_p;
	int			total_chars_ftp;
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			fd;

	num = 54;
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, ANSI_COLOR_CYAN"Test 20 (int10) : %%.11d='%.11d', %%*.18d='%*.18d', %%0.14d='%0.14d', %%lld='%lld'\n", num, 33, num, num, -9223372036854775808);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, ANSI_COLOR_CYAN"Test 20 (int10) : %%.11d='%.11d', %%*.18d='%*.18d', %%0.14d='%0.14d', %%lld='%lld'\n", num, 33, num, num, -9223372036854775808);
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
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
		printf(ANSI_COLOR_GREEN"Test 20 (int10) : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 20 (int10) : Wrong!\n");
}

void			test_int11(void)
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
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 21 (int11) : %%.15d='%.15d', %%24.5d='%24.5d', %%+d='%+d', %%d='%d', %%03.2d='%03.2d'\n", num, num, 0, 0, 0);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 21 (int11) : %%.15d='%.15d', %%24.5d='%24.5d', %%+d='%+d', %%d='%d', %%03.2d='%03.2d'\n", num, num, 0, 0, 0);
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
		printf(ANSI_COLOR_GREEN"Test 21 : with %%.15d , %%24.5d : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 21 : with %%.15d , %%24.5d : Wrong!\n");
}

void			test_int12(void)
{
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			total_chars_p;
	int			total_chars_ftp;
	int			fd;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 51 (int12) : %%03.2d='%03.2d', %%-10.5d='%-10.5d', %%-6.4d='%-6.4d', %%-+10.5d='%-+10.5d', %%+10.5d='%+10.5d'\n", -1, 4242, 4242, 4242, 4242);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 51 (int12) : %%03.2d='%03.2d', %%-10.5d='%-10.5d', %%-6.4d='%-6.4d', %%-+10.5d='%-+10.5d', %%+10.5d='%+10.5d'\n", -1, 4242, 4242, 4242, 4242);
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
		printf(ANSI_COLOR_GREEN"Test 51 (int12): Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 51 (int12): Wrong!\n");
}