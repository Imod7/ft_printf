/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_helper.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/25 15:58:34 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/07/25 15:58:36 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				print_binary(uint16_t flag_num)
{
	int				bit;
	int 			col;
	unsigned short	mask;

	bit = 0;
	col = 0;
	while (col < 16)
	{
		mask = flag_num >> bit;
		if (mask & 1)
			printf("1 ");
		else
			printf("0 ");
		bit++;
		col++;
	}
}
