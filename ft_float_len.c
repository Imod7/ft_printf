/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_float_len.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 09:57:25 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/10/30 09:57:27 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int				length_fraction(char *fr)
{
	size_t		index;
	int			len;

	index = 0;
	len = 0;
	while (fr[index] != 0)
	{
		index++;
		len++;
	}
	return (len);
}

int				length_product(short *pr)
{
	size_t		index;
	int			len;

	index = 0;
	len = 0;
	while (pr[index] == 0)
		index++;
	while (pr[index] != 0)
	{
		index++;
		len++;
	}
	return (len);
}
