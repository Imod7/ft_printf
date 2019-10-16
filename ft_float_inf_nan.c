/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_float_inf_nan.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 19:37:06 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/10/11 19:37:08 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			check_exp_allones(t_float *fl)
{
	int		bit;
	int		pos;

	pos = 14;
	while (pos >= 0)
	{
		bit = (*fl).exponent[4] >> pos;
		if (bit & 1)
			pos--;
		else
			return (-1);
	}
	return (0);
}

int			check_mant_allzeros(t_float *fl)
{
	int		bit;
	int		pos;

	pos = 62;
	while (pos >= 0)
	{
		bit = (*fl).mantissa >> pos;
		if (bit & 1)
			return (-1);
		else
			pos--;
	}
	return (0);
}

int			check_inf_nan(t_float *fl, t_print *t_prnt, short *product)
{
	if ((check_exp_allones(fl) == 0) && (check_mant_allzeros(fl) == 0))
	{
		(*t_prnt).diff = -1;
		if (((*fl).exponent[4] >> 15) & 1)
		{
			product[0] = '-';
			product[1] = 'i';
			product[2] = 'n';
			product[3] = 'f';
			return (-1);
		}
		else
		{
			product[0] = 'i';
			product[1] = 'n';
			product[2] = 'f';
			return (1);
		}
	}
	else if ((check_exp_allones(fl) == 0) && (check_mant_allzeros(fl) != 0))
	{
		(*t_prnt).diff = -1;
		product[0] = 'n';
		product[1] = 'a';
		product[2] = 'n';
		return (2);
	}
	return (0);
}
