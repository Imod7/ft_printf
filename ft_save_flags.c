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

void				minfw_precision_flags(t_format *t_flags, const char **str)
{
	int				digits;

	if ((ft_isdigit(**str) == 1) &&
	((*t_flags).minfw == 0))
	{
		(*t_flags).minfw = ft_atoi(*str);
		digits = number_of_digits((*t_flags).minfw);
		(*str) = (*str) + digits - 1;
	}
	else if (**str == '.')
	{
		(*t_flags).flags |= FLAG_PRECIS;
		(*str)++;
		if ((ft_isdigit(**str) == 1) && \
		((*t_flags).precision == 0))
		{
			(*t_flags).precision = ft_atoi(*str);
			digits = number_of_digits((*t_flags).precision);
			(*str) = (*str) + digits - 1;
		}
		else
			(*str)--;
	}
}

void				save_flags(t_format *t_flags, const char **str)
{
	while (**str != '\0' && all_flags_retrieved(**str) == 0)
	{
		if (**str == '*')
			(*t_flags).flags |= FLAG_ASTER;
		else if (**str == '-')
			(*t_flags).flags |= FLAG_MINUS;
		else if (**str == '+')
			(*t_flags).flags |= FLAG_PLUS;
		else if (**str == ' ')
			(*t_flags).flags |= FLAG_SPACE;
		else if (**str == '0')
			(*t_flags).flags |= FLAG_ZERO;
		else if (**str == '#')
			(*t_flags).flags |= FLAG_HT;
		else if (((ft_isdigit(**str) == 1) &&
		((*t_flags).minfw == 0)) || (**str == '.'))
			minfw_precision_flags(t_flags, str);
		else if ((**str == 'h' || **str == 'l') && ((*t_flags).modifier == 0))
			save_modifier(*str, t_flags);
		(*str)++;
	}
	(*t_flags).argtype = **str;
	// printf("\nflag modifier= %i \n", (*t_flags).modifier);
	// printf("\nstr= %c,flags= %u \n", **str, (*t_flags).flags);
	// printf("\nminfw=%d,pr=%d\n", (*t_flags).minfw, (*t_flags).precision);
	// printf("\nstr='%s'\nprecision=%d\n", *str, (*t_flags).precision);
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
	(*t_flags).fd = 0;
}

void				clear_forfloat(t_float *fl_num)
{
	int				index;

	(*fl_num).f_num = 0;
	(*fl_num).mantissa = 0;
	index = 0;
	while (index < 5)
	{
		(*fl_num).exponent[index] = 0;
		index++;
	}
}
