/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:18:52 by samatsum          #+#    #+#             */
/*   Updated: 2023/05/17 16:50:01 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	int		str_len;
	char	*string_cpy;
	int		i;

	i = 0;
	str_len = ft_strlen(string);
	string_cpy = (char *)malloc(sizeof(char) * str_len + 1);
	if (string_cpy == NULL)
		return (NULL);
	while (string[i] != '\0')
	{
		string_cpy[i] = string[i];
		i++;
	}
	string_cpy[i] = '\0';
	return (string_cpy);
}

// [** 説明]
//  strdup() 関数は、文字列 sの複製である 新しい文字列へのポインターを返す。
// 新しい文字列のためのメモリーは malloc(3) で得ている。 そして、 free(3) で解放することができる。
//  最後の NULL 文字分も malloc で確保する．

// [** 返り値]
// 　成功すると、 strdup() 関数は複製された文字列へのポインターを返す。
// 十分なメモリーが確保できなかった場合には、 NULL を返し、 errno にエラーの原因を示す値を設定する。
// 　[Reference https://linuxjm.osdn.jp/html/LDP_man-pages/man3/strdup.3.html]
