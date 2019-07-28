/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printing_functions.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/24 19:46:10 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/07/24 20:25:51 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_string(char *str, size_t index, ...)
{
	va_list		argptr;
	//char		*ptr;

	va_start(argptr, str);
	//ptr = va_arg(argptr, char *);
	//ft_putstr(ptr);
	va_end(argptr);
	return (0);
}
