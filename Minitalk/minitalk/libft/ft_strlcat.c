/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:47:18 by samatsum          #+#    #+#             */
/*   Updated: 2023/05/17 14:23:51 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dtsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	cpy_size;
	size_t	i;

	if (dst == NULL && dtsize == 0)
		return (0 + ft_strlen(src));
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dtsize <= dst_len)
		return (dtsize + src_len);
	cpy_size = dtsize - dst_len - 1;
	i = 0;
	while (i < cpy_size && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
// strlcatはdestとsrcを結合させる
// destの後ろにsrcを（dstsize-dest文字数-1)文字ペーストしてくれる
// 返り値は、dest文字数がdstsize以上の時は（dstsize＋src文字数）
// dstsizeよりdestの文字数が小さい時は時は（dest文字数＋src文字数）
//restrict修飾子が適用されたポインタは、そのポインタが指すオブジェクトへのアクセスが他のポインタや参照によって行われないことを示します。
//つまり、そのポインタを介してアクセスされるオブジェクトは、他のポインタや参照によって変更されることがないという制約があります。
// [** 説明]
//  　ポインタ`src`の指すアドレスから最大で`dstsize - strlen(dst) - 1`バイト文字列を`dst`の末尾に追記し、
//`NULL`文字で終わるようにする。		
// 　`strlcat`の第3引数`dstsize` には連結先文字列`dst` の書き込み可能サイズが指定される。
// 　従って、仮に`dst` の長さが`dstsize` 以上であった場合、連結する余白がない、あるいは終端の`NULL`文字がサイズ内にないことを示す。

// [** 戻り値]
//  戻り値（理想の連結後の文字列の長さ）には、`指定された書き込み可能サイズ`と`連結元文字列src の長さ`の和を返す。

// [* 戻り値が dst の文字数 + src の文字数である理由]
//  　strlcatが「dstの文字数+srcの文字数」を返すのは、連結後に必要なバッファサイズを知らせるためだと思います。
//戻り値がdstのバッファサイズより小さければ連結が成功したとわかり、大きければバッファサイズが足りなかったとわかります。
//（その時は戻り値より大きなバッファを用意して再実行すれば良い。）
//  　ここで問題なのがdstの文字数がちょうどバッファサイズと同じ場合
// 　　　`char dst[5] = "12345"; // dstはnull終端されていない`
// 　 `strlen(dst)`はおそらく5より大きくなる。
// 　 そこでstrlcatは`strlen(dst) >= size` の場合は上記のような間違いだと仮定して、
//必要なバッファサイズとして「srcの文字数+size」を返すのだと思います。