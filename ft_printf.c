/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/16 13:33:53 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/07/16 13:45:05 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					find_no_args(char *str)
{
	int			no_args;
	int			i;

	no_args = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			no_args++;
		if ((str[i] == '%') && str[i + 1] == '%')
			no_args--;
		i++;
	}
	return (no_args);
}

int					ft_printf(char *str, ...)
{
	t_format		t_flags;
	va_list			argptr;

	va_start(argptr, str);
	clear_formatstruct(&t_flags);
	if (error_check(t_flags, str) == 1)
		return (0);
	t_flags.total_chars_printed = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			if (*str == '%')
			{
				ft_putchar('%');
				t_flags.total_chars_printed++;
			}
			else
			{
				clear_formatstruct(&t_flags);
				save_flags(&t_flags, &str);
				print_arg(argptr, &t_flags);
			}
		}
		else
		{
			ft_putchar(*str);
			t_flags.total_chars_printed++;
			// printf("char = %c , number_of_chars = %d \n", *str, t_flags.total_chars_printed);
		}
		str++;
	}
	va_end(argptr);
	return (t_flags.total_chars_printed);
}
