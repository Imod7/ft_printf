/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests_memory.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 16:28:00 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/11/26 16:28:03 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

int				test_memory1(void)
{
	char		*returned_line_ft_dprintf;
	int			total_chars_ftp;
	int			fd;
	int tab[10] = {0, 23, 150, 255, 12, 16, 42, 103};

	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "Test memory : %%m='%m'\n", tab);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	printf(ANSI_COLOR_GREEN"kkkkTest 145 	(memory1)	BONUS\n"ANSI_COLOR_RESET);
	printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
	close(fd);
	return (0);
}
