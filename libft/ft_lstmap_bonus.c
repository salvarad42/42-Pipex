/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salvarad <salvarad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:34:16 by salvarad          #+#    #+#             */
/*   Updated: 2023/05/29 15:07:12 by salvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_nodo;
	t_list	*new_lst;

	new_lst = 0;
	while (lst)
	{
		new_nodo = ft_lstnew((*f)(lst -> content));
		if (!new_nodo)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_nodo);
		lst = lst -> next;
	}
	return (new_lst);
}
