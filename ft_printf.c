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
	t_flagstruct	t_flags;
	va_list			argptr;

	printf(ANSI_COLOR_GREEN);
	t_flags.flags = 0;
	va_start(argptr, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			clear_flagstruct(&t_flags);
			save_flags(&t_flags, &str);
			// print_format(&t_flags);
			print_arg(argptr, *str, t_flags);
		}
		else
			ft_putchar(*str);
		str++;
	}
	va_end(argptr);
	return (0);
}
