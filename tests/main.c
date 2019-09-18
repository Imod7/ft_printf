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

#include "../ft_printf.h"
#include "test_header.h"

int				main(void)
{
	int			option;
	int			i;
	test_func	*test_array[51];

	test_array[0] = test_int1;
	test_array[1] = test_int2;
	test_array[2] = test_int3;
	test_array[3] = test_int4;
	test_array[4] = test_int5;
	test_array[5] = test_int6;
	test_array[6] = test_int7;
	test_array[7] = test_int8;
	test_array[8] = test_int9;
	test_array[9] = test_char1;
	test_array[10] = test_char2;
	test_array[11] = test_char3;
	test_array[12] = test_char4;
	test_array[13] = test_char5;
	test_array[14] = test_char6;
	test_array[15] = test_char7;
	test_array[16] = test_octal1;
	test_array[17] = test_octal2;
	test_array[18] = test_octal3;
	test_array[19] = test_int10;
	test_array[20] = test_int11;
	test_array[21] = test_hex1;
	test_array[22] = test_hex2;
	test_array[23] = test_hex3;
	test_array[24] = test_hex4;
	test_array[25] = test_hex5;
	test_array[26] = test_hex6;
	test_array[27] = test_hex7;
	test_array[28] = test_hex8;
	test_array[29] = test_hex9;
	test_array[30] = test_hex10;
	test_array[31] = test_hex11;
	test_array[32] = test_hex12;
	test_array[33] = test_i1;
	test_array[34] = test_i2;
	test_array[35] = test_i3;
	test_array[36] = test_pointer1;
	test_array[37] = test_pointer2;
	test_array[38] = test_exceptions1;
	test_array[39] = test_i4;
	test_array[40] = test_exceptions2;
	test_array[41] = test_float1;
	test_array[42] = test_string1;
	test_array[43] = test_float2;
	test_array[44] = test_float3;
	test_array[45] = test_float4;
	test_array[46] = test_float5;
	test_array[47] = test_string2;
	test_array[48] = test_string3;
	test_array[49] = test_octal4;
	test_array[50] = test_int12;
	i = 1;
	printf("Which Test do you want to run ? (0 to run All) \n");
	scanf("%d", &option);
	if (option != 0)
		test_array[option - 1]();
	else
	{
		while (i <= (int)(sizeof(test_array) / sizeof(test_array[0])))
		{
			test_array[i - 1]();
			i++;
		}
	}
	return (0);
}
