/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_saveflags.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/08 15:07:14 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/08/08 15:07:17 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					found_conversion(char str)
{
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

int					save_modifier(char *str, t_flagstruct *t_flags)
{
	if ((str[0] == 'h') && (str[1] != 'h'))
		(*t_flags).modifier = H;
	if ((str[0] == 'h') && (str[1] == 'h'))
		(*t_flags).modifier = HH;
	if ((str[0] == 'l') && (str[1] != 'l'))
		(*t_flags).modifier = L;
	if ((str[0] == 'l') && (str[1] == 'l'))
		(*t_flags).modifier = LL;
	return (0);
}

void				save_flags(t_flagstruct *t_flags, char **str)
{
	int				digits;

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
		if (**str == '.')
			(*t_flags).flags |= FLAG_PRECIS;
		if ((ft_isdigit(**str) == 1) && (**str != '0'))
		{
			(*t_flags).minfw = ft_atoi(*str);
			digits = number_of_digits((*t_flags).minfw, *t_flags);
			(*str) = (*str) + digits - 1;
		}
		if ((**str == 'h' || **str == 'l') && ((*t_flags).modifier == 0))
			save_modifier(*str, t_flags);
		(*str)++;
	}
	(*t_flags).argtype = **str;
	// printf("\n --> flag modifier = %i \n", (*t_flags).modifier);
	// printf("\n --> str = %c ,flags = %u \n", **str, (*t_flags).flags);
	// print_binary((*t_flags).flags);
}

void				clear_flagstruct(t_flagstruct *t_flags)
{
	(*t_flags).flags = 0;
	(*t_flags).minfw = 0;
	(*t_flags).precision = 0;
	(*t_flags).argtype = 0;
	(*t_flags).chars_printed = 0;
	(*t_flags).modifier = 0;
}
