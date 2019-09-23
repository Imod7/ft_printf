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

# include <assert.h>
# include <fcntl.h>

// # define ANSI_COLOR_RESET   "\x1b[0m"
// # define ANSI_COLOR_RED     "\x1b[31m"
// # define ANSI_COLOR_GREEN   "\x1b[32m"
// # define ANSI_COLOR_YELLOW	"\x1b[33m"
// # define ANSI_COLOR_MAGENTA	"\x1b[35m"
// # define ANSI_COLOR_CYAN    "\x1b[36m"

typedef void test_func(void);

void	test_int1(void);
void	test_int2(void);
void	test_int3(void);
void	test_int4(void);
void	test_int5(void);
void	test_int6(void);
void	test_int7(void);
void	test_int8(void);
void	test_int9(void);
void	test_int10(void);
void	test_int11(void);
void	test_int12(void);
void	test_char1(void);
void    test_char2(void);
void    test_char3(void);
void    test_char4(void);
void    test_char5(void);
void    test_char6(void);
void    test_char7(void);
void	test_octal1(void);
void	test_octal2(void);
void	test_octal3(void);
void	test_octal4(void);
void	test_octal5(void);
void	test_octal6(void);
void	test_hex1(void);
void	test_hex2(void);
void	test_hex3(void);
void	test_hex4(void);
void	test_hex5(void);
void	test_hex6(void);
void	test_hex7(void);
void	test_hex8(void);
void	test_hex9(void);
void	test_hex10(void);
void	test_hex11(void);
void	test_hex12(void);
void 	test_i1(void);
void	test_i2(void);
void	test_i3(void);
void	test_i4(void);
void	test_double1(void);
void	test_pointer1(void);
void	test_pointer2(void);
void	test_exceptions1(void);
void	test_exceptions2(void);
void	test_float1(void);
void	test_float2(void);
void	test_float3(void);
void	test_float4(void);
void	test_float5(void);
void	test_string1(void);
void	test_string2(void);
void	test_string3(void);
void	test_u1(void);
void	test_u2(void);
void	test_hex13(void);

# endif