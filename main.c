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
	printf(ANSI_COLOR_YELLOW "\n--- PRINTF ---\n");
	printf("'Test with the number '%+d' and the string '%s' and the char '%c'\n", 44, "coding", 'K');
	printf(ANSI_COLOR_RESET);
	printf(ANSI_COLOR_CYAN "\n--- FT_PRINTF ---\n");
	ft_printf("'Test with the number '%+d' and the string '%s' and the char '%c'\n\n", 44, "coding", 'K');
	printf(ANSI_COLOR_RESET);
	return (0);
}
