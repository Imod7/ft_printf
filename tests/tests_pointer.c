/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests_double.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/17 04:34:22 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/08/17 04:34:25 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

int				test_pointer1(void)
{
	int			num;
	void		*ptr;
	int			total_chars_p;
	int			total_chars_ftp;
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			fd;

	num = -586;
	ptr = &num;
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%-19p='%-19p'\n", ptr);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%-19p='%-19p'\n", ptr);
	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 37 (pointer1)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 37 (pointer1)	-> FAIL!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int				test_pointer2(void)
{
	long long	num;
	void		*ptr;
	int			total_chars_p;
	int			total_chars_ftp;
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			fd;

	num = 9223372036854775807;
	ptr = &num;
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%-*p='%-*p', %%*p='%*p'\n", 29, ptr, 16, ptr);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%-*p='%-*p', %%*p='%*p'\n", 29, ptr, 16, ptr);
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
		printf(ANSI_COLOR_GREEN"Test 38 (pointer2)	-> SUCCESS!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 38 (pointer2)	-> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int				test_pointer3(void)
{
	int			total_chars_p;
	int			total_chars_ftp;
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			fd;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%p='%p', %%5p='%5p'\n", 0, 0);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%p='%p', %%5p='%5p'\n", 0, 0);
	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 91 (pointer3)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 91 (pointer3)	-> FAIL!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int				test_pointer4(void)
{
	int			total_chars_p;
	int			total_chars_ftp;
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			fd;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%2.9p='%2.9p'\n", 1234);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%2.9p='%2.9p'\n", 1234);
	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 96 (pointer4)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 96 (pointer4)	-> FAIL!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}
