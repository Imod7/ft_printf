/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/24 13:23:12 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/08/13 22:07:07 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"

# define ANSI_COLOR_RESET   "\x1b[0m"
# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW	"\x1b[33m"
# define ANSI_COLOR_MAGENTA	"\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"

# define FLAG_MINUS (1 << 0)
# define FLAG_PLUS (1 << 1)
# define FLAG_SPACE (1 << 2)
# define FLAG_ZERO (1 << 3)
# define FLAG_HT (1 << 4)
# define FLAG_APOSTR (1 << 5)
# define FLAG_PRECIS (1 << 6)
# define FLAG_ASTER (1 << 7)
# define FLAG_NEGAT (1 << 8)

typedef enum	e_modifier {
	N,
	H,
	HH,
	L,
	LL
}				t_modifier;

typedef struct	s_format
{
	int			flags;
	int			minfw;
	int			precision;
	char		argtype;
	int			special_chars_printed;
	int			total_chars_printed;
	int			float_decpart_len;
	int			fd;
	t_modifier	modifier;
}				t_format;

int             ft_printf_genericfunc(int fd, const char *str, va_list	argptr);
int				ft_printf(const char *str, ...);
int				ft_dprintf(int fd, const char *str, ...);
void			save_flags(t_format *t_flags, const char **str);
int				error_check(t_format t_flags, const char *str);
void			print_arg(va_list argptr, t_format *t_flags);
void			print_sign(t_format *t_flags);
void			print_padding(t_format *t_flags, int no_digits);
void			check_modifier(long long *arg, t_format *t_flags);
void			check_modif_un(unsigned long long *arg, t_format *t_flags);
int				number_of_digits(long long num);
int				number_of_digits_un(unsigned long long num, t_format t_flags);
void			clear_formatstruct(t_format *t_flags);
void			ft_putnbr_int(long long n, int fd);
void			ft_putnbr_octal(unsigned long long n, int fd);
void			ft_putnbr_hex(unsigned long long n, int fd);
void			ft_putnbr_hex_capit(unsigned long long n, int fd);
void			ft_putnbr_un_int(unsigned long long n, int fd);
void			print_string(va_list argptr, t_format *t_flags);
void			print_character(va_list argptr, t_format *t_flags);
void			print_other(char arg, t_format *t_flags);
// void			print_octal(va_list argptr, t_format *t_flags);
void			print_hex_octal(va_list argptr, t_format *t_flags);
// long long		return_decimal_part_as_int(double num);
void			clear_forfloat(t_format *t_flags);
void			print_float(va_list argptr, t_format *t_flags);
void			intwithminus(long long arg, t_format *t_flags, int len);
void			int_otherflag(long long arg, t_format *t_flags, int len);
char			*ft_itoa_float(float n);
void			add_to_buffer(int fd, const char **str, t_format *t_flags);
void			print_binary(long long flag_num);
long long		invert_allbits(long long num);
long long		binary_addone(long long num);
/* Common functions */
void			check_plusflag(t_format *t_flags);
void			check_arg_zero(unsigned long long *arg, t_format *t_flags);
void			print_order(t_format *t_flags, int len);
void			print_inverse(t_format *t_flags, int len);
void			print_number(unsigned long long arg, t_format *t_flags);

#endif
