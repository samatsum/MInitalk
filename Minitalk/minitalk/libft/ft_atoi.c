/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:22:50 by samatsum          #+#    #+#             */
/*   Updated: 2023/06/03 21:15:45 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n')
		return (1);
	if (c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

static int	check_overflow(int m, unsigned long long a, const char *str, int i)
{
	if (m == 1 && a >= 9223372036854775807ULL)
		return (-1);
	if (m == -1 && a >= 9223372036854775808ULL)
		return (0);
	if (m == 1 && a >= 1844674407370955161 && str[i + 1] >= '6')
		return (-1);
	if (m == -1 && a >= 1844674407370955161 && str[i + 1] >= '7')
		return (0);
	return (2);
}

int	ft_atoi(const char *str)
{
	int						i;
	unsigned long long		ans;
	int						minus_flag;
	int						result;

	i = 0;
	minus_flag = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus_flag = -1;
		i++;
	}
	ans = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ans = ans * 10 + (str[i] - '0');
		result = check_overflow(minus_flag, ans, str, i);
		if (result != 2)
			return (result);
		i++;
	}
	return ((int)ans * minus_flag);
}

// #include <stdlib.h>
// #include<stdio.h>
// void execute(const char *str)
// {
// 	printf("%s: \n", str);
// 	int ret = ft_atoi(str);
// 	printf("mine＝%d@\n", ret);
// 	printf("atoi＝%d@\n", atoi(str));
// }
// int	main(void)
// {
// 	execute("9223372036854775806");
// 	execute("9223372036854775807");
// 	execute("9223372036854775808");

// 	execute("18446744073709551616");
// 	execute("18446744073709551615");
// 	execute("18446744073709551614");

// 	execute("-18446744073709551617");
// 	execute("-18446744073709551616");
// 	execute("-18446744073709551615");
// 	return (0);
// }

// 説明]
//  atoi() 関数は、nptr によって指示される文字列のはじめの部分を int 型整数に変換する。 
//この振る舞いは、 atoi() 関数がエラーを見つけない点以外は、`(long)strtol(nptr, NULL, 10);` と同じである。
//   これは `man`によって定義されている。
//  なお man によると `strtol`は overflow、underflowした場合にそれぞれ `LONG_MAX` `LONG_MIN` 
//を返すことが定義されている（`man strtol`の RETURN VALUES を参照）。
// [** 返り値]
// 　変換された値

// [** Tips]
//  Long の最小値，最大値
// code:LONG_MIN_MAX
