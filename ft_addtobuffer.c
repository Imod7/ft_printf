/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_addtobuffer.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/14 10:16:58 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/09/14 10:30:31 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

// size_t		len_until_arg(const char *s, char *str_result)
// {
// 	size_t	length;

// 	length = 0;
// 	while ((*s != '\0') && (*s != '%'))
// 	{
// 		str_result[length] = *s;
// 		length++;
// 		s++;
// 	}
// 	return (length);
// }

void		add_to_buffer(const char **str, t_format *t_flags, \
						t_print *tprnt)
{
	char	str_result[1000];
	size_t	length;

	length = 0;
	while ((**str != '\0') && (**str != '%'))
	{
		str_result[length] = **str;
		length++;
		(*str)++;
	}
	// write(fd, str_result, length);
	buffer_writer(str_result, length, t_flags, tprnt);
	(*t_flags).total_chars_printed = (*t_flags).total_chars_printed + length;
}
