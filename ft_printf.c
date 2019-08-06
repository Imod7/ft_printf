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

int					found_conversion(char str)
{
	//printf("     Inside FOUND_CONVERSION - str[index] = %c \n", str[index]);
	if (str == 'c' || str == 's' || str == 'p')
		return (1);
	if (str == 'd' || str == 'i' || str == 'o')
		return (1);
	if (str == 'u' || str == 'x' || str == 'X')
		return (1);
	if (str == 'f' || str == '%')
		return (1);
	return (0);
}

int					save_flags(t_flagstruct *t_flags, char **str)
{
	// ft_putstr(ANSI_COLOR_CYAN "\n\n Inside SAVE_FLAGS function \n");
	// ft_putstr("  Before Saving Flags \n");
	(*t_flags).flags = 0;
	// printf("  str[] = %c ,flags = %u \n", **str, (*t_flags).flags);
	// printf(ANSI_COLOR_RESET);
	while (**str != '\0' && found_conversion(**str) == 0)
	{
		if (**str == '-')
			(*t_flags).flags |= FLAG_MINUS;
		if (**str == '+')
			(*t_flags).flags |= FLAG_PLUS;
		if (**str == ' ')
			(*t_flags).flags |= FLAG_SPACE;
		if (**str == '0')
			(*t_flags).flags |= FLAG_ZERO;
		if (**str == '#')
			(*t_flags).flags |= FLAG_HT;
		(*str)++;
	}
	// ft_putstr(ANSI_COLOR_CYAN "  After Saving Flags \n");
	// printf("  str = %c ,flags = %u \n", **str, (*t_flags).flags);
	// printf(ANSI_COLOR_RESET);
	return (0);
}

int					ft_printf(char *str, ...)
{
	t_flagstruct	t_flags;
	va_list			argptr;

	t_flags.flags = 0;
	va_start(argptr, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			save_flags(&t_flags, &str);
			print_format(t_flags);
			print_arg(argptr, *str);
		}
		else
			ft_putchar(*str);
		str++;
	}
	va_end(argptr);
	return (0);
}
