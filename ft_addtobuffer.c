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

#include "ft_printf.h"

size_t		len_until_arg(const char *s, char *str_result)
{
	size_t	length;

	length = 0;
	while ((*s != '\0') && (*s != '%'))
	{
		str_result[length] = *s;
		length++;
		s++;
	}
	return (length);
}

void		add_to_buffer(int fd, const char **str, t_format *t_flags)
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
	// len = len_until_arg(*str, &str_result);
	// printf("string BEFORE in add to buffer = %s, len = %lu\n", *str, len);
	// str_result = (char *)malloc(sizeof(char) * len);
	// str_result = ft_strncpy(str_result, *str, len);
	// printf("\nstr result COPIED = '%s' , fd = %d, len = %zu\n", str_result, fd, length);
	write(fd, str_result, length);
	// (*str) = (*str) + length;
	// printf("string AFTER in add to buffer = %s, \n", *str);
	(*t_flags).total_chars_printed = (*t_flags).total_chars_printed + length;
}
