/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 09:44:02 by samatsum          #+#    #+#             */
/*   Updated: 2023/05/18 06:32:11 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	i = 0;
	src_len = ft_strlen(src);
	if (size > 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

// [** 説明]
//  ポインタ`src`の指すアドレスから最大で`size - 1`バイトの文字列を`dst`にコピーし、
//`dst`の指す文字列が必ず`NULL`文字で終わるようにする。これによって、`dst`が`char`配列の場合に
//`sizeof(dst)`を`size`として指定すればバッファオーバーランしないことが保証される。
//  `strncpy`は似たプロトタイプを持つが、最大で`size`バイトをコピーするので
//`NULL`文字で終わるとは限らない点や、文字列が短い場合に`dst`の残った部分をすべてゼロで埋める点が
//`strlcpy`と異なる。
//  [Reference[https://ja.wikipedia.org/wiki/Strlcpy]
// [** 返り値]
//  `src` の長さ．