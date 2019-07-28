/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/24 13:23:12 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/07/24 13:25:00 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/includes/libft.h"

#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_CYAN    "\x1b[36m"

#define FLAG_MINUS (1 << 0) // 0000 0001 => 1
#define FLAG_PLUS (1 << 1)  // 0000 0010 => 2
#define FLAG_SPACE (1 << 2) // 0000 0100
#define FLAG_ZERO (1 << 3)  // 0000 1000
#define FLAG_HT (1 << 4);   // 0001 0000 

typedef struct  s_flaglist
{
    uint16_t    flags;       //0100110000000000
    int         minfw;      // minimum field width
    int         precision;  // max num of char of a str, number of digits after decimal or float, number of digits for an int
    char        argtype;    //for saving which type it is
    int         *pos;       //position of argument
}               t_flaglist;

int			save_flags(char *str, size_t index);

# endif
