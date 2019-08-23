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

int					ft_printf(const char *str, ...)
{
	va_list		argptr;
	int			result;
	int			fd;

	fd = 1;
	va_start(argptr, str);
	result = ft_printf_allversions(fd, str, argptr);
	va_end(argptr);
	return (result);
}

int					ft_dprintf(int fd, const char *str, ...)
{
	va_list		argptr;
	int			result;

	va_start(argptr, str);
	result = ft_printf_allversions(fd, str, argptr);
	va_end(argptr);
	return (result);
}
