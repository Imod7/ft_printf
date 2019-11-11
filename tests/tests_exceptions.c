/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests_exceptions.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 00:07:04 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/08/19 00:07:09 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

int				test_exceptions1(void)
{
	int			total_chars_p;
	int			total_chars_ftp;
	int			fd;
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "'%%', %%kjjj='%kjjj',  %% -9k='% -9k'  exc='%      %', ex1='%  %'\n", 74, "test");
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "'%%', %%kjjj='%kjjj',  %% -9k='% -9k'  exc='%      %', ex1='%  %'\n", 74, "test");
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
		printf(ANSI_COLOR_GREEN"Test 39 (exceptions)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 39 (exceptions)	-> FAIL!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int				test_exceptions2(void)
{
	int		    num;

	num = 74;
	ft_printf(ANSI_COLOR_MAGENTA"Test 41 		-> UNDEFINED BEHAVIOUR\n");
	// total_chars_p = printf(ANSI_COLOR_RED"Test_41   >percentpercent   : '%%'     >15-mk   : '%15-mkjjj'  ,  >space9-v: '% 9-v'\n", num);
	// total_chars_ftp = ft_printf(ANSI_COLOR_RED"Test_41   >percentpercent   : '%%'     >15-mk   : '%15-mkjjj'  ,  >space9-v: '% 9-v'\n", num);
	// assert(total_chars_p == total_chars_ftp);
	// printf(ANSI_COLOR_MAGENTA"total_chars_p   = %d \n", total_chars_p);
	// printf(ANSI_COLOR_MAGENTA"total_chars_ftp = %d \n", total_chars_ftp);
}

int				test_exceptions3(void)
{
	int			total_chars_p;
	int			total_chars_ftp;
	int			fd;
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%www='%www', '%'\n", 74);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%www='%www', '%'\n");
	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 94 (exceptions)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 94 (exceptions)	-> FAIL!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int				test_exceptions4(void)
{
	int			total_chars_p;
	int			total_chars_ftp;
	int			fd;
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%");
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%");
	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	if ((returned_line_dprintf == 0) && (returned_line_ft_dprintf == 0) && \
	(total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 95 (exceptions4)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 95 (exceptions4)	-> FAIL!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int				test_exceptions5(void)
{
	int			total_chars_p;
	int			total_chars_ftp;
	int			fd;
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%5");
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	// total_chars_ftp = ft_dprintf(fd, "%%5='%5'");
	total_chars_ftp = ft_dprintf(fd, "%5");
	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	if ((returned_line_dprintf == 0) && (returned_line_ft_dprintf == 0) && \
	(total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 97 (exceptions5)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 97 (exceptions5)	-> FAIL!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}