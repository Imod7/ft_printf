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

int					found_conversion(char *str, size_t index)
{
	//printf("     Inside FOUND_CONVERSION - str[index] = %c \n", str[index]);
	if (str[index] == 'c' || str[index] == 's' || str[index] == 'p')
		return (1);
	if (str[index] == 'd' || str[index] == 'i' || str[index] == 'o')
		return (1);
	if (str[index] == 'u' || str[index] == 'x' || str[index] == 'X')
		return (1);
	if (str[index] == 'f' || str[index] == '%')
		return (1);
	return (0);
}

int					save_flags(char *str, size_t index)
{
	t_flagstruct	*t_flags;

	//ft_putstr(ANSI_COLOR_CYAN "\n Inside SAVE_FLAGS function \n");
	//ft_putstr("  Before Saving Flags \n");
	t_flags = malloc(sizeof(t_flagstruct));
	t_flags->flags = 0;
	//printf("  str[%zu] = %c ,flags = %u \n", index, str[index], t_flags->flags);
	printf(ANSI_COLOR_RESET);
	while (str[index] != '\0' && found_conversion(str, index) == 0)
	{
		if (str[index] == '-')
			t_flags->flags |= FLAG_MINUS;
		if (str[index] == '+')
			t_flags->flags |= FLAG_PLUS;
		if (str[index] == ' ')
			t_flags->flags |= FLAG_SPACE;
		if (str[index] == '0')
			t_flags->flags |= FLAG_ZERO;
		if (str[index] == '#')
			t_flags->flags |= FLAG_HT;
		index++;
	}
	//ft_putstr(ANSI_COLOR_CYAN "  After Saving Flags \n");
	//printf("  str[%zu] = %c ,flags = %u \n", index, str[index], t_flags->flags);
	printf(ANSI_COLOR_RESET);
	return (0);
}

int					ft_printf(char *str, ...)
{
	va_list			argptr;
	int				no_args;
	int				count;
	size_t			i;
	//char		*ptr;

	count = 0;
	i = 0;
	no_args = find_no_args(str);
	printf("Number of arguments = %d \n", no_args);
	va_start(argptr, str);
	while (count < no_args)
	{
		while (str[i] != '\0' && str[i] != '%')
		{
			printf(ANSI_COLOR_GREEN);
			ft_putchar(str[i]);
			printf(ANSI_COLOR_RESET);
			i++;
		}
		i++;
		save_flags(str, i);
		//ptr = va_arg(argptr, char *);
		//ft_putstr(ptr);
		count++;
		i = i + 2;
	}
	va_end(argptr);
	return (0);
}
