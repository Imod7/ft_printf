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

	len = 0;
	if (pr[0] == 0)
	{
		index = FLOAT_MIDDLE - 1;
		while ((pr[index] != 0) && (index <= FLOAT_TOTAL_LEN))
		{
			index--;
			len++;
		}
		index = FLOAT_MIDDLE + 1;
		while ((pr[index] != 0) && (index <= FLOAT_TOTAL_LEN))
		{
			index++;
			len++;
		}
		if (len != 1)
			len += 1;
	}
	else
	{
		index = 0;
		while ((pr[index] == 0) && (index <= FLOAT_TOTAL_LEN))
		{
			index++;
		}
		while ((pr[index] != 0) && (index <= FLOAT_TOTAL_LEN))
		{
			index++;
			len++;
		}
	}
	// printf("\n LEN PROD = %d", len);
	return (len);
}

int				length_product_decpart(short *pr)
{
	size_t		index;
	int			len;

	index = FLOAT_MIDDLE + 1;
	len = 0;
	while (pr[index] != 0)
	{
		index++;
		len++;
	}
	return (len);
}

int				length_product_intpart(short *pr)
{
	size_t		index;
	int			len;

	len = 0;
	if (pr[0] == 0)
	{
		index = FLOAT_MIDDLE - 1;
		while ((pr[index] != 0) && (index <= FLOAT_TOTAL_LEN))
		{
			index--;
			len++;
		}
		// index = FLOAT_MIDDLE + 1;
		// while ((pr[index] != 0) && (index <= FLOAT_TOTAL_LEN))
		// {
		// 	index++;
		// 	len++;
		// }
		// if (len != 1)
			// len += 1;
	}
	else
	{
		index = 0;
		while ((pr[index] == 0) && (index <= FLOAT_TOTAL_LEN))
		{
			index++;
		}
		while ((pr[index] != 0) && (index <= FLOAT_TOTAL_LEN) && pr[index] != '.')
		{
			index++;
			len++;
		}
	}
	// printf("\n len int = %d", len);
	return (len);
}
