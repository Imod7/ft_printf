/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_buffer_manager.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 12:53:44 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/11/13 12:55:45 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int				store_to_buffer(unsigned char **un_str, int len, \
									t_format *t_flags, t_print *t_prnt, int i)
{
	while (((*t_prnt).buf_index < 1000) && (i < len))
	{
		if ((*t_prnt).print_end != 1)
		{
			// if (((*t_prnt).buf_index >= 0) && ((*t_prnt).buf_index < 10))
			// 	printf(ANSI_COLOR_GREEN"\n >> index = '%d', i = %d, un_str = %c"ANSI_COLOR_RESET, (*t_prnt).buf_index, i, **un_str);
			(*t_prnt).buffer[(*t_prnt).buf_index] = **un_str;
			(*t_prnt).buf_index++;
			(*un_str)++;
		}
		i++;
	}
	if (((*t_prnt).buf_index == 1000) || ((*t_prnt).print_end == 1))
	{
		// printf(ANSI_COLOR_CYAN"\n >> index = '%d', i = %d, and buffer ='%s'"ANSI_COLOR_RESET, (*t_prnt).buf_index, i, (*t_prnt).buffer);
		write((*t_flags).fd, (*t_prnt).buffer, (*t_prnt).buf_index);
		(*t_prnt).buf_index = 0;
		// (*t_flags).total_chars_printed = (*t_flags).total_chars_printed + (*t_prnt).buf_index);
	}
	return (i);
}

void				buffer_writer(const void *str, int len, t_format *t_flags, \
							t_print *t_prnt)
{
	int				i;
	unsigned char	*un_str;

	un_str = (unsigned char *)str;
	i = 0;
	// sleep(1);
	// printf(ANSI_COLOR_YELLOW"\n >> str = %s, len = %d", un_str, len);
	if (len < 1000)
		store_to_buffer(&un_str, len, t_flags, t_prnt, i);
	else
	{
		while (i < len)
		{
			// printf(ANSI_COLOR_YELLOW"\n >> i = %d, len = %d, un = %c", i, len, *un_str);
			i = store_to_buffer(&un_str, len, t_flags, t_prnt, i);
		}
		// (*t_flags).total_chars_printed = (*t_flags).total_chars_printed + len;
	}
}
