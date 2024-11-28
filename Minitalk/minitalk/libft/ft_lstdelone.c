/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:46:14 by samatsum          #+#    #+#             */
/*   Updated: 2023/05/23 20:49:50 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }	t_list;
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}
