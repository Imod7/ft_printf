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
	// char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	// int			total_chars_p;
	int			total_chars_ftp;
	int			fd;

	// fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	// total_chars_p = dprintf(fd, "Test binary : %%b='%b'\n", 18);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test binary : %%070.6llB='%070.6llB'\n", 18446744073709551611);
	// total_chars_ftp = ft_dprintf(fd, "Test binary : %%09.6B='%09.6B'\n", 12345);
	// close(fd);
	// fd = open("result_dprintf.txt", O_RDONLY);
	// get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	close(fd);
	// if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	// (total_chars_p == total_chars_ftp))
	// {
		printf(ANSI_COLOR_GREEN"Test 140 	(bin2)	BONUS\n"ANSI_COLOR_RESET);
		// printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	// }
	// else
	// {
	// 	printf(ANSI_COLOR_RED"Test 1 (bin1) -> FAIL!\n"ANSI_COLOR_RESET);
	// 	printf("printf    : [%s]\n", returned_line_dprintf);
	// 	printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
	// 	return (-1);
	// }
}

int				test_binary3(void)
{
	// char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	// int			total_chars_p;
	int			total_chars_ftp;
	int			fd;

	// fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	// total_chars_p = dprintf(fd, "Test binary : %%b='%b'\n", 18);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test binary : %%070.6lB='%070.6lB'\n", 4294967295);
	// total_chars_ftp = ft_dprintf(fd, "Test binary : %%070.6lu='%070.6lu'\n", 4294967295);
	// total_chars_ftp = ft_dprintf(fd, "Test binary : %%09.6B='%09.6B'\n", 12345);
	// close(fd);
	// fd = open("result_dprintf.txt", O_RDONLY);
	// get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	close(fd);
	// if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	// (total_chars_p == total_chars_ftp))
	// {
		printf(ANSI_COLOR_GREEN"Test 141 	(binary3)	BONUS\n"ANSI_COLOR_RESET);
		// printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	// }
	// else
	// {
	// 	printf(ANSI_COLOR_RED"Test 1 (bin1) -> FAIL!\n"ANSI_COLOR_RESET);
	// 	printf("printf    : [%s]\n", returned_line_dprintf);
	// 	printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
	// 	return (-1);
	// }
}
