/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests_octal.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/13 20:29:54 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/08/13 20:29:56 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "test_header.h"

void			test_octal1(void)
{
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			total_chars_p;
	int			total_chars_ftp;
	int			fd;
	int		    num;

	num = 74;
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 17 (octal1) : %%6o='%6o', %%6o='%6lo', %%+-05o='%-05o'\n", num, 4294967296, 2500);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 17 (octal1) : %%6o='%6o', %%6o='%6lo', %%+-05o='%-05o'\n", num, 4294967296, 2500);
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
		printf(ANSI_COLOR_GREEN"Test 17 (octal1) : %%6o : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 17 (octal1) : %%6o : Wrong!\n");
}

void			test_octal2(void)
{
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			total_chars_p;
	int			total_chars_ftp;
	int			fd;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 18 (octal2) : %%05o='%05o', %%#*o(with 22)='%#*o', %%-#6o='%-#6o', %%-10.5o='%-10.5o'\n", 74, 22, 74, 2500, 2500);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 18 (octal2) : %%05o='%05o', %%#*o(with 22)='%#*o', %%-#6o='%-#6o', %%-10.5o='%-10.5o'\n", 74, 22, 74, 2500, 2500);
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
	// printf("\n'%s'\n", returned_line_dprintf);
	// printf("'%s'\n", returned_line_ft_dprintf);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
		printf(ANSI_COLOR_GREEN"Test 18 (octal2) : %%05o , %%#*o : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 18 (octal2) : %%05o , %%#*o : Wrong!\n");
}

void				test_octal3(void)
{
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			total_chars_p;
	int			total_chars_ftp;
	int			fd;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 19 (octal3) : %% 7o='% 7o', %%#6o='%#6o', %%-#6o='%-#6o'\n", 120, 2500, 2500);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 19 (octal3) : %% 7o='% 7o', %%#6o='%#6o', %%-#6o='%-#6o'\n", 120, 2500, 2500);
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
	// printf("\n'%s'\n", returned_line_dprintf);
	// printf("'%s'\n", returned_line_ft_dprintf);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
		printf(ANSI_COLOR_GREEN"Test 19 (octal3) : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 19 (octal3) : Wrong!\n");
}

void			test_octal4(void)
{
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			total_chars_p;
	int			total_chars_ftp;
	int			fd;
	int		    num;

	num = 74;
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 50 (octal4) : %%-5.10o='%-5.10o', %%-5o='%-5o', %%-5.10x='%-5.10x', %%-5x='%-5x', %%-5.10d='%-5.10d', %%-5d='%-5d', %%-5.10o='%-5.10o'\n", 2500, 2500, 2500, 2500, 2500, 2500, -55);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 50 (octal4) : %%-5.10o='%-5.10o', %%-5o='%-5o', %%-5.10x='%-5.10x', %%-5x='%-5x', %%-5.10d='%-5.10d', %%-5d='%-5d', %%-5.10o='%-5.10o'\n", 2500, 2500, 2500, 2500, 2500, 2500, -55);
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
	// printf("\n'%s'\n", returned_line_dprintf);
	// printf("'%s'\n", returned_line_ft_dprintf);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
		printf(ANSI_COLOR_GREEN"Test 50 (octal4) : %%-5.10o : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 50 (octal4) :%%-5.10o : Wrong!\n");
}

void				test_octal5(void)
{
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			total_chars_p;
	int			total_chars_ftp;
	int			fd;
	int		    num;

	num = 74;
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 53 (octal5 with ZEROS) : %%.o='%.o', %%.0o='%.0o', %%.0d='%.0d', %%.0x='%.0x', %%.0u='%.0u', %%.0X='%.0X', %%.0i='%.0i'\n", 0, 0, 0, 0, 0, 0, 0);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 53 (octal5 with ZEROS) : %%.o='%.o', %%.0o='%.0o', %%.0d='%.0d', %%.0x='%.0x', %%.0u='%.0u', %%.0X='%.0X', %%.0i='%.0i'\n", 0, 0, 0, 0, 0, 0, 0);
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
	// printf("\n'%s'\n", returned_line_dprintf);
	// printf("'%s'\n", returned_line_ft_dprintf);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
		printf(ANSI_COLOR_GREEN"Test 53 (octal5) ZEROS : %%o, %%.0o with 0 : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 53 (octal5) ZEROS : %%o, %%.0o with 0 : Wrong!\n");
}

void				test_octal6(void)
{
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			total_chars_p;
	int			total_chars_ftp;
	int			fd;
	int		    num;

	num = 74;
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 54 (octal6) : %%5.o='%5.o', %%5.0o='%5.0o', %%#.o='%#.o', %%#.0o='%#.0o', %%#.0x='%#.0x', %%o='%o'\n", 0, 0, 0, 0, 0, 0);
	// total_chars_p = dprintf(fd, "'%#.o'\n", 0);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 54 (octal6) : %%5.o='%5.o', %%5.0o='%5.0o', %%#.o='%#.o', %%#.0o='%#.0o', %%#.0x='%#.0x', %%o='%o'\n", 0, 0, 0, 0, 0, 0);
	// total_chars_ftp = ft_dprintf(fd, "'%#.o'\n", 0);
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
	// printf("\n'%s'\n", returned_line_dprintf);
	// printf("'%s'\n", returned_line_ft_dprintf);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
		printf(ANSI_COLOR_GREEN"Test 54 (octal6) ZEROS : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 54 (octal6) ZEROS : Wrong!\n");
}

void				test_octal7(void)
{
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			total_chars_p;
	int			total_chars_ftp;
	int			fd;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 62 (octal7) : %%-5.10o='%-5.10o'\n", 2500);
	// total_chars_p = dprintf(fd, "'%#.o'\n", 0);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 62 (octal7) : %%-5.10o='%-5.10o'\n", 2500);
	// total_chars_ftp = ft_dprintf(fd, "'%#.o'\n", 0);
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
	// printf("\n'%s'\n", returned_line_dprintf);
	// printf("'%s'\n", returned_line_ft_dprintf);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
		printf(ANSI_COLOR_GREEN"Test 62 (octal7) : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 62 (octal7) : Wrong!\n");
}