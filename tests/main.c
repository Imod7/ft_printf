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

#include "test_header.h"

int				main(void)
{
	int			option;
	int			i;
	int			test_result;
	int			test_passed;
	test_func	*test_array[98];

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
	test_array[51] = test_u1;
	test_array[52] = test_octal5;
	test_array[53] = test_octal6;
	test_array[54] = test_u2;
	test_array[55] = test_hex13;
	test_array[56] = test_float6;
	test_array[57] = test_float7;
	test_array[58] = test_float8;
	test_array[59] = test_float9;
	test_array[60] = test_string4;
	test_array[61] = test_octal7;
	test_array[62] = test_float10;
	test_array[63] = test_float11;
	test_array[64] = test_float12;
	test_array[65] = test_float13;
	test_array[66] = test_float14;
	test_array[67] = test_float15;
	test_array[68] = test_float16;
	test_array[69] = test_float17;
	test_array[70] = test_i5;
	test_array[71] = test_int13;
	test_array[72] = test_int14;
	test_array[73] = test_int15;
	test_array[74] = test_octal8;
	test_array[75] = test_hex14;
	test_array[76] = test_octal9;
	test_array[77] = test_hex15;
	test_array[78] = test_float18;
	test_array[79] = test_octal10;
	test_array[80] = test_u3;
	test_array[81] = test_octal11;
	test_array[82] = test_octal12;
	test_array[83] = test_u4;
	test_array[84] = test_octal13;
	test_array[85] = test_u5;
	test_array[86] = test_hex16;
	test_array[87] = test_octal14;
	test_array[88] = test_octal15;
	test_array[89] = test_octal16;
	test_array[90] = test_pointer3;
	test_array[91] = test_char8;
	test_array[92] = test_string5;
	test_array[93] = test_exceptions3;
	test_array[94] = test_exceptions4;
	test_array[95] = test_pointer4;
	test_array[96] = test_exceptions5;
	test_array[97] = test_string6;
	i = 1;
	test_passed = 0;
	printf("Which Test do you want to run ? (0 to run All) \n");
	scanf("%d", &option);
	if (option > (int)(sizeof(test_array) / sizeof(test_array[0])))
	{
		printf(ANSI_COLOR_RED"\nThe max option you can give is \
		%d\n"ANSI_COLOR_RESET, \
		(int)(sizeof(test_array) / sizeof(test_array[0])));
		return (0);
	}
	if (option != 0)
		test_array[option - 1]();
	else
	{
		while (i <= (int)(sizeof(test_array) / sizeof(test_array[0])))
		{
			test_result = test_array[i - 1]();
			if (test_result == 0)
				test_passed++;
			i++;
		}
	}
	printf(ANSI_COLOR_CYAN"\n--------------------------------------------");
	printf("\nTests that Passed	-> %d / %d", test_passed, i);
	printf("\n--------------------------------------------\n");
	return (0);
}
