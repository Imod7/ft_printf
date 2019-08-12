/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/13 00:20:08 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/08/13 00:58:43 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_octal(int n)
{
	if (n == -2147483648)
	{
		ft_putchar(45);
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		ft_putchar(45);
		n = n * (-1);
	}
	if (n >= 0 && n <= 8)
		ft_putchar(n + 48);
	if (n > 8)
	{
		ft_putnbr_octal(n / 8);
		ft_putnbr_octal(n % 8);
	}
}

int     number_of_digits_octal(int n)
{
	int digits;

	digits = 0;
	if (n == -2147483648)
	{
		ft_putchar(45);
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		// ft_putchar(45);
		n = n * (-1);
	}
	if (n >= 0 && n <= 8)
		digits++;
	if (n > 8)
	{
		ft_putnbr_octal(n / 8);
		ft_putnbr_octal(n % 8);
	}
	return (digits);
}