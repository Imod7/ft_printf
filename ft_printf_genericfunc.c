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

void			find_percent(int fd, const char *str, t_format *t_flags)
{
	char		c;
	int			len;

	len = 0;
	while ((*str != '%') && (*str == ' '))
	{
		// c = ' ';
		// write(fd, &c, 1);
		str++;
	}
	if (*str == '%')
	{
		c = '%';
		write(fd, &c, 1);
		str++;
		(*t_flags).total_chars_printed++;
	}
}

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
			// if ((*str == '%') || (*str == ' '))
			// 	find_percent(fd, str, &t_flags);
			if (*str == '%')
			{
				c = '%';
				write(fd, &c, 1);
				t_flags.total_chars_printed++;
			}
			else
			{
				// printf(ANSI_COLOR_GREEN"\nNEXT CALL OF PRINTF\n");
				clear_formatstruct(&t_flags);
				save_flags(&t_flags, &str);
				t_flags.fd = fd;
				print_arg(argptr, &t_flags);
			}
		}
		else
		{
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
