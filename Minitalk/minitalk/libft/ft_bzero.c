/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 01:13:55 by samatsum          #+#    #+#             */
/*   Updated: 2023/05/17 01:19:02 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t size)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (size-- > 0)
		*p++ = 0;
}

// explicit_bzeroとω矛盾
// http://lpha-z.hatenablog.com/entry/2019/10/06/231500
// →bzeroの使われ方が書いてある。
// →explicit_bzeroという存在の話も面白い。

// http://manpages.ubuntu.com/manpages/bionic/ja/man3/bzero.3.html

// [** Tips]
//  Q. ポインタが渡された場合、どういう処理？NULL文字が埋められる？NULLポインタ？
//  A. NULL文字が埋められて、NULLポインタと同値になる