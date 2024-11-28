/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:14:57 by samatsum          #+#    #+#             */
/*   Updated: 2023/05/17 13:14:01 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	if (big == NULL && len == 0)
		return (NULL);
	little_len = ft_strlen(little);
	if (*little == 0)
		return ((char *)big);
	if (*big == 0)
		return (NULL);
	while (little_len <= len)
	{
		if (*big == *little && ft_strncmp(big, little, little_len) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
// #include <string.h>
// #include<stdio.h>
// int main(void)
// {
// 	char *ans1 = ft_strnstr("abbbcdefg", "bbc", 0);
// 	printf("%s\n",ans1);
// 	char *ans = strnstr("abbbcdefg", "bbc", 0);
// 	printf("%s\n",ans);
// 	return (0);
// }
// strnstr() 関数は、検索された len 文字より少ない文字列 big の中で、
// ヌル文 字で終了する文字列little が最初に出現する位置を探します。
//  ‘\0’ の後に現れる文字は、検索されません。