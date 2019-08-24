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

int					all_flags_retrieved(char str)
{
	if (str == '*' || str == '-' || str == '+')
		return (0);
	if (str == ' ' || str == '0' || str == '#')
		return (0);
	if (str == '.')
		return (0);
	if ((str == 'h') && (str != 'h'))
		return (0);
	if ((str == 'h') && (str == 'h'))
		return (0);
	if ((str == 'l') && (str != 'l'))
		return (0);
	if ((str == 'l') && (str == 'l'))
		return (0);
	if (ft_isdigit(str) == 1)
		return (0);
	return (1);
}

int					save_modifier(const char *str, t_format *t_flags)
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

void				save_flags(t_format *t_flags, const char **str)
{
	int				digits;

	while (**str != '\0' && all_flags_retrieved(**str) == 0)
	{
		if (**str == '*')
			(*t_flags).flags |= FLAG_ASTER;
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
		if ((ft_isdigit(**str) == 1) && (**str != '0') && \
		((*t_flags).minfw == 0))
		{
			(*t_flags).minfw = ft_atoi(*str);
			digits = number_of_digits((*t_flags).minfw);
			(*str) = (*str) + digits - 1;
		}
		if (**str == '.')
		{
			(*t_flags).flags |= FLAG_PRECIS;
			(*str)++;
			// printf("OUTSIDE >>>> str = %c, precision=%d, minfw=%d, special_chars=%d\n", **str, (*t_flags).precision, (*t_flags).minfw, (*t_flags).special_chars_printed);
			if ((ft_isdigit(**str) == 1) && (**str != '0') && \
			((*t_flags).precision == 0))
			{
				(*t_flags).precision = ft_atoi(*str);
				digits = number_of_digits((*t_flags).precision);
				(*str) = (*str) + digits - 1;
				// printf("INSIDE >>>> precision=%d, minfw=%d, special_chars=%d\n", (*t_flags).precision, (*t_flags).minfw, (*t_flags).special_chars_printed);
			}
			if ((*t_flags).minfw == 0)
				(*t_flags).minfw = (*t_flags).precision;
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

/*
** The only thing we do not initialize in the function clear_formatstruct
** is the member total_chars_printed because we need to continue counting
** for more than one arguments
*/

void				clear_formatstruct(t_format *t_flags)
{
	(*t_flags).flags = 0;
	(*t_flags).minfw = 0;
	(*t_flags).precision = 0;
	(*t_flags).argtype = 0;
	(*t_flags).special_chars_printed = 0;
	(*t_flags).modifier = N;
	(*t_flags).float_decpart_len = 0;
	(*t_flags).fd = 0;
}

void				clear_forfloat(t_format *t_flags)
{
	(*t_flags).flags = 0;
	(*t_flags).minfw = 0;
	(*t_flags).special_chars_printed = 0;
}
