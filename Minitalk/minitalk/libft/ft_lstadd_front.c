/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:48:43 by samatsum          #+#    #+#             */
/*   Updated: 2023/05/22 20:37:30 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }	t_list;
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}
