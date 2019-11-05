/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests_string.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 20:59:01 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/08/22 20:59:48 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

int				test_string1(void)
{
	int			total_chars_p;
	int			total_chars_ftp;
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			fd;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 43 : %%*.5s='%*.5s' , %%.2s='%.2s' , %%5.2s='%5.2s' , %s, %s\n", 5, "sarip", "four", "open source", "code", "code");
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 43 : %%*.5s='%*.5s' , %%.2s='%.2s' , %%5.2s='%5.2s' , %s, %s\n", 5, "sarip", "four", "open source", "code", "code");
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
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 43 (string1)	-> SUCCESS!\n");
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 43 (string1)	-> FAIL!\n");
		return (-1);
	}
}

int				test_string2(void)
{
	int			total_chars_p;
	int			total_chars_ftp;
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			fd;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 48 : %%-5s='%-5s' , %%-15s='%-15s' , %%.2s='%.2sair', %%5.2s='%5.2ssun'\n", "ik wil ein hund", "schilpad", "", "");
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 48 : %%-5s='%-5s' , %%-15s='%-15s' , %%.2s='%.2sair', %%5.2s='%5.2ssun'\n", "ik wil ein hund", "schilpad", "", "");
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
		printf(ANSI_COLOR_GREEN"Test 48 (string2)	-> SUCCESS!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 48 (string2)	-> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int				test_string3(void)
{
	int			total_chars_p;
	int			total_chars_ftp;
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			fd;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "'%s', '%s', %%20.*s='%20.*s'\n", NULL, \
	"super", 5, "Dit is een test");
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "'%s', '%s', %%20.*s='%20.*s'\n", NULL, \
	"super", 5, "Dit is een test");
	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 49 (string3) -> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 49 (string3)	-> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int				test_string4(void)
{
	int			total_chars_p;
	int			total_chars_ftp;
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			fd;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%5.2='%5.2s', %%-5.2s='%-5.2s'\n", "", "");
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%5.2='%5.2s', %%-5.2s='%-5.2s'\n", "", "");
	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 61 (string4)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 61 (string4)		-> FAIL!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int				test_string5(void)
{
	int			total_chars_p;
	int			total_chars_ftp;
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			fd;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%4.s='%4.s'\n", "42");
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%4.s='%4.s'\n", "42");
	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 93 (string5) 	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 93 (string5) 	-> FAIL!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int				test_string6(void)
{
	int			total_chars_p;
	int			total_chars_ftp;
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			fd;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%7.7s%7.7s", "hello", "world");
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%7.7s%7.7s", "hello", "world");
	printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);
	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 98 (string6) 	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 98 (string6) 	-> FAIL!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}