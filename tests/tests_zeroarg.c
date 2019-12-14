/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests_zeroarg.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/28 18:05:03 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/11/28 18:05:05 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

int				test_zeroarg1(void)
{
	int			total_chars_p;
	int			total_chars_ftp;
    char        snprintf_str[100];
    char        ft_snprintf_str[100];

	total_chars_p = snprintf(snprintf_str, 70, "%%i='%i', %%3.6i='%3.6i', \
	%%9.2i='%9.2i', %%0.0i='%0.0i', %%1.0i='%1.0i'", 0, 0, 0, 0, 0);
	total_chars_ftp = ft_snprintf(ft_snprintf_str, 70, "%%i='%i', %%3.6i='%3.6i', \
	%%9.2i='%9.2i', %%0.0i='%0.0i', %%1.0i='%1.0i'", 0, 0, 0, 0, 0);
	if ((strcmp(snprintf_str, ft_snprintf_str) == 0) && \
	(total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 149 (zeroarg1)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("snprintf    : [%s]\n", snprintf_str);
		printf("ft_snprintf : [%s]\n", ft_snprintf_str);
		// printf(ANSI_COLOR_CYAN"printf return total chars     = %d \n"\
		// ANSI_COLOR_RESET, total_chars_p);
		// printf(ANSI_COLOR_YELLOW"ft_printf return total chars  = %d \n"\
		// ANSI_COLOR_RESET, total_chars_ftp);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 149 (zeroarg1)  -> FAIL!\n"ANSI_COLOR_RESET);
		printf("snprintf    : [%s]\n", snprintf_str);
		printf("ft_snprintf : [%s]\n", ft_snprintf_str);
		return (-1);
	}
}

int				test_zeroarg2(void)
{
	int			total_chars_p;
	int			total_chars_ftp;
    char        snprintf_str[12];
    char        ft_snprintf_str[12];

	total_chars_p = snprintf(snprintf_str, 12, "%%1i='%1i' ABCDEF", 0);
	total_chars_ftp = ft_snprintf(ft_snprintf_str, 12, "%%1i='%1i' ABCDEF", \
	0);
	if ((strcmp(snprintf_str, ft_snprintf_str) == 0) && \
	(total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 150 (zeroarg2)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("snprintf    : [%s]\n", snprintf_str);
		printf("ft_snprintf : [%s]\n", ft_snprintf_str);
		// printf(ANSI_COLOR_CYAN"printf return total chars     = %d \n"ANSI_COLOR_RESET, total_chars_p);
		// printf(ANSI_COLOR_YELLOW"ft_printf return total chars  = %d \n"ANSI_COLOR_RESET, total_chars_ftp);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 150 (zeroarg2)   -> FAIL!\n"ANSI_COLOR_RESET);
		printf("snprintf    : [%s]\n", snprintf_str);
		printf("ft_snprintf : [%s]\n", ft_snprintf_str);
		return (-1);
	}
}

int				test_zeroarg3(void)
{
	int			total_chars_p;
	int			total_chars_ftp;
    char        snprintf_str[50];
    char        ft_snprintf_str[50];

	total_chars_p = snprintf(snprintf_str, 30, "%%2i='%2i' %%5i='%5i'", 0, 0);
	total_chars_ftp = ft_snprintf(ft_snprintf_str, 30, "%%2i='%2i' %%5i='%5i'", 0, 0);
	if ((strcmp(snprintf_str, ft_snprintf_str) == 0) && \
	(total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 151 (zeroarg3)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("snprintf    : [%s]\n", snprintf_str);
		printf("ft_snprintf : [%s]\n", ft_snprintf_str);
		// printf(ANSI_COLOR_CYAN"printf return total chars     = %d \n"ANSI_COLOR_RESET, total_chars_p);
		// printf(ANSI_COLOR_YELLOW"ft_printf return total chars  = %d \n"ANSI_COLOR_RESET, total_chars_ftp);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 151 (zeroarg3)   -> FAIL!\n"ANSI_COLOR_RESET);
		printf("snprintf    : [%s]\n", snprintf_str);
		printf("ft_snprintf : [%s]\n", ft_snprintf_str);
		return (-1);
	}
}

int				test_zeroarg4(void)
{
	int			total_chars_p;
	int			total_chars_ftp;
    char        snprintf_str[50];
    char        ft_snprintf_str[50];

	total_chars_p = snprintf(snprintf_str, 30, "%%.1i='%.1i', %%2.2i='%2.2i'", 0, 0);
	total_chars_ftp = ft_snprintf(ft_snprintf_str, 30, "%%.1i='%.1i', %%2.2i='%2.2i'", 0, 0);
	if ((strcmp(snprintf_str, ft_snprintf_str) == 0) && \
	(total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 152 (zeroarg4)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("snprintf    : [%s]\n", snprintf_str);
		printf("ft_snprintf : [%s]\n", ft_snprintf_str);
		// printf(ANSI_COLOR_CYAN"printf return total chars     = %d \n"ANSI_COLOR_RESET, total_chars_p);
		// printf(ANSI_COLOR_YELLOW"ft_printf return total chars  = %d \n"ANSI_COLOR_RESET, total_chars_ftp);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 152 (zeroarg4)   -> FAIL!\n"ANSI_COLOR_RESET);
		printf("snprintf    : [%s]\n", snprintf_str);
		printf("ft_snprintf : [%s]\n", ft_snprintf_str);
		return (-1);
	}
}

int						test_zeroarg5(void)
{
	int					total_chars_p;
	int					total_chars_ftp;
	int					fd;
	char				*returned_line_dprintf;
	char				*returned_line_ft_dprintf;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%-*.*u='%-*.*u'(min=5, prec=5), %%01.u='%01.u'\n", 5, 5, 0, 0);
	fd = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd, "%%-*.*u='%-*.*u'(min=5, prec=5), %%01.u='%01.u'\n", 5, 5, 0, 0);
	close(fd);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	close(fd);
	fd = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_ft_dprintf);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0) && \
	(total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 124 (zeroarg5)	ZERO_ARG -> \
		SUCCESS!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 124 (zeroarg5) ZERO_ARG 	-> FAIL!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int				test_zeroarg6(void)
{
	int			total_chars_p;
	int			total_chars_ftp;
    char        snprintf_str[50];
    char        ft_snprintf_str[50];

	total_chars_p = snprintf(snprintf_str, 30, "%%.1u='%.1u', %%2.2u='%2.2u'", 0, 0);
	total_chars_ftp = ft_snprintf(ft_snprintf_str, 30, "%%.1u='%.1u', %%2.2u='%2.2u'", 0, 0);
	if ((total_chars_p == total_chars_ftp) && \
	(strcmp(snprintf_str, ft_snprintf_str) == 0))
	{
		printf(ANSI_COLOR_GREEN"Test 152 (zeroarg6)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("snprintf    : [%s]\n", snprintf_str);
		printf("ft_snprintf : [%s]\n", ft_snprintf_str);
		// printf(ANSI_COLOR_CYAN"printf return total chars     = %d \n"ANSI_COLOR_RESET, total_chars_p);
		// printf(ANSI_COLOR_YELLOW"ft_printf return total chars  = %d \n"ANSI_COLOR_RESET, total_chars_ftp);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 152 (zeroarg6)   -> FAIL!\n"ANSI_COLOR_RESET);
		printf("snprintf    : [%s]\n", snprintf_str);
		printf("ft_snprintf : [%s]\n", ft_snprintf_str);
		return (-1);
	}
}

int				test_zeroarg7(void)
{
	int			total_chars_p;
	int			total_chars_ftp;
    char        snprintf_str[50];
    char        ft_snprintf_str[50];

	total_chars_p = snprintf(snprintf_str, 30, "%%.2u='%.2u', %%3.3u='%3.3u'", 0, 0);
	total_chars_ftp = ft_snprintf(ft_snprintf_str, 30, "%%.2u='%.2u', %%3.3u='%3.3u'", 0, 0);
	if ((total_chars_p == total_chars_ftp) && \
	(strcmp(snprintf_str, ft_snprintf_str) == 0))
	{
		printf(ANSI_COLOR_GREEN"Test 153 (zeroarg7)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("snprintf    : [%s]\n", snprintf_str);
		printf("ft_snprintf : [%s]\n", ft_snprintf_str);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 153 (zeroarg7)   -> FAIL!\n"ANSI_COLOR_RESET);
		printf("snprintf    : [%s]\n", snprintf_str);
		printf("ft_snprintf : [%s]\n", ft_snprintf_str);
		return (-1);
	}
}

int				test_zeroarg8(void)
{
	int			total_chars_p;
	int			total_chars_ftp;
    char        snprintf_str[50];
    char        ft_snprintf_str[50];

	total_chars_p = snprintf(snprintf_str, 30, "%%0.1d='%0.1d', %%4.4d='%4.4d'", 0, 0);
	total_chars_ftp = ft_snprintf(ft_snprintf_str, 30, "%%0.1d='%0.1d', %%4.4d='%4.4d'", 0, 0);
	if ((total_chars_p == total_chars_ftp) && \
	(strcmp(snprintf_str, ft_snprintf_str) == 0))
	{
		printf(ANSI_COLOR_GREEN"Test 155 (zeroarg8)	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("snprintf    : [%s]\n", snprintf_str);
		printf("ft_snprintf : [%s]\n", ft_snprintf_str);
		// printf(ANSI_COLOR_CYAN"printf return total chars     = %d \n"ANSI_COLOR_RESET, total_chars_p);
		// printf(ANSI_COLOR_YELLOW"ft_printf return total chars  = %d \n"ANSI_COLOR_RESET, total_chars_ftp);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 155 (zeroarg8)   -> FAIL!\n"ANSI_COLOR_RESET);
		printf("snprintf    : [%s]\n", snprintf_str);
		printf("ft_snprintf : [%s]\n", ft_snprintf_str);
		return (-1);
	}
}

int				test_zeroarg9(void)
{
	int			total_chars_p;
	int			total_chars_ftp;
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			fd;
	int			fd1;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%.0d", 0);
	fd1 = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd1, "%.0d", 0);
	close(fd);
	close(fd1);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	fd1 = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd1, &returned_line_ft_dprintf);
	close(fd);
	close(fd1);
	if ((returned_line_dprintf == NULL) && (returned_line_ft_dprintf == NULL) && \
	(total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 160 (test_zeroarg9) 	-> SUCCESS!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{
		printf(ANSI_COLOR_RED"Test 160 (test_zeroarg9) 	-> FAIL!\n"ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (-1);
	}
}

int				test_zeroarg10(void)
{
	int			total_chars_p;
	int			total_chars_ftp;
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			fd;
	int			fd1;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_p = dprintf(fd, "%%+.1d='%+.1d', %% .0i='% .0i', %%-.0d='%-.0d', %% 02.0i='% 02.0i'\n", 0, 0, 0, 0);
	fd1 = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd1, "%%+.1d='%+.1d', %% .0i='% .0i', %%-.0d='%-.0d', %% 02.0i='% 02.0i'\n", 0, 0, 0, 0);
	close(fd);
	close(fd1);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	fd1 = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd1, &returned_line_ft_dprintf);
	close(fd);
	close(fd1);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0)
	&& (total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 164 (test_zeroarg10) 	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{ 
		printf(ANSI_COLOR_RED"Test 164 (test_zeroarg10) 	-> FAIL!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		printf(ANSI_COLOR_CYAN"printf return total chars     = %d \n"ANSI_COLOR_RESET, total_chars_p);
		printf(ANSI_COLOR_YELLOW"ft_printf return total chars  = %d \n"ANSI_COLOR_RESET, total_chars_ftp);
		return (-1);
	}
}

int				test_zeroarg11(void)
{
	int			total_chars_p;
	int			total_chars_ftp;
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			fd;
	int			fd1;

	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	// total_chars_p = dprintf(fd, "%%#.o='%#.o', %%#5.3o='%#5.3o', %%5.3o='%5.3o', %%#5.3d='%#5.3d',\n", 0, 0, 0, 0);
	total_chars_p = dprintf(fd, "%%5.3o='%5.3o', %%2.5o='%2.5o', %%11p='%11p', %%+7i='%+7i', %% 8.5i='% 8.5i', %% -3i='% -3i', %% -3d='% -3d'\n", 0, 0, 0, 0, 0, 0, 0);
	fd1 = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd1, "%%5.3o='%5.3o', %%2.5o='%2.5o', %%11p='%11p', %%+7i='%+7i', %% 8.5i='% 8.5i', %% -3i='% -3i', %% -3d='% -3d'\n", 0, 0, 0, 0, 0, 0, 0);
	close(fd);
	close(fd1);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	fd1 = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd1, &returned_line_ft_dprintf);
	close(fd);
	close(fd1);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0)
	&& (total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 165 (test_zeroarg11) 	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{ 
		printf(ANSI_COLOR_RED"Test 165 (test_zeroarg11) 	-> FAIL!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		printf(ANSI_COLOR_CYAN"printf return total chars     = %d \n"ANSI_COLOR_RESET, total_chars_p);
		printf(ANSI_COLOR_YELLOW"ft_printf return total chars  = %d \n"ANSI_COLOR_RESET, total_chars_ftp);
		return (-1);
	}
}

int				test_zeroarg12(void)
{
	int			total_chars_p;
	int			total_chars_ftp;
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			fd;
	int			fd1;

	close(fd);
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	// total_chars_p = dprintf(fd, "%%#.o='%#.o', %%#5.3o='%#5.3o', %%5.3o='%5.3o', %%#5.3d='%#5.3d',\n", 0, 0, 0, 0);
	total_chars_p = dprintf(fd, "%%+-8.5i='%+-8.5i', %% +-8.5i='% +-8.5i', %%+-8.5d='%+-8.5d', %% +-8.5d='% +-8.5d', %%3x='%3x', %%#3x='%#3x'\n", 0, 0, 0, 0, 0, 0);
	fd1 = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd1, "%%+-8.5i='%+-8.5i', %% +-8.5i='% +-8.5i', %%+-8.5d='%+-8.5d', %% +-8.5d='% +-8.5d', %%3x='%3x', %%#3x='%#3x'\n", 0, 0, 0, 0, 0, 0);
	close(fd);
	close(fd1);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	fd1 = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd1, &returned_line_ft_dprintf);
	close(fd);
	close(fd1);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0)
	&& (total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 170 (test_zeroarg12) 	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{ 
		printf(ANSI_COLOR_RED"Test 170 (test_zeroarg12) 	-> FAIL!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		printf(ANSI_COLOR_CYAN"printf return total chars     = %d \n"ANSI_COLOR_RESET, total_chars_p);
		printf(ANSI_COLOR_YELLOW"ft_printf return total chars  = %d \n"ANSI_COLOR_RESET, total_chars_ftp);
		return (-1);
	}
}

int				test_zeroarg13(void)
{
	int			total_chars_p;
	int			total_chars_ftp;
	char		*returned_line_dprintf;
	char		*returned_line_ft_dprintf;
	int			fd;
	int			fd1;

	close(fd);
	fd = open("result_dprintf.txt", O_TRUNC | O_WRONLY);
	// total_chars_p = dprintf(fd, "%%#.o='%#.o', %%#5.3o='%#5.3o', %%5.3o='%5.3o', %%#5.3d='%#5.3d',\n", 0, 0, 0, 0);
	total_chars_p = dprintf(fd, "%%#-3x='%#-3x', %%3X='%3X', %%#3X='%#3X', %%#3o='%#3o', %%-5.0o='%-5.0o', %%-5.o='%-5.o'\n", 0, 0, 0, 0, 0, 0);
	fd1 = open("result_ftdprintf.txt", O_TRUNC | O_WRONLY);
	total_chars_ftp = ft_dprintf(fd1, "%%#-3x='%#-3x', %%3X='%3X', %%#3X='%#3X', %%#3o='%#3o', %%-5.0o='%-5.0o', %%-5.o='%-5.o'\n", 0, 0, 0, 0, 0, 0);
	close(fd);
	close(fd1);
	fd = open("result_dprintf.txt", O_RDONLY);
	get_next_line(fd, &returned_line_dprintf);
	fd1 = open("result_ftdprintf.txt", O_RDONLY);
	get_next_line(fd1, &returned_line_ft_dprintf);
	close(fd);
	close(fd1);
	if ((strcmp(returned_line_dprintf, returned_line_ft_dprintf) == 0)
	&& (total_chars_p == total_chars_ftp))
	{
		printf(ANSI_COLOR_GREEN"Test 171 (test_zeroarg13) 	-> SUCCESS!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		return (0);
	}
	else
	{ 
		printf(ANSI_COLOR_RED"Test 171 (test_zeroarg13) 	-> FAIL!\n"\
		ANSI_COLOR_RESET);
		printf("printf    : [%s]\n", returned_line_dprintf);
		printf("ft_printf : [%s]\n", returned_line_ft_dprintf);
		printf(ANSI_COLOR_CYAN"printf return total chars     = %d \n"ANSI_COLOR_RESET, total_chars_p);
		printf(ANSI_COLOR_YELLOW"ft_printf return total chars  = %d \n"ANSI_COLOR_RESET, total_chars_ftp);
		return (-1);
	}
}