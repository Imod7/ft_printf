/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests_char.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/15 12:22:51 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/09/15 12:22:59 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

int				test_char1(void)
{
	char		c;
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			total_chars_p;
	int			total_chars_ftp;
	int			fd;

	c = 'A';
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 10 (char1) : %%+c='%+c', %%2c='%2c', %% c='% c', %% c='% c'\n", c, 0, 0, 'D');
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 10 (char1) : %%+c='%+c', %%2c='%2c', %% c='% c', %% c='% c'\n", c, 0, 0, 'D');
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
		printf(ANSI_COLOR_GREEN"Test 10 (char1) 		-> SUCCESS!\n");
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_MAGENTA"Test 10 (char1) 	-> FAIL from strcmp but SUCCESS in 42 Filehecker!\n");
		return (-1);
	}
}

int				test_char2(void)
{
	char		c;
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			total_chars_p;
	int			total_chars_ftp;
	int			fd;

	c = 'G';
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	// total_chars_p = dprintf(fd, "Test 11 (char2) : %%-8c='%-8c', %%.2c='%.2c', %% c='% c', %%2c='%2c'\n", c, NULL, 0, 0);
	total_chars_p = dprintf(fd, "Test 11 (char2) : %%-8c='%-8c'\n", c);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	// total_chars_ftp = ft_dprintf(fd, "Test 11 (char2) : %%-8c='%-8c', %%.2c='%.2c', %% c='% c', %%2c='%2c'\n", c, NULL, 0, 0);
	total_chars_ftp = ft_dprintf(fd, "Test 11 (char2) : %%-8c='%-8c'\n", c);
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
		printf(ANSI_COLOR_GREEN"Test 11 (char2) 	-> SUCCESS!\n");
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 11 (char2) 	-> FAIL!\n");
		return (-1);
	}
}

int				test_char3(void)
{
	char		c;

	c = 'K';
	ft_printf(ANSI_COLOR_MAGENTA"Test 12 (char3) 	-> UNDEFINED BEHAVIOUR\n");
	// printf(ANSI_COLOR_CYAN"Test 12 -0c THE PRINTF : '%-0c'\n", c);
}

int				test_char4(void)
{
	char		c;

	c = 'M';
	ft_printf(ANSI_COLOR_MAGENTA"Test 13 (char4) 	-> UNDEFINED BEHAVIOUR\n");
	// printf(ANSI_COLOR_CYAN"Test 13 hc THE PRINTF : '%hc'\n", c);
	// ft_printf(ANSI_COLOR_YELLOW"Test 13 hc MY  PRINTF : '%hc'\n\n", c);
}

int				test_char5(void)
{
	char		c;

	c = 'G';
	ft_printf(ANSI_COLOR_MAGENTA"Test 14 (char5) 	-> UNDEFINED BEHAVIOUR\n");
	// printf(ANSI_COLOR_CYAN"Test 14 hhc THE PRINTF : '%hhc'\n", c);
	// ft_printf(ANSI_COLOR_YELLOW"Test 14 hhc MY  PRINTF : '%hhc'\n\n", c);
}

int				test_char6(void)
{
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			total_chars_p;
	int			total_chars_ftp;
	int			fd;
	char		c;

	c = 'B';
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%9lc='%9lc', %%*c='%*c'\n", c, -10, 'a');
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%9lc='%9lc', %%*c='%*c'\n", c, -10, 'a');
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
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0)
	&& (total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 15 (char6) 	-> SUCCESS!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 15 (char6) 	-> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int				test_char7(void)
{
	char		c;

	c = 'C';
	ft_printf(ANSI_COLOR_MAGENTA"Test 16 		-> Error/Warning >> ");
	// printf(ANSI_COLOR_CYAN"Test 16 4llc THE PRINTF : '%4llc'\n", c);
	ft_printf(ANSI_COLOR_YELLOW" 4llc MY  PRINTF : '%4llc'\n", c);
}
