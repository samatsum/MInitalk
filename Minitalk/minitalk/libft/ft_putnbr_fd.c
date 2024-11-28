/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:21:01 by samatsum          #+#    #+#             */
/*   Updated: 2023/05/20 15:49:33 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	write_digit(int n, int fd)
{
	char	c;

	c = n + '0';
	write(fd, &c, 1);
}

static void	write_number(int n, int fd)
{
	if (n >= 10)
		write_number(n / 10, fd);
	write_digit(n % 10, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == -2147483648)
		{
			write(fd, "2147483648", 10);
			return ;
		}
		n = -n;
	}
	else if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	write_number(n, fd);
}
// #include"libft.h"

// void	ft_putnbr_fd(int n, int fd)
// {
// 	char	num_str[12];
// 	int		i;
// 	int		sign;

// 	sign = 1;
// 	i = 0;
// 	if (n == 0)
// 	{
// 		write(fd, "0", 1);
// 		return ;
// 	}
// 	if (n == -2147483648)
// 	{
// 		write(fd, "-2147483648", 11);
// 		return ;
// 	}
// 	if (n < 0)
// 	{
// 		sign = -1;
// 		n = -n;
// 	}
// 	while (n != 0)
// 	{
// 		num_str[i++] = (n % 10) + '0';
// 		n /= 10;
// 	}
// 	if (sign == -1)
// 		num_str[i++] = '-';
// 	while (i > 0)
// 		write(fd, &num_str[--i], 1);
// }

// #include "libft.h"

// void	ft_itoa_modoki(int n, int num_of_digits, int fd)
// {
// 	char	ans;

// 	while (num_of_digits > 0)
// 	{
// 		ans = n % 10 + '0';
// 		write(fd, &ans, 1);
// 		n = n / 10;
// 		num_of_digits--;
// 	}
// }

// void	ft_putnbr_fd(int n, int fd)
// {
// 	int		num_of_digits;
// 	int		tmp;

// 	if (n == -2147483648)
// 	{
// 		write(fd, "-2147483648", 11);
// 		return;
// 	}
// 	if (n < 0)
// 	{
// 		write(fd, "-", 1);
// 		n = -n;
// 	}
// 	tmp = n;
// 	num_of_digits = 0;
// 	while (tmp > 0)
// 	{
// 		num_of_digits++;
// 		tmp = tmp / 10;
// 	}
// 	ft_itoa_modoki(n, num_of_digits, fd);
// }
