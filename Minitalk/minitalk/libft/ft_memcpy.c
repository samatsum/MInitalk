/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 01:19:38 by samatsum          #+#    #+#             */
/*   Updated: 2023/05/17 01:47:40 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *buf1, const void *buf2, size_t n)
{
	size_t		i;
	char		*buf1_byte;
	const char	*buf2_byte;

	if (buf1 == NULL && buf2 == NULL)
		return (NULL);
	i = 0;
	buf1_byte = (char *)buf1;
	buf2_byte = (const char *)buf2;
	while (n > i)
	{
		buf1_byte[i] = buf2_byte[i];
		i++;
	}
	return (buf1);
}
//void * 型のポインタ変数に対しては添字演算子（[]）や間接演算子（*）が使用できません。
// [** 説明]
// 　memcpy() は、メモリー領域 src からメモリー領域 dest に 最大で n バイトのコピーを行う。
// n バイトコピーする前に文字 c が見つかると、 そこでコピーを中止する。
//コピー元とコピー先のメモリー領域が重なっている場合、 結果は不定である。 

// [** 返り値]
// 　dest 中に見つかった c の 次にあるキャラクター型の変数を指すポインターを返す。 見つからなかった場合、NULL を返す。