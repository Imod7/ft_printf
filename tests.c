/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/09 00:20:25 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/08/09 00:24:25 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	test_one(void)
{
	printf(ANSI_COLOR_CYAN"'Test 1 THE PRINTF : with the number '%+08d' and the string '%s' and the char '%c'\n", 45, "coding", 'K');
	ft_printf(ANSI_COLOR_YELLOW"'Test 1 MY  PRINTF : with the number '%+08d' and the string '%s' and the char '%c'\n\n", 45, "coding", 'K');
}

void	test_two(void)
{
	printf(ANSI_COLOR_CYAN"Test 2 THE PRINTF : '%+08d' blabla\n", 45);
	ft_printf(ANSI_COLOR_YELLOW"Test 2 MY  PRINTF : '%+08d' blabla\n\n", 45);
}

void	test_three(void)
{
	printf(ANSI_COLOR_CYAN"Test 3 THE PRINTF : '%+8d' \n", 55);
	ft_printf(ANSI_COLOR_YELLOW"Test 3 MY  PRINTF : '%+8d' \n\n", 55);
}

void	test_four(void)
{
	printf(ANSI_COLOR_CYAN"Test 4 THE PRINTF : '%010d'\n", 1256);
	ft_printf(ANSI_COLOR_YELLOW"Test 4 MY  PRINTF : '%010d'\n\n", 1256);
}

void	test_five(void)
{
	printf(ANSI_COLOR_CYAN"Test 5 THE PRINTF : '%-10d'\n", 99);
	ft_printf(ANSI_COLOR_YELLOW"Test 5 MY  PRINTF : '%-10d'\n\n", 99);
}
