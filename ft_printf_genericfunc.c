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

int				next_char(const char *str, t_format *t_flags, t_print *tprnt)
{
	if (*str == '%')
	{
		// write(fd, &"%", 1);
		buffer_writer(&"%", 1, t_flags, tprnt);
		(*t_flags).total_chars_printed++;
		return (1);
	}
	else if (check_valid_char_after_percent(*str, t_flags) == 1)
		return (2);
	else
		return (3);
}

void			print_end(t_format *t_flags, t_print *t_prnt)
{
	// printf(ANSI_COLOR_MAGENTA"\n PRINTING index = '%d' and buffer = \n --- '%s' ---\n\n\n"ANSI_COLOR_RESET, (*t_prnt).buf_index, ((*t_prnt).buffer));
	// printf(ANSI_COLOR_RED"\n THE END PRINTING index = '%d' and buffer = \n\n\n--> '%s' <--\n\n\n"ANSI_COLOR_RESET, (*t_prnt).buf_index, ((*t_prnt).buffer));
	(*t_prnt).print_end = 1;
	buffer_writer("", 1, t_flags, t_prnt);
	// (*t_prnt).buffer[0] = 0;
	ft_memset((*t_prnt).buffer, 0, BUFFER_SIZE);
	(*t_flags).fd = 0;
}

void			initialize(t_format *t_flags, t_print *t_prnt)
{
	ft_memset((*t_prnt).buffer, 0, BUFFER_SIZE);
	(*t_prnt).buf_index = 0;
	(*t_flags).total_chars_printed = 0;
	(*t_prnt).print_end = 0;
}

int				ft_printf_genericfunc(int fd, const char *str, va_list argptr)
{
	t_format	t_flags;
	t_print		t_prnt;
	int			result;

	clear_formatstruct(&t_flags, &t_prnt);
	t_flags.fd = fd;
	initialize(&t_flags, &t_prnt);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			result = next_char(str, &t_flags, &t_prnt);
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
			{
				// printf(ANSI_COLOR_YELLOW"\n ADD TO BUFFER  "ANSI_COLOR_RESET);
				add_to_buffer(&str, &t_flags, &t_prnt);
			}
			str--;
		}
		str++;
	}
	print_end(&t_flags, &t_prnt);
	return (t_flags.total_chars_printed);
}
