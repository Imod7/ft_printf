/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests_undefined_behaviour.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/28 20:21:04 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/11/28 20:21:06 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"
#include <locale.h>

int				test_undef1(void)
{
	char		c;
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			total_chars_p;
	int			total_chars_ftp;
	int			fd;

	c = 'A';
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 1 (char1) : %%2c='%2c', %%22c='%22c', %%4c='%4c'\n", c, 0, 'A');
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 1 (char1) : %%2c='%2c', %%22c='%22c', %%4c='%4c'\n", c, 0, 'A');
	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	close(fd);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 156 (undef1) 		-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_MAGENTA"Test 156 (undef1) 	-> FAIL \n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int				test_undef2(void)
{
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			total_chars_p;
	int			total_chars_ftp;
	int			fd;
	int			fd1;
	char		c;

	setlocale(LC_ALL, "en_US.UTF-8");
	c = 'B';
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "😀%%2c='%2c'\n", NULL);
	fd1 = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd1, "😀%%2c='%2c'\n", NULL);
	close(fd);
	close(fd1);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	fd1 = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd1, &returned_line_ft_dprintf);
	close(fd);
	close(fd1);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0)
	&& (total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 157 (undef2)  -> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 157 (undef2) -> FAIL!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int				test_undef3(void)
{
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			total_chars_p;
	int			total_chars_ftp;
	int			fd;
	int			fd1;
	int		    num;

	num = 74;
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%+-5o='%-5o'\n", 2500);
	fd1 = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd1, "%%+-5o='%-5o'\n", 2500);
	close(fd);
	close(fd1);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	fd1 = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd1, &returned_line_ft_dprintf);
	close(fd);
	close(fd1);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 158 (test_undef3)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 158 (test_undef3)		-> FAIL!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}