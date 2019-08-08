/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/24 13:23:12 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/08/01 18:19:42 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/includes/libft.h"

#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_MAGENTA	"\x1b[35m"
#define ANSI_COLOR_YELLOW	"\x1b[33m"

#define FLAG_MINUS (1 << 0)     // 0000 0000 0001
#define FLAG_PLUS (1 << 1)      // 0000 0000 0010
#define FLAG_SPACE (1 << 2)     // 0000 0000 0100
#define FLAG_ZERO (1 << 3)      // 0000 0000 1000 
#define FLAG_HT (1 << 4)       // 0000 0001 0000 
#define FLAG_APOSTR (1 << 5)   // 0000 0010 0000
#define FLAG_PRECIS (1 << 6)   // 0000 0100 0000

typedef struct  s_flagstruct
{
	uint16_t    flags;
	int         minfw;      // minimum field width
	int         precision;  // saving the number after the dot
	char        argtype;    	// conversion type
	int			chars_printed;	// to keep track how many chars where printed
}               t_flagstruct;

int				ft_printf(char *str, ...);
int				save_flags(t_flagstruct *t_flags, char **str);
void			print_arg(va_list argptr, char c, t_flagstruct t_flags);
void			print_format(t_flagstruct t_flags);
void			print_binary(uint16_t flag_num);
int				number_of_digits(int minfw);
void			clear_flagstruct(t_flagstruct *t_flags);

# endif
