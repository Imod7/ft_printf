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
	index = 0;
	while ((pr[index] == 0) && (index <= 10000))
	{
		index++;
		// printf("\n INDEX = %zu, pr = %c%c%c%c%c%c%c", index, pr[5000], pr[5001], pr[5002], pr[5003], pr[5004], pr[5005],pr[5006]);
		// printf("%c%c%c%c%c%c%c", pr[5007], pr[5008], pr[5009], pr[5010], pr[5011], pr[5012],pr[5013]);
		// printf("%c%c%c%c%c%c%c", pr[5014], pr[5015], pr[5016], pr[5017], pr[5018], pr[5019],pr[5020]);
	}
	while ((pr[index] != 0) && (index <= 10000))
	{
		index++;
		len++;
		// printf("\n >>> pr = %c%c%c%c%c%c%c", pr[5000], pr[5001], pr[5002], pr[5003], pr[5004], pr[5005],pr[5006]);
		// printf("%c%c%c%c%c%c%c", pr[5007], pr[5008], pr[5009], pr[5010], pr[5011], pr[5012],pr[5013]);
		// printf("%c%c%c%c%c%c%c", pr[5014], pr[5015], pr[5016], pr[5017], pr[5018], pr[5019],pr[5020]);
	}
	// printf("\n len = %d", len);
	return (len);
}

int				length_product_decpart(short *pr)
{
	size_t		index;
	int			len;

	index = 5002;
	len = 0;
	while (pr[index] != 0)
	{
		index++;
		len++;
	}
	return (len);
}
