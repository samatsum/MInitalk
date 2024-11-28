/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 02:09:17 by samatsum          #+#    #+#             */
/*   Updated: 2023/05/27 11:31:51 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *buf1, const void *buf2, size_t n)
{
	size_t		i;
	char		*buf1_byte;
	const char	*buf2_byte;

	buf1_byte = (char *)buf1;
	buf2_byte = (const char *)buf2;
	if (buf1_byte == buf2_byte)
		return (buf1);
	if (buf1_byte > buf2_byte)
	{
		n = n + 1;
		while (--n > 0)
			buf1_byte[n - 1] = buf2_byte[n - 1];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			buf1_byte[i] = buf2_byte[i];
			i++;
		}
	}
	return (buf1);
}

// [** 説明]
//  `dst` の先頭から `len` 文字分 `src` をコピーします。
//このとき、`strcpy()`と異なり空文字(`'\0'`)を付加することはありません。
//また、`src` を単なるメモリブロックとして扱うため、途中に空文字(`'\0'`)を含んでいてもコピーを続けます。
//`dst` と `src` が重なっているときの動作は `memcpy()` では未定義ですが、
//この`memmove()` では正しくコピー（つまり移動）が行われます。

// [** 返り値]
//  dst の値．

// [** Source Code]
//  [gcc https://github.com/gcc-mirror/gcc/blob/master/libgcc/memmove.c]

// [** Tips]
//  `dst` が `src` の後ろにある場合は，`src` の後ろから `dst` の後ろに `len` 回コピーを行えば良い．
