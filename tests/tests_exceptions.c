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

#include "../ft_printf.h"
#include "test_header.h"

void			test_exceptions1(void)
{
	int					total_chars_p;
	int					total_chars_ftp;
	int					fd;
	char				*returned_line_dprintf;
	char				*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 39 (exceptions) : '%%', %%kjjj='%kjjj',  %% -9k='% -9k'  exc='%      %', ex1='%  %'\n", 74);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 39 (exceptions) : '%%', %%kjjj='%kjjj',  %% -9k='% -9k'  exc='%      %', ex1='%  %'\n", 74);
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
		printf(ANSI_COLOR_GREEN"Test 39 (exceptions) : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test 39 (exceptions) : Wrong!\n");
}

void			test_exceptions2(void)
{
	int		    num;
	// int			total_chars_p;
	// int			total_chars_ftp;

	num = 74;
	ft_printf(ANSI_COLOR_MAGENTA"Test 41 Undefined Behaviour\n");
	// total_chars_p = printf(ANSI_COLOR_RED"Test_41   >percentpercent   : '%%'     >15-mk   : '%15-mkjjj'  ,  >space9-v: '% 9-v'\n", num);
	// total_chars_ftp = ft_printf(ANSI_COLOR_RED"Test_41   >percentpercent   : '%%'     >15-mk   : '%15-mkjjj'  ,  >space9-v: '% 9-v'\n", num);
	// assert(total_chars_p == total_chars_ftp);
	// printf(ANSI_COLOR_MAGENTA"total_chars_p   = %d \n", total_chars_p);
	// printf(ANSI_COLOR_MAGENTA"total_chars_ftp = %d \n", total_chars_ftp);
}
