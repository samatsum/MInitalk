/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 11:36:15 by samatsum          #+#    #+#             */
/*   Updated: 2023/05/20 12:07:10 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_num_digits(long n)
{
	size_t	num_digits;

	num_digits = 1;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		n /= 10;
		num_digits++;
	}
	return (num_digits);
}

static void	convert_number(char *ans, size_t num_digits, long tmp, int flag)
{
	ans[num_digits] = '\0';
	while (num_digits > 0)
	{
		num_digits--;
		if (flag == 1 && num_digits == 0)
			break ;
		ans[num_digits] = (tmp % 10) + '0';
		tmp /= 10;
	}
}

char	*ft_itoa(int n)
{
	size_t	num_digits;
	char	*ans;
	long	tmp;
	int		flag;

	num_digits = get_num_digits((long)n);
	tmp = (long)n;
	flag = 0;
	if (tmp < 0)
	{
		tmp = -tmp;
		num_digits++;
		flag = 1;
	}
	ans = (char *)malloc(sizeof(char) * (num_digits + 1));
	if (!ans)
		return (NULL);
	if (flag == 1)
		ans[0] = '-';
	convert_number(ans, num_digits, tmp, flag);
	return (ans);
}

// int main(void)
// {
// 	char *ans;
// 	ans = ft_itoa(-5859);
// 	printf("%s\n",ans);
// 	return (0);
// }
// #include "libft.h"

// static size_t	get_num_digits(int n)
// {
// 	size_t	num_digits;

// 	num_digits = 1;
// 	if (n < 0)
// 		n = -n;
// 	while (n >= 10)
// 	{
// 		n /= 10;
// 		num_digits++;
// 	}
// 	return (num_digits);
// }

// static void	convert_number(char *ans, size_t num_digits, long tmp, int flag)
// {
// 	ans[num_digits] = '\0';
// 	if (tmp < 0)
// 	{
// 		flag = 1;
// 		tmp = -tmp;
// 	}
// 	while (num_digits > 0)
// 	{
// 		num_digits--;
// 		ans[num_digits] = (tmp % 10) + '0';
// 		tmp /= 10;
// 	}
// 	if (flag == 1)
// 		ans[0] = '-';
// }

// char	*ft_itoa(int n)
// {
// 	size_t	num_digits;
// 	char	*ans;
// 	long	tmp;
// 	int		flag;

// 	num_digits = get_num_digits(n);
// 	ans = (char *)malloc(sizeof(char) * (num_digits + 1));
// 	if (!ans)
// 		return (NULL);
// 	tmp = n;
// 	flag = 0;
// 	convert_number(ans, num_digits, tmp, flag);
// 	return (ans);
// }

// #include "libft.h"

// char	*ft_itoa(int n)
// {
// 	long	num_of_digits;
// 	char	*ans;
// 	long	tmp;
// 	long	flag;

// 	flag = 0;
// 	tmp = n;
// 	if (n < 0)
// 	{
// 		tmp = -tmp;
// 		flag = 1;
// 	}
// 	num_of_digits = 1;
// 	if (flag == 1)
// 		num_of_digits++;
// 	while (tmp >= 10)
// 	{
// 		tmp = tmp / 10;
// 		num_of_digits++;
// 	}
// 	ans = (char *)malloc(sizeof(char) * (num_of_digits + 1));
// 	if (ans == NULL)
// 		return (NULL);
// 	ans[num_of_digits] = '\0';
// 	tmp = n;
// 	if (n < 0)
// 		tmp = -tmp;
// 	while (num_of_digits > 0)
// 	{
// 		num_of_digits--;
// 		ans[num_of_digits] = (tmp % 10) + '0';
// 		tmp = tmp / 10;
// 	}
// 	if (flag == 1)
// 		ans[0] = '-';
// 	return (ans);
// }

// #include "libft.h"

// char	*ft_itoa(int n)
// {
// 	long		num_of_digits;
// 	char	*ans;
// 	long		tmp;
// 	long		flag;

// 	flag = 0;
// 	tmp = n;
// 	if (n < 0)
// 	{
// 		tmp = -n;
// 		flag = 1;
// 	}
// 	num_of_digits = 0;
// 	if (n == 0)
// 		return ("0");
// 	while (tmp > 0)
// 	{
// 		num_of_digits++;
// 		tmp = tmp / 10;
// 	}
// 	ans = (char *)malloc(sizeof(char) * (num_of_digits + 1));
// 	if (ans == NULL)
// 		return (NULL);
// 	if (flag == 1)
// 	{
// 		ans[0] = '-';
// 	}
// 	ans[num_of_digits] = '\0';
// 	while (num_of_digits > 0)
// 	{
// 		ans[num_of_digits - 1] = n % 10 + '0';
// 		n = n / 10;
// 		num_of_digits--;
// 	}
// 	return (ans);
// }
