/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dprintf.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/23 18:22:44 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/08/23 18:22:46 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf_allversions(int fd, const char *str, va_list argptr)
{
    t_format	t_flags;
	char		c;

	clear_formatstruct(&t_flags);
	// if (error_check(t_flags, str) == 1)
	// 	return (0);
	t_flags.total_chars_printed = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			if (*str == '%')
			{
				c = '%';
				write(fd, &c, 1);
				t_flags.total_chars_printed++;
			}
			else
			{
				clear_formatstruct(&t_flags);
				save_flags(&t_flags, &str);
				t_flags.fd = fd;
				print_arg(argptr, &t_flags);
			}
		}
		else
		{
			write(fd, str, 1);
			t_flags.total_chars_printed++;
			// printf("char = %c \n", *str);
			// printf("number_of_chars = %d \n", t_flags.total_chars_printed);
		}
		str++;
	}
	return (t_flags.total_chars_printed);
}
