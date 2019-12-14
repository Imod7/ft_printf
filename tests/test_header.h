/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_header.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/09 00:31:01 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/08/09 00:31:03 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HEADER_H
# define TEST_HEADER_H

# define ANSI_COLOR_RESET   "\x1b[0m"
# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW	"\x1b[33m"
# define ANSI_COLOR_BLUE	"\x1b[34m"
# define ANSI_COLOR_MAGENTA	"\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"

# include "../ft_printf_ORIGINAL/includes/ft_printf.h"
# include <assert.h>
# include <fcntl.h>
# include <float.h>
# include <stdio.h>

typedef int test_func(void);

int		test_int1(void);
int		test_int2(void);
int		test_int3(void);
int		test_int4(void);
int		test_int5(void);
int		test_int6(void);
int		test_int7(void);
int		test_int8(void);
int		test_int9(void);
int		test_int10(void);
int		test_int11(void);
int		test_int12(void);
int		test_int13(void);
int		test_int14(void);
int		test_int15(void);
int		test_int16(void);
int		test_int17(void);
int		test_int18(void);
int		test_int19(void);
int		test_int20(void);
int		test_int21(void);
int		test_char1(void);
int		test_char2(void);
int		test_char3(void);
int		test_char4(void);
int		test_char5(void);
int		test_char6(void);
int		test_char7(void);
int		test_char8(void);
int		test_octal1(void);
int		test_octal2(void);
int		test_octal3(void);
int		test_octal4(void);
int		test_octal5(void);
int		test_octal6(void);
int		test_octal7(void);
int		test_octal8(void);
int		test_octal9(void);
int		test_octal10(void);
int		test_octal11(void);
int		test_octal12(void);
int		test_octal13(void);
int		test_octal14(void);
int		test_octal15(void);
int		test_octal16(void);
int		test_octal17(void);
int		test_octal18(void);
int		test_octal19(void);
int		test_hex1(void);
int		test_hex2(void);
int		test_hex3(void);
int		test_hex4(void);
int		test_hex5(void);
int		test_hex6(void);
int		test_hex7(void);
int		test_hex8(void);
int		test_hex9(void);
int		test_hex10(void);
int		test_hex11(void);
int		test_hex12(void);
int		test_hex13(void);
int		test_hex14(void);
int		test_hex15(void);
int		test_hex16(void);
int		test_hex17(void);
int		test_hex18(void);
int		test_hex19(void);
int		test_i1(void);
int		test_i2(void);
int		test_i3(void);
int		test_i4(void);
int		test_i5(void);
int		test_i6(void);
int		test_i7(void);
int		test_i8(void);
int		test_i9(void);
int		test_i10(void);
int		test_i11(void);
int		test_i12(void);
int		test_double1(void);
int		test_pointer1(void);
int		test_pointer2(void);
int		test_pointer3(void);
int		test_pointer4(void);
int		test_pointer5(void);
int		test_pointer6(void);
int		test_exceptions1(void);
int		test_exceptions2(void);
int		test_exceptions3(void);
int		test_exceptions4(void);
int		test_exceptions5(void);
int		test_exceptions6(void);
int		test_string1(void);
int		test_string2(void);
int		test_string3(void);
int		test_string4(void);
int     test_string5(void);
int     test_string6(void);
int     test_string7(void);
int     test_string8(void);
int     test_string9(void);
int     test_string10(void);
int     test_string11(void);
int     test_string12(void);
int		test_u1(void);
int		test_u2(void);
int		test_u3(void);
int		test_u4(void);
int		test_u5(void);
int		test_u6(void);
int		test_u7(void);
int		test_u9(void);
int		test_u10(void);
int		test_float1(void);
int		test_float2(void);
int		test_float3(void);
int		test_float4(void);
int		test_float5(void);
int		test_float6(void);
int		test_float7(void);
int		test_float8(void);
int		test_float9(void);
int		test_float10(void);
int		test_float11(void);
int		test_float12(void);
int		test_float13(void);
int		test_float14(void);
int		test_float15(void);
int		test_float16(void);
int		test_float17(void);
int		test_float18(void);
int		test_float19(void);
int		test_float20(void);
int		test_float21(void);
int		test_float22(void);
int		test_float23(void);
int		test_float24(void);
int		test_float25(void);
int		test_float26(void);
int		test_float27(void);
int		test_float28(void);
int		test_float29(void);
int		test_float30(void);
int		test_sprintf1(void);
int		test_sprintf2(void);
int		test_sprintf3(void);
int		test_mix1(void);
int		test_mix2(void);
int		test_binary1(void);
int		test_binary2(void);
int		test_binary3(void);
int		test_binary4(void);
int		test_snprintf1(void);
int		test_snprintf2(void);
int		test_snprintf3(void);
int		test_memory1(void);
int		test_zeroarg1(void);
int		test_zeroarg2(void);
int		test_zeroarg3(void);
int		test_zeroarg4(void);
int		test_zeroarg5(void);
int		test_zeroarg6(void);
int		test_zeroarg7(void);
int		test_zeroarg8(void);
int		test_zeroarg9(void);
int		test_zeroarg10(void);
int		test_zeroarg11(void);
int		test_zeroarg12(void);
int		test_zeroarg13(void);
int		test_undef1(void);
int		test_undef2(void);
int		test_undef3(void);

#endif