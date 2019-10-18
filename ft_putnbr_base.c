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

#include "includes/ft_printf.h"

void					ft_putnbr_int(long long n, int fd)
{
	int					num;

	if (n < -9223372036854775807)
	{
		write(fd, &"9", 1);
		ft_putnbr_int(223372036854775808, fd);
	}
	if (n == -2147483648)
	{
		write(fd, &"2", 1);
		ft_putnbr_int(147483648, fd);
	}
	else if (n < 0)
		n = n * (-1);
	if (n >= 0 && n <= 9)
	{
		num = n + 48;
		write(fd, &num, 1);
	}
	if (n > 9)
	{
		ft_putnbr_int(n / 10, fd);
		ft_putnbr_int(n % 10, fd);
	}
}

void					ft_putnbr_un_int(unsigned long long n, int fd)
{
	int					num;

	if (n <= 9)
	{
		num = n + 48;
		write(fd, &num, 1);
	}
	if (n > 9)
	{
		ft_putnbr_un_int(n / 10, fd);
		ft_putnbr_un_int(n % 10, fd);
	}
}

void					ft_putnbr_octal(unsigned long long n, int fd)
{
	unsigned long long	num;

	if (n < 8)
	{
		num = n + 48;
		write(fd, &num, 1);
	}
	if (n >= 8)
	{
		ft_putnbr_octal(n / 8, fd);
		ft_putnbr_octal(n % 8, fd);
	}
}

void					ft_putnbr_hex(unsigned long long n, int fd)
{
	unsigned long long	num;

	// printf("number = %llu\n", n);
	if (n <= 9)
	{
		num = n + 48;
		write(fd, &num, 1);
		// printf("num = %llu\n", num);
	}
	if (n > 9 && n < 16)
	{
		num = n + 87;
		write(fd, &num, 1);
		// printf("num = %llu\n", num);
	}
	if (n >= 16)
	{
		ft_putnbr_hex(n / 16, fd);
		ft_putnbr_hex(n % 16, fd);
	}
}

void					ft_putnbr_hex_capit(unsigned long long n, int fd)
{
	unsigned long long	num;

	if (n <= 9)
	{
		num = n + 48;
		write(fd, &num, 1);
	}
	if (n > 9 && n < 16)
	{
		num = n + 55;
		write(fd, &num, 1);
	}
	if (n >= 16)
	{
		ft_putnbr_hex_capit(n / 16, fd);
		ft_putnbr_hex_capit(n % 16, fd);
	}
}
