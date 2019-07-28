/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/28 15:49:31 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/07/28 15:49:37 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				main(void)
{
	printf(ANSI_COLOR_GREEN "\n--- FT_PRINTF ---\n");
	ft_printf("Test with one num = %+d &one string %+-s and another string \
    %s %%\n\n", 23, "Awesome", "Printf");
	printf(ANSI_COLOR_RESET);
	printf(ANSI_COLOR_CYAN "\n\n--- PRINTF ---\n");
	printf("Test with one num = %d &one string %s and another string \
    %s %%", 23, "Awesome", "Printf");
	printf(ANSI_COLOR_RESET);
	return (0);
}
