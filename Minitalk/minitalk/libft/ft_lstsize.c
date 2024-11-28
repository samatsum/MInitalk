/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:47:51 by samatsum          #+#    #+#             */
/*   Updated: 2023/05/23 20:41:52 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }	t_list;
int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	if (lst == NULL)
		return (0);
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
