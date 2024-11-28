/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:10:44 by samatsum          #+#    #+#             */
/*   Updated: 2023/05/23 20:49:37 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }	t_list;
t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
