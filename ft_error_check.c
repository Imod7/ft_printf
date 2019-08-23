/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_error_check.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/11 17:32:39 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/08/11 17:39:47 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		error_check(t_format t_flags, const char *str)
{
	clear_formatstruct(&t_flags);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			clear_formatstruct(&t_flags);
			save_flags(&t_flags, &str);
		}
		else if (t_flags.argtype != 0)
		{
			if (((t_flags.flags & FLAG_ASTER) > 0) && \
			((t_flags.flags & FLAG_SPACE) > 0))
			{
				ft_putstr("Error!\n");
				return (1);
			}
			if (t_flags.argtype == 'c')
			{
				if ((t_flags.flags & FLAG_PLUS) > 0)
				{
					ft_putstr("Error!\n");
					return (1);
				}
				if (((t_flags.flags & FLAG_MINUS) > 0) && \
				((t_flags.flags & FLAG_ZERO) > 0))
				{
					ft_putstr("Error!\n");
					return (1);
				}
				if ((t_flags.modifier == H) || (t_flags.modifier == HH) || \
				(t_flags.modifier == LL))
				{
					ft_putstr("Error!\n");
					return (1);
				}
			}
			if (t_flags.argtype == 'o')
			{
				if ((t_flags.flags & FLAG_SPACE) > 0)
				{
					ft_putstr("Error!\n");
					return (1);
				}
			}
		}
		str++;
	}
	return (0);
}
