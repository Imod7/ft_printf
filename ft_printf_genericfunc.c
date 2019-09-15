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

int				ft_printf_genericfunc(int fd, const char *str, va_list argptr)
{
	t_format	t_flags;
	char		c;

	clear_formatstruct(&t_flags);
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
			// printf("Printing string = %c \n", *str);
			while ((*str != '\0') && (*str != '%'))
				add_to_buffer(fd, &str, &t_flags);
			str--;
			// write(fd, str, 1);
			// t_flags.total_chars_printed++;
		}
		str++;
	}
	return (t_flags.total_chars_printed);
}
