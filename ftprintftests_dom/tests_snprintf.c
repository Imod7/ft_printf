/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests_snprintf.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/23 19:11:50 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/11/23 19:11:51 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

/*
** In snprintf if size is zero or negative is undefined
*/

int				test_snprintf1(void)
{
	int			total_chars_p;
	int			total_chars_ftp;
    char        snprintf_str[55];
    char        ft_snprintf_str[55];

	total_chars_p = snprintf(snprintf_str, 33, "Test snprintf1 : \
    %%6o='%6o', %%-05o='%-05o'ABCEFG", 325, 2500);
	total_chars_ftp = ft_snprintf(ft_snprintf_str, 33, "Test snprintf1 : \
    %%6o='%6o', %%-05o='%-05o'ABCEFG", 325, 2500);
	if ((strcmp(snprintf_str, ft_snprintf_str) == 0) && \
	(total_chars_p == total_chars_ftp))
    {
		printf(ANSI_COLOR_GREEN"Test 142 (snprintf1)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", snprintf_str);
		printf("ft_printf : [%s]\n", ft_snprintf_str);
		// printf(ANSI_COLOR_CYAN"printf return total chars     = %d \n"ANSI_COLOR_RESET, total_chars_p);
		// printf(ANSI_COLOR_YELLOW"ft_printf return total chars  = %d \n"ANSI_COLOR_RESET, total_chars_ftp);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 142 (snprintf1)   -> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", snprintf_str);
		printf("ft_printf : [%s]\n", ft_snprintf_str);
		return (-1);
	}
}

int				test_snprintf2(void)
{
	int			total_chars_p;
	int			total_chars_ftp;
    char        snprintf_str[55];
    char        ft_snprintf_str[55];

	total_chars_p = snprintf(snprintf_str, 1, "toto %%.0d='%.0d' et %%+.i='%+.i'XX", 0, 0);
	total_chars_ftp = ft_snprintf(ft_snprintf_str, 1, "toto %%.0d='%.0d' et %%+.i='%+.i'XX", 0, 0);
	if ((strcmp(snprintf_str, ft_snprintf_str) == 0) && \
	(total_chars_p == total_chars_ftp))
    {
		printf(ANSI_COLOR_GREEN"Test 143 (snprintf2)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", snprintf_str);
		printf("ft_printf : [%s]\n", ft_snprintf_str);
		// printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
		// printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 143 (snprintf2)   -> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", snprintf_str);
		printf("ft_printf : [%s]\n", ft_snprintf_str);
		return (-1);
	}
}

int				test_snprintf3(void)
{
	int			total_chars_p;
	int			total_chars_ftp;
    char        snprintf_str[20];
    char        ft_snprintf_str[20];

	total_chars_p = snprintf(snprintf_str, 5, "%%.*d='%.*d'\n",  -5, 42);
	total_chars_ftp = ft_snprintf(ft_snprintf_str, 5, "%%.*d='%.*d'\n",  -5, 42);
	if ((strcmp(snprintf_str, ft_snprintf_str) == 0) && \
	(total_chars_p == total_chars_ftp))
    {
		printf(ANSI_COLOR_GREEN"Test 144 (snprintf3)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", snprintf_str);
		printf("ft_printf : [%s]\n", ft_snprintf_str);
		// printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
		// printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 144 (snprintf3)   -> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", snprintf_str);
		printf("ft_printf : [%s]\n", ft_snprintf_str);
		return (-1);
	}
}
