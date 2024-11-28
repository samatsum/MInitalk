/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 08:47:31 by samatsum          #+#    #+#             */
/*   Updated: 2023/05/19 11:25:51 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	int		i;
	int		j;
	int		start;
	int		end;
	char	*trimmed;

	i = 0;
	start = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	trimmed = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!trimmed)
		return (NULL);
	j = 0;
	while (start <= end)
		trimmed[j++] = s1[start++];
	trimmed[j] = '\0';
	return (trimmed);
}

// #include"libft.h"

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i] != 0)
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	int		i;
// 	int		j;
// 	int		k;
// 	int		flag;
// 	int		repeet_flag;
// 	char	*ans;
// 	int		index;

// 	i = 0;
// 	j = 0;
// 	k = 0;
// 	flag = 0;
// 	repeet_flag = 1;
// 	if (s1[0] == '\0')
// 		return ("\0");
// 	if (set[0] == '\0')
// 		return ((char *)s1);
// 	ans = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
// 	if (ans == NULL)
// 		return (NULL);
// 	while (s1[i] != '\0' && repeet_flag == 1)
// 	{
// 		j = 0;
// 		flag = 0;
// 		repeet_flag = 0;
// 		while (set[j] != '\0')
// 		{
// 			if (s1[i] == set[j])
// 				flag = 1;
// 			if (s1[i + 1] == set[j])
// 				repeet_flag = 1;
// 			j++;
// 		}
// 		if (flag == 0)
// 			break ;
// 		i++;
// 	}
// 	index = ft_strlen(s1) - 1;
// 	repeet_flag = 1;
// 	while (index >= 0 && repeet_flag == 1)
// 	{
// 		j = 0;
// 		flag = 0;
// 		repeet_flag = 0;
// 		while (set[j] != '\0')
// 		{
// 			if (s1[index] == set[j])
// 				flag = 1;
// 			if (s1[index - 1] == set[j])
// 				repeet_flag = 1;
// 			j++;
// 		}
// 		if (flag == 0)
// 			break ;
// 		index--;
// 	}
// 	while (i <= index)
// 		ans[k++] = s1[i++];
// 	ans[k] = '\0';
// 	return (ans);
// }

// [** 説明]
// 　`s1` の前からと後ろから見ていき，`set` の中にある文字を `s1` の先頭と末尾から削除する．

// [** 返り値]
// 　切り抜いた後の文字列の先頭アドレス．