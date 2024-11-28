/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:25:57 by samatsum          #+#    #+#             */
/*   Updated: 2023/05/19 00:00:04 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ans;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		ans = ft_strdup("\0");
		return (ans);
	}
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	ans = (char *)malloc(sizeof(char) * (len + 1));
	if (ans == NULL)
		return (NULL);
	i = 0;
	while (len != 0 && s[start] != '\0')
	{
		ans[i] = s[start];
		start++;
		len--;
		i++;
	}
	ans[i] = '\0';
	return (ans);
}

// #include<stdio.h>
// int main(void)
// {
// 	char *str = "01234";
// 	size_t size = 10;
// 	char *ret = ft_substr(str, 10, size);

// 	printf("%s\n", ret);
// 	free(ret);
// }