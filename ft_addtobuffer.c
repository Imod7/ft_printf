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

void		add_to_buffer(const char **str, t_format *t_flags, \
						t_print *tprnt)
{
	char	str_result[BUFFER_SIZE];
	size_t	length;

	length = 0;
	while ((**str != '\0') && (**str != '%'))
	{
		str_result[length] = **str;
		length++;
		(*str)++;
	}
	buffer_writer(str_result, length, t_flags, tprnt);
	(*t_flags).total_chars_printed = (*t_flags).total_chars_printed + length;
}
