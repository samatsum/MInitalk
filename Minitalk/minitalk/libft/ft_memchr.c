/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 01:42:42 by samatsum          #+#    #+#             */
/*   Updated: 2023/05/17 02:09:36 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int ch, size_t n)
{
	const unsigned char	*buf_byte;

	buf_byte = (const unsigned char *)buf;
	while (n-- > 0)
	{
		if (*buf_byte == (unsigned char)ch)
			return ((void *)buf_byte);
		buf_byte++;
	}
	return (NULL);
}
//void * 型のポインタ変数に対しては添字演算子（[]）や間接演算子（*）が使用できません。
// [** 説明]
//  ポインター `s` が指し示すメモリー領域の先頭の `n` バイトから最初に登場する文字 `c` を探す。
//`c` と `s` が指し示すメモリー領域の各バイトは両方とも `unsigned char` と解釈される。

// [** 返り値]
//  一致する文字へのポインターを返し、 もし文字が指定メモリー領域に現れない場合は `NULL` を返す。
//  [Reference https://linuxjm.osdn.jp/html/LDP_man-pages/man3/memchr.3.html]
