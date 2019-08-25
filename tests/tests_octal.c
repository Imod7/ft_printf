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

void			test_17(void)
{
	// int		    num;
	// int			total_chars_p;
	// int			total_chars_ftp;

	// num = 74;
	// write(1, "\n", 1);
	// total_chars_p = printf(ANSI_COLOR_CYAN"Test 17 6o : '%6o'\n", num);
	// total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test 17 6o : '%6o'\n", num);
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			total_chars_p;
	int			total_chars_ftp;
	int			fd;
	int		    num;

	num = 74;
	write(1, "\n", 1);
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 17 6o : '%6o'\n", num);

	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 17 6o : '%6o'\n", num);
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
	// printf("\n'%s'\n", returned_line_dprintf);
	// printf("'%s'\n", returned_line_ft_dprintf);
	if (strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0)
		printf(ANSI_COLOR_GREEN"Test_17 with %%6o : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test_17 with %%6o : Wrong!\n");
}

void				test_18(void)
{
	// unsigned short	num;
	// int				total_chars_p;
	// int				total_chars_ftp;

	// num = 5623;
	// write(1, "\n", 1);
	// total_chars_p = printf(ANSI_COLOR_CYAN"Test 18   >05o : '%05o' , >#*o : '%#*o'\n", num, 22, num);
	// total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test 18   >05o : '%05o' , >#*o : '%#*o'\n", num, 22, num);
	// assert(total_chars_p == total_chars_ftp);
	// // printf(ANSI_COLOR_RED"total_chars_p   = %d \n", total_chars_p);
	// // printf(ANSI_COLOR_RED"total_chars_ftp = %d \n", total_chars_ftp);
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			total_chars_p;
	int			total_chars_ftp;
	int			fd;
	int		    num;

	num = 74;
	write(1, "\n", 1);
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "Test 18   >05o : '%05o' , >#*o : '%#*o'\n", num, 22, num);

	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test 18   >05o : '%05o' , >#*o : '%#*o'\n", num, 22, num);
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
	// printf("\n'%s'\n", returned_line_dprintf);
	// printf("'%s'\n", returned_line_ft_dprintf);
	if (strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0)
		printf(ANSI_COLOR_GREEN"Test_18 with %%05o , %%#*o : Correct!\n");
	else
		printf(ANSI_COLOR_RED"Test_18 with %%05o , %%#*o : Wrong!\n");
}

void				test_19(void)
{
	unsigned char	num;
	// int				total_chars_p;
	// int				total_chars_ftp;

	num = 120;
	write(1, "\n", 1);
	ft_printf(ANSI_COLOR_MAGENTA"Test 19  with %% 7o Undefined Behaviour");
	// total_chars_p = printf(ANSI_COLOR_CYAN"Test 19 space7o THE PRINTF : '% 7o'\n", num);
	// ft_printf(ANSI_COLOR_YELLOW"Test 19 space7o MY  PRINTF : '% 7o'\n\n", num);
}
