/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:49:19 by samatsum          #+#    #+#             */
/*   Updated: 2023/05/17 16:18:21 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*addr;

	if (n == 0 || size == 0)
		return (malloc(1));
	if (n > SIZE_MAX / size || size > SIZE_MAX / n)
		return (NULL);
	addr = malloc(n * size);
	if (addr == NULL)
		return (NULL);
	ft_memset(addr, 0, n * size);
	return (addr);
}
//	if (n > SIZE_MAX / size || size > SIZE_MAX / n)でオーバーフローを検知だ！
// [** 説明]
//  ヒープメモリから size バイトのブロックを n個割り当てます。
//確保されたブロックは 0 クリアされます。この関数を使うことにより、
//プログラムで予め配列などを使ってメモリを確保せずに、
//必要な場所で必要なだけメモリを確保することが出来ます。
//calloc関数で確保したメモリは、使用後、必ず free関数で解放してください。
// [** 返り値]
// 　成功時：　確保したメモリブロックを指すポインタ
// 　失敗時：　NULL　（メモリ不足により指定サイズ分のメモリが確保できないとき）
//  [Reference http://www9.plala.or.jp/sgwr-t/lib/calloc.html]
