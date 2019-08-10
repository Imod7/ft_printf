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

void			print_binary(uint16_t flag_num)
{
	int			bit;
	int			pos;

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

int				main(void)
{
	int			option;
	int			i;
	test_func	*test_array[9];

	test_array[0] = test_one;
	test_array[1] = test_two;
	test_array[2] = test_three;
	test_array[3] = test_four;
	test_array[4] = test_five;
	test_array[5] = test_six;
	test_array[6] = test_seven;
	test_array[7] = test_eight;
	test_array[8] = test_nine;
	i = 1;
	printf("Which Test do you want to run ? (0 to run All) \n");
	scanf("%d", &option);
	if (option != 0)
		test_array[option - 1]();
	else
	{
		while (i <= 9)
		{
			test_array[i - 1]();
			i++;
		}
	}
	return (0);
}
