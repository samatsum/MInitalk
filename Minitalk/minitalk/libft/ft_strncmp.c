/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:42:50 by samatsum          #+#    #+#             */
/*   Updated: 2023/05/17 09:24:13 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if ((s1 == NULL || s2 == NULL) && n == 0)
		return (0);
	while (*s1 == *s2 && *s1 != '\0' && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

// #include<stdio.h>
// #include<string.h>
// int main(void)
// {
// 	printf("or : %d\n", strncmp(NULL, NULL, 0));
// 	printf("1 : %d\n", ft_strncmp(NULL, NULL, 0));

// 	printf("or : %d\n", strncmp("hello", NULL, 0));
// 	printf("2 : %d\n", ft_strncmp("hello", NULL, 0));
// 	printf("or : %d\n", strncmp(NULL, "hello", 0));
// 	printf("3 : %d\n", ft_strncmp(NULL, "hello", 0));
// 	//printf("4 : %d\n", ft_strncmp("hello", NULL, 3));
// 	printf("or : %d\n", ft_strncmp(NULL, NULL, 3));
// }
// //返り値をキャストする理由は、比較する文字の値の範囲を拡張するため!!。
// // strncmpは文字列の比較に特化しており、文字列の終端に達するか、
// //指定されたバイト数(n)に到達するまで比較を行います。
// // memcmpはメモリ領域の比較に使用され、文字列に限定されず、任意のメモリ領域の比較が可能です。
// // strncmpは文字列の比較結果を返すため、比較において文字の大小や順序を考慮します。
// //一方、memcmpは単純にメモリ領域をバイト単位で比較し、等しいかどうかの結果を返します。
// // [** 説明]
// // 　文字列`*s1` と文字列`*s2` を先頭から`n`文字比較します。`'\0'`以降の比較は行いません。

// // [** 返り値]
// // 　`s1 > s2` で正の値、`s1 < s2` で負の値、`s1 = s2`で` 0` を返す。
// //この大小関係は一般に文字コード順による。
// // 　[Reference http://www9.plala.or.jp/sgwr-t/lib/strncmp.html]