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

int				check_valid_specifier(char str)
{
	if (ft_isalpha(str) == 1)
		return (0);
	if (str == '%')
		return (0);
	return (1);
}

int				check_valid_char_after_percent(char str, t_format *t_flags)
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

int				next_char(const char *str, t_format *t_flags, t_print *t_prnt)
{
	if (*str == '%')
	{
		t_prnt->writer(&"%", 1, t_prnt);
		(*t_flags).total_chars_printed++;
		return (1);
	}
	else if (check_valid_char_after_percent(*str, t_flags) == 1)
		return (2);
	else
		return (3);
}

int				ft_printf_genericfunc(t_format *t_flags, t_print *t_prnt, \
										const char *str, va_list argptr)
{
	int			result;

	initialize_buffer(t_flags, t_prnt);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			result = next_char(str, t_flags, t_prnt);
			if (result == 2)
				break ;
			else if (result == 3)
			{
				clear_formatstruct(t_flags, t_prnt);
				save_flags(t_flags, &str);
				// t_flags.fd = fd;
				if (check_valid_specifier(*str) == 0)
					print_arg(argptr, t_flags, t_prnt);
				else
					break ;
			}
		}
		else
		{
			while ((*str != '\0') && (*str != '%'))
			{
				t_prnt->writer(str, 1, t_prnt);
				t_flags->total_chars_printed += 1;
				str++;
			}
			str--;
		}
		str++;
	}
	end_of_string(t_prnt);
	return (t_flags->total_chars_printed);
}
