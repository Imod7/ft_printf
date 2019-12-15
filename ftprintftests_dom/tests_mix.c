/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests_mix.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 15:39:33 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/11/20 15:39:35 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

int				test_mix1(void)
{
	int			num;
	int			total_chars_p;
	int			total_chars_ftp;
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			fd;

	num = -2147483648;
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "toto %%.0d='%.0d' et %%+.i='%+.i', %%+1.i='%+1.i', %%-.i='%-.i', %%+3.i='%+3.i', %%-.0i='%-.0i'", 0, 0, 0, 0, 0, 0);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "toto %%.0d='%.0d' et %%+.i='%+.i', %%+1.i='%+1.i', %%-.i='%-.i', %%+3.i='%+3.i', %%-.0i='%-.0i'", 0, 0, 0, 0, 0, 0);
	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	close(fd);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 135 (mix1) ARGUM_ZERO	-> SUCCESS!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 135 (mix1) ARGUM_ZERO	-> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int				test_mix2(void)
{
	int			num;
	int			total_chars_p;
	int			total_chars_ftp;
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			fd;
	int			fd1;
	char 		*s = NULL;
	int			n2 = -329837;
	float 		foo = 0.9378183264;
	double 		x = 1./0;

	num = -2147483648;
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%-d, x=%f %.4s ,printf:---%-4d---% +---12.5%---%%%0004%---%+1%---END\n", n2, x, s, 10000);
	fd1 = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd1, "%-d, x=%f %.4s ,printf:---%-4d---% +---12.5%---%%%0004%---%+1%---END\n", n2, x, s, 10000);
	close(fd);
	close(fd1);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	fd1 = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd1, &returned_line_ft_dprintf);
	close(fd);
	close(fd1);
	// printf("IT ARRIVES HERE '%s'\n", returned_line_dprintf);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 161 (mix2) 	-> SUCCESS!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 161 (mix2) 	-> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}
