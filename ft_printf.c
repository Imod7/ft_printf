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

int				find_no_args(char *str)
{
	int			no_args;
	int			i;

	no_args = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			no_args++;
		i++;
	}
	return (no_args);
}

int				found_conversion(char *str, size_t index)
{
	printf("inside found_conver - str[index] = %c \n", str[index]);
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

int				save_flags(char *str, size_t index)
{
	uint16_t	flags;

	flags = 0;
	ft_putstr("before conversion \n");
	printf("str[index] = %c ,flags = %d\n", str[index], flags);
	while (str[index] != '\0' && found_conversion(str, index) == 0)
	{
		if (str[index] == '-')
			flags |= FLAG_MINUS;
		if (str[index] == '+')
			flags |= FLAG_PLUS;
		if (str[index] == ' ')
			flags |= FLAG_SPACE;
		index++;
	}
	ft_putstr("after conversion \n");
	printf("str[index] = %c ,flags = %d\n", str[index], flags);
	return (0);
}

int				ft_printf(char *str, ...)
{
	va_list		argptr;
	int			no_args;
	int			count;
	size_t		i;
	//char		*ptr;

	count = 0;
	i = 0;
	no_args = find_no_args(str);
	va_start(argptr, str);
	while (count < no_args)
	{
		while (str[i] != '\0' && str[i] != '%')
		{
			ft_putchar(str[i]);
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

int				main(void)
{
	printf(ANSI_COLOR_GREEN "\n--- FT_PRINTF ---\n");
	ft_printf("Number = %+d %+-s really likes %s \n\n", 23, "Dom", "WindSurf");
	printf(ANSI_COLOR_RESET);
	printf(ANSI_COLOR_CYAN "\n--- PRINTF ---\n");
	printf("%s really likes %s \n\n", "Dom", "WindSurf");
	printf(ANSI_COLOR_RESET);
	return (0);
}
