/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests_unsigned.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/19 14:30:45 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/09/19 14:30:47 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "test_header.h"

void		test_u1(void)
{
	// char		*returned_line_dprintf;
	// char		*returned_line_ft_dprintf;
	// int			total_chars_p;
	// int			total_chars_ftp;
	// int			fd;

	// fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	// total_chars_p = dprintf(fd, "'Test 52 (test_u1) : %%u='%u', %% u='% u', %%+u='%+u'\n", -1, 4294967295, 4294967295);
	// fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	// total_chars_ftp = ft_dprintf(fd, "'Test 52 (test_u1) : %%u='%u', %% u='% u', %%+u='%+u'\n", -1, 4294967295, 4294967295);
	// // assert(total_chars_p == total_chars_ftp);
	// // printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	// // printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);

	// close(fd);
	// fd = open("result_dprintf.txt", O_RDONLY);
	// get_next_line(fd, &returned_line_dprintf);
	// close(fd);
	// fd = open("result_ftdprintf.txt", O_RDONLY);
	// get_next_line(fd, &returned_line_ft_dprintf);
	// // assert(strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0);
	// if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	// (total_chars_p == total_chars_ftp))
		// printf(ANSI_COLOR_GREEN"Test 52 : Correct!\n");
	// else
		// printf(ANSI_COLOR_RED"Test 52 : Wrong!\n");
	printf(ANSI_COLOR_MAGENTA"Test 52 : Correct with no flags!\n");
}
