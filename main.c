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
#include "test_header.h"
#include <assert.h>

void				print_binary(uint16_t flag_num)
{
	int				bit;
	int 			pos;

	pos = 16;
	printf("\n the num is : %d \n", flag_num);
	while (pos >= 0)
	{
		bit = flag_num >> pos;
		if (bit & 1)
			printf("1 ");
		else
			printf("0 ");
		pos--;
	}
}

int					main(void)
{
	int			option;
	int			i;

	i = 1;
	test_func *test_array[5] = {
		test_one,
		test_two,
		test_three,
		test_four,
		test_five
	};
	printf("Which Test do you want to run ? (0 to run All) \n");
	scanf("%d", &option);
	if (option != 0)
		test_array[option - 1]();
	else
	{
		while (i <= 5)
		{
			test_array[i - 1]();
			i++;
		}
	}
	return (0);
}
