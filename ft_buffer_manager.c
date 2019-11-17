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

int					store_to_buffer(unsigned char **un_str, int len, \
									t_format *t_flags, t_print *t_prnt, int i)
{
	while (((*t_prnt).buf_index < BUFFER_SIZE) && (i < len))
	{
		if ((*t_prnt).print_end != 1)
		{
			(*t_prnt).buffer[(*t_prnt).buf_index] = **un_str;
			(*t_prnt).buf_index++;
			(*un_str)++;
		}
		i++;
	}
	if (((*t_prnt).buf_index == BUFFER_SIZE) || ((*t_prnt).print_end == 1))
	{
		write((*t_flags).fd, (*t_prnt).buffer, (*t_prnt).buf_index);
		(*t_prnt).buf_index = 0;
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
	if (len < BUFFER_SIZE)
		store_to_buffer(&un_str, len, t_flags, t_prnt, i);
	else
	{
		while (i < len)
		{
			i = store_to_buffer(&un_str, len, t_flags, t_prnt, i);
		}
	}
}
