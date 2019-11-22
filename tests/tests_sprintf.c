/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests_sprintf.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 13:35:48 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/11/20 13:36:27 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

int				test_sprintf1(void)
{
	int			total_chars_p;
	int			total_chars_ftp;
    char        sprintf_str[50];
    char        ft_sprintf_str[50];

	total_chars_p = sprintf(sprintf_str, "Test sprintf1 : %%6o='%6o', \
    %%+-05o='%+-05o'\n", 325, 2500);
	total_chars_ftp = ft_sprintf(ft_sprintf_str, "Test sprintf1 : %%6o='%6o', \
    %%+-05o='%+-05o'\n", 325, 2500);
	// printf(ANSI_COLOR_CYAN"total_chars_p   = %d \n", total_chars_p);
	// printf(ANSI_COLOR_YELLOW"total_chars_ftp = %d \n", total_chars_ftp);
	if ((strcmp(sprintf_str, ft_sprintf_str) == 0) && \
	(total_chars_p == total_chars_ftp))
    {
		printf(ANSI_COLOR_GREEN"Test 132 (sprintf1)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", sprintf_str);
		printf("ft_printf : [%s]\n", ft_sprintf_str);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 132 (sprintf1)   -> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", sprintf_str);
		printf("ft_printf : [%s]\n", ft_sprintf_str);
		return (-1);
	}
}

int				test_sprintf2(void)
{
	int			total_chars_p;
	int			total_chars_ftp;
    char        sprintf_str[100];
    char        ft_sprintf_str[100];

	total_chars_p = sprintf(sprintf_str, "%%hhu=%hhu", (unsigned char)20);
	total_chars_ftp = ft_sprintf(ft_sprintf_str, "%%hhu=%hhu", (unsigned char)20);
	if ((strcmp(sprintf_str, ft_sprintf_str) == 0) && \
	(total_chars_p == total_chars_ftp))
    {
		printf(ANSI_COLOR_GREEN"Test 136 (sprintf2)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", sprintf_str);
		printf("ft_printf : [%s]\n", ft_sprintf_str);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 136 (sprintf2)   -> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", sprintf_str);
		printf("ft_printf : [%s]\n", ft_sprintf_str);
		return (-1);
	}
}

int				test_sprintf3(void)
{
	int			total_chars_p;
	int			total_chars_ftp;
    char        sprintf_str[100];
    char        ft_sprintf_str[100];

	total_chars_p = sprintf(sprintf_str, "\\nHERE et %00009u%-2lu mimi et titi%--14u", 0, (unsigned long)14, 200);
	total_chars_ftp = ft_sprintf(ft_sprintf_str, "\\nHERE et %00009u%-2lu mimi et titi%--14u", 0, (unsigned long)14, 200);
	if ((strcmp(sprintf_str, ft_sprintf_str) == 0) && \
	(total_chars_p == total_chars_ftp))
    {
		printf(ANSI_COLOR_GREEN"Test 138 (sprintf3)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", sprintf_str);
		printf("ft_printf : [%s]\n", ft_sprintf_str);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 138 (sprintf3)   -> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", sprintf_str);
		printf("ft_printf : [%s]\n", ft_sprintf_str);
		return (-1);
	}
}