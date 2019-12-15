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

int				main(int argc, char **argv)
{
	int			option;
	int			i;
	int			test_result;
	int			test_passed;
	test_func	*test_array[171];

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
	test_array[98] = test_string7;
	test_array[99] = test_string8;
	test_array[100] = test_string9;
	test_array[101] = test_string10;
	test_array[102] = test_string11;
	test_array[103] = test_i6;
	test_array[104] = test_int16;
	test_array[105] = test_i7;
	test_array[106] = test_i8;
	test_array[107] = test_i9;
	test_array[108] = test_i10;
	test_array[109] = test_hex17;
	test_array[110] = test_octal17;
	test_array[111] = test_u6;
	test_array[112] = test_u7;
	test_array[113] = test_i11;
	test_array[114] = test_float19;
	test_array[115] = test_float20;
	test_array[116] = test_float21;
	test_array[117] = test_float22;
	test_array[118] = test_float23;
	test_array[119] = test_exceptions6;
	test_array[120] = test_float24;
	test_array[121] = test_float25;
	test_array[122] = test_hex18;
	test_array[123] = test_zeroarg5;
	test_array[124] = test_u9;
	test_array[125] = test_u10;
	test_array[126] = test_int17;
	test_array[127] = test_int18;
	test_array[128] = test_string12;
	test_array[129] = test_int19;
	test_array[130] = test_octal18;
	test_array[131] = test_sprintf1;
	test_array[132] = test_int20;
	test_array[133] = test_i12;
	test_array[134] = test_mix1;
	test_array[135] = test_sprintf2;
	test_array[136] = test_int21;
	test_array[137] = test_sprintf3;
	test_array[138] = test_binary1;
	test_array[139] = test_binary2;
	test_array[140] = test_binary3;
	test_array[141] = test_snprintf1;
	test_array[142] = test_snprintf2;
	test_array[143] = test_snprintf3;
	test_array[144] = test_memory1;
	test_array[145] = test_float26;
	test_array[146] = test_float27;
	test_array[147] = test_float28;
	test_array[148] = test_zeroarg1;
	test_array[149] = test_zeroarg2;
	test_array[150] = test_zeroarg3;
	test_array[151] = test_zeroarg4;
	test_array[152] = test_zeroarg6;
	test_array[153] = test_zeroarg7;
	test_array[154] = test_zeroarg8;
	test_array[155] = test_undef1;
	test_array[156] = test_undef2;
	test_array[157] = test_undef3;
	test_array[158] = test_hex19;
	test_array[159] = test_zeroarg9;
	test_array[160] = test_mix2;
	test_array[161] = test_float29;
	test_array[162] = test_float30;
	test_array[163] = test_zeroarg10;
	test_array[164] = test_zeroarg11;
	test_array[165] = test_octal19;
	test_array[166] = test_pointer5;
	test_array[167] = test_pointer6;
	test_array[168] = test_binary4;
	test_array[169] = test_zeroarg12;
	test_array[170] = test_zeroarg13;
	i = 1;
	test_passed = 0;
	// test_array[117]();
	if (argc == 1)
	{
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
	}
	else
	{
		if (argv[1][0] == 'f')
		{
			int ids_array[] = {41, 43, 44, 45, 46, 56, 57, 58, 59, 62, \
			63, 64, 65, 66, 67, 68, 69, 78, 114, 115, 116, 117, 118, 120, \
			121, 145, 146, 147, 161, 162};
			i = 0;
			while (i < (int)(sizeof(ids_array) / sizeof(ids_array[0])))
			{
				test_result = test_array[ids_array[i]]();
				if (test_result == 0)
					test_passed++;
				i++;
			}
		}
		else if (argv[1][0] == 'o')
		{
			int ids_array[] = {16, 17, 18, 49, 52, 53, 61, 74, 76, 79, 81, \
			82, 84, 87, 88, 89, 110};
			i = 0;
			while (i < (int)(sizeof(ids_array) / sizeof(ids_array[0])))
			{
				test_result = test_array[ids_array[i]]();
				if (test_result == 0)
					test_passed++;
				i++;
			}
		}
		else if (argv[1][0] == 'u')
		{
			int ids_array[] = {51, 54, 80, 83, 85, 111, 112, 123};
			i = 0;
			while (i < (int)(sizeof(ids_array) / sizeof(ids_array[0])))
			{
				test_result = test_array[ids_array[i]]();
				if (test_result == 0)
					test_passed++;
				i++;
			}
		}
		else if (argv[1][0] == 'i')
		{
			int ids_array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 19, 20, 50, 71, \
			72, 73, 104};
			i = 0;
			while (i < (int)(sizeof(ids_array) / sizeof(ids_array[0])))
			{
				test_result = test_array[ids_array[i]]();
				if (test_result == 0)
					test_passed++;
				i++;
			}
		}
		else if (argv[1][0] == 'z')
		{
			int ids_array[] = {8, 20, 33, 52, 53, 54, 55, 70, 71, 85, 86, 87, 88, 89, \
			90, 91, 106, 107, 109, 110, 112, 122, 123, 124, 134, 148, 149, 150, 151, 152, 153, 154,\
			159, 163, 164, 166, 167, 169};
			i = 0;
			while (i < (int)(sizeof(ids_array) / sizeof(ids_array[0])))
			{
				test_result = test_array[ids_array[i]]();
				if (test_result == 0)
					test_passed++;
				i++;
			}
		}
	}
	printf(ANSI_COLOR_CYAN"\n--------------------------------------------");
	printf("\nTests that Passed	-> %d / %d", test_passed, i - 1);
	printf("\n--------------------------------------------\n");
	return (0);
}
