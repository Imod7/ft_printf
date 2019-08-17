/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests_fd.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/16 23:52:38 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/08/16 23:52:40 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "test_header.h"

void		test_fd1(void)
{
    FILE    *fptr;
    int     total_chars_p;

    fptr = fopen("sample.txt", "w");
    if (fptr == NULL)
    {
        printf("Could not open file");
        return 0;
    }
	write(1, "\n", 1);
	total_chars_p = fprintf(fptr, ANSI_COLOR_CYAN"Test 31 09hhX : '%09hhX'\n", num);
	// total_chars_ftp = ft_printf(ANSI_COLOR_YELLOW"Test 31 09hhX : '%09hhX'\n", num);
	// assert(total_chars_p == total_chars_ftp);
	printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	// printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);
}

