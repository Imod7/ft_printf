/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests_binary.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/21 11:30:33 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/11/21 11:30:36 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

int				test_binary1(void)
{
	char		*returned_line_ft_dprintf;
	int			total_chars_ftp;
	int			fd;

	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test binary : %%09.6b='%09.6b'\n", -18);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	close(fd);
	printf(ANSI_COLOR_GREEN"Test 139 	(bin1)	BONUS\n"ANSI_COLOR_RESET);
	printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
	return (0);
}

int				test_binary2(void)
{
	char		*returned_line_ft_dprintf;
	int			total_chars_ftp;
	int			fd;

	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test binary : %%070.6llB='%070.6llB'\n", 18446744073709551611);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	close(fd);
		printf(ANSI_COLOR_GREEN"Test 140 	(bin2)	BONUS\n"ANSI_COLOR_RESET);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
}

int				test_binary3(void)
{
	// char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	// int			total_chars_p;
	int			total_chars_ftp;
	int			fd;

	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test binary : %%070.6lB='%070.6lB'\n", 4294967295);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	close(fd);
	printf(ANSI_COLOR_GREEN"Test 141 	(binary3)	BONUS\n"ANSI_COLOR_RESET);
	printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
	return (0);
}

int				test_binary4(void)
{
	// char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	// int			total_chars_p;
	int			total_chars_ftp;
	int			fd;

	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test binary : %%llB='%llB', %%3b (zero arg)= '%3b', %%3B (zero arg)= '%3B', %%b (zero arg)= '%b', %%B (zero arg)= '%B'\n", (unsigned long long)18446744073709551615, 0, 0, 0, 0);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	close(fd);
	printf(ANSI_COLOR_GREEN"Test 169	(binary4)	BONUS\n"ANSI_COLOR_RESET);
	printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
	return (0);
}
