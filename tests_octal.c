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

#include "ft_printf.h"

void			test_17(void)
{
	int		    num;

	num = 74;
	printf(ANSI_COLOR_CYAN"Test 17 6o THE PRINTF : '%6o'\n", num);
	ft_printf(ANSI_COLOR_YELLOW"Test 17 6o MY  PRINTF : '%6o'\n\n", num);
}

void			test_18(void)
{
	int		    num;

	num = 99;
	printf(ANSI_COLOR_CYAN"Test 18 05o THE PRINTF : '%05o'\n", num);
	ft_printf(ANSI_COLOR_YELLOW"Test 18 05o MY  PRINTF : '%05o'\n\n", num);
}

void			test_19(void)
{
	int		    num;

	num = 1348;
	ft_printf(ANSI_COLOR_GREEN"Test 19 should show error >> ");
	// printf(ANSI_COLOR_CYAN"Test 19 space7o THE PRINTF : '% 7o'\n", num);
	ft_printf(ANSI_COLOR_YELLOW"Test 19 space7o MY  PRINTF : '% 7o'\n\n", num);
	printf("\n");
}
