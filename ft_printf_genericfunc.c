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

#include "includes/ft_printf.h"

int					check_valid_specifier(char str)
{
	if (ft_isalpha(str) == 1)
		return (0);
	if (str == '%')
		return (0);
	return (1);
}

int					check_valid_char_after_percent(char str, t_format *t_flags)
{
	if (str == '*' || str == '-' || str == '+')
		return (0);
	if (str == ' ' || str == '0' || str == '#')
		return (0);
	if (str == '.' || str == '%')
		return (0);
	if (ft_isalpha(str) == 1)
		return (0);
	if (ft_isdigit(str) == 1)
		return (0);
	if (str != '\0')
		(*t_flags).total_chars_printed++;
	return (1);
}

int				next_char(int fd, const char *str, t_format *t_flags)
{
	if (*str == '%')
	{
		write(fd, &"%", 1);
		(*t_flags).total_chars_printed++;
		return (1);
	}
	else if (check_valid_char_after_percent(*str, t_flags) == 1)
		return (2);
	else
		return (3);
}

int				ft_printf_genericfunc(int fd, const char *str, va_list argptr)
{
	t_format	t_flags;
	t_print		t_prnt;
	int			result;

	clear_formatstruct(&t_flags, &t_prnt);
	t_flags.total_chars_printed = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			result = next_char(fd, str, &t_flags);
			if (result == 2)
				break ;
			else if (result == 3)
			{
				clear_formatstruct(&t_flags, &t_prnt);
				save_flags(&t_flags, &str);
				t_flags.fd = fd;
				if (check_valid_specifier(*str) == 0)
					print_arg(argptr, &t_flags, &t_prnt);
				else
					break ;
			}
		}
		else
		{
			while ((*str != '\0') && (*str != '%'))
				add_to_buffer(fd, &str, &t_flags);
			str--;
		}
		str++;
	}
	return (t_flags.total_chars_printed);
}
