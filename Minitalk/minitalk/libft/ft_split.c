/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:32:49 by samatsum          #+#    #+#             */
/*   Updated: 2023/05/20 11:32:58 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int		count;
	int		is_word;
	size_t	i;

	i = 0;
	count = 0;
	is_word = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == c)
			is_word = 0;
		else
		{
			if (is_word == 0)
			{
				count++;
				is_word = 1;
			}
		}
		i++;
	}
	return (count);
}

static int	count_len(const char *s, char c, int start)
{
	int	len;

	len = 0;
	while (s[start] != '\0' && s[start] != c)
	{
		len++;
		start++;
	}
	return (len);
}

static char	*extract_word(const char *s, int start, int len)
{
	int		i;
	char	*word;

	word = (char *)malloc(sizeof(char) * (len + 1));
	if (word == NULL)
	{
		free(word);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	in_ft_split(const char *s, char c, char **ans, int *i)
{
	int		j;
	int		count;

	count = 0;
	j = -1;
	while (s[count] != '\0')
	{
		if (s[count] != c)
		{
			ans[*i] = extract_word(s, count, count_len(s, c, count));
			if (ans[*i] == NULL)
			{
				while (++j < *i)
					free(ans[j]);
				free(ans);
				return (1);
			}
			(*i)++;
			count += count_len(s, c, count);
		}
		else
			count++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		c_num;
	char	**ans;
	int		i;

	if (s == NULL)
		return (NULL);
	c_num = count_words(s, c);
	ans = (char **)malloc(sizeof(char *) * (c_num + 1));
	if (ans == NULL)
		return (NULL);
	i = 0;
	if (in_ft_split(s, c, ans, &i))
		return (NULL);
	ans[i] = NULL;
	return (ans);
}
// #include<stdio.h>
// int main(void)
// {
// 	char **ans;
// 	ans = ft_split("hello world 42 tokyo", ' ');
// 	printf("ans[0] = %s\n", ans[0]);
// 	printf("ans[1] = %s\n", ans[1]);
// 	printf("ans[2] = %s\n", ans[2]);
// 	printf("ans[3] = %s\n", ans[3]);
// 	free(ans);
// 	return (0);
// }
// char	**ft_split(char const *s, char c)
// {
// 	int		c_num;
// 	char	**ans;
// 	int		i;
// 	int		j;
// 	int		count;
// 	int		start;
// 	int		word_len;
// 	int		f;

// 	c_num = count_c(s, c);
// 	ans = (char **)malloc(sizeof(char *) * (c_num + 1));
// 	if (ans == NULL)
// 		return (NULL);
// 	i = 0;
// 	j = -1;
// 	count = 0;
// 	start = 0;
// 	f = -1;
// 	while (s[count] != '\0')
// 	{
// 		if (s[count] != c)
// 		{
// 			start = count;
// 			word_len = count_word(s, c, start);
// 			ans[i] = (char *)malloc(sizeof(char) * (word_len + 1));
// 			if (ans[i] == NULL)
// 			{
// 				while (++f < i)
// 					free(ans[f]);
// 				free(ans);
// 				return (NULL);
// 			}
// 			j = -1;
// 			while (++j < word_len)
// 				ans[i][j] = s[start + j];
// 			ans[i][j] = '\0';
// 			i++;
// 			count += word_len;
// 		}
// 		else
// 			count++;
// 	}
// 	ans[i] = NULL;
// 	return (ans);
// }
