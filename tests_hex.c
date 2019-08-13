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

void			test_22(void)
{
	int		    num;

	num = -2000;
	printf(ANSI_COLOR_CYAN"Test 22 x THE PRINTF : '%x'\n", num);
	ft_printf(ANSI_COLOR_YELLOW"Test 22 x MY  PRINTF : '%x'\n\n", num);
}

void			test_23(void)
{
	int		    num;

	num = 4000;
	printf(ANSI_COLOR_CYAN"Test 23 0x THE PRINTF : '%0.11x'\n", num);
	ft_printf(ANSI_COLOR_YELLOW"Test 23 0x MY  PRINTF : '%0.11x'\n\n", num);
}

void			    test_24(void)
{
	unsigned short	num;

	num = 8523;
	printf(ANSI_COLOR_CYAN"Test 24 hx THE PRINTF : '%hx'\n", num);
	ft_printf(ANSI_COLOR_YELLOW"Test 24 hx MY  PRINTF : '%hx'\n\n", num);
}
