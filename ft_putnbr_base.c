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

void	ft_putnbr_int(long long n, int fd)
{
	int num;

	if (n == -2147483648)
	{
		// ft_putchar(45);
		// ft_putchar('2');
		num = 50;
		write(fd, &num, 1);
		ft_putnbr_int(147483648, fd);
	}
	else if (n < 0)
	{
		// ft_putchar(45);
		n = n * (-1);
	}
	if (n >= 0 && n <= 9)
	{
		// ft_putchar(n + 48);
		num = n + 48;
		write(fd, &num, 1);
	}
	if (n > 9)
	{
		ft_putnbr_int(n / 10, fd);
		ft_putnbr_int(n % 10, fd);
	}
}

void					ft_putnbr_octal(unsigned long long n, int fd)
{
	unsigned long long	num;

	if (n <= 8)
	{
		num = n + 48;
		write(fd, &num, 1);
	}
	if (n > 8)
	{
		ft_putnbr_octal(n / 8, fd);
		ft_putnbr_octal(n % 8, fd);
	}
}

void	ft_putnbr_hex(unsigned long long n, int fd)
{
	unsigned long long	num;

	if (n <= 9)
	{
		num = n + 48;
		write(fd, &num, 1);
	}
	if (n > 9 && n <= 16)
	{
		num = n + 87;
		write(fd, &num, 1);
	}
	if (n > 16)
	{
		ft_putnbr_hex(n / 16, fd);
		ft_putnbr_hex(n % 16, fd);
	}
}

void	ft_putnbr_hex_capit(unsigned long long n, int fd)
{
	unsigned long long	num;

	if (n <= 9)
	{
		num = n + 48;
		write(fd, &num, 1);
	}
	if (n > 9 && n <= 16)
	{
		num = n + 55;
		write(fd, &num, 1);
	}
	if (n > 16)
	{
		ft_putnbr_hex_capit(n / 16, fd);
		ft_putnbr_hex_capit(n % 16, fd);
	}
}
